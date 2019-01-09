
// MFCSessionDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCSession.h"
#include "MFCSessionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//reference:  http://www.rohitab.com/discuss/topic/41626-rdp-com-server-client/
CMFCSessionDlg::CMFCSessionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSessionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	//{
	//	TRACE(_T("Fatal Error: MFC initialization failed \n"));
	//	return ;
	//}

	// Init the COM library - have Windows load up the DLLs.
	if (FAILED(CoInitialize(NULL)))
	{
		TRACE(_T("Fatal Error: OLE initialization failed \n"));
		return ;
	}
}

CMFCSessionDlg::~CMFCSessionDlg()
{
	CoUninitialize();
	if (m_pBtnCreateSession){
		delete m_pBtnCreateSession;
		m_pBtnCreateSession = NULL;
	}

	if (m_pEdConnectString){
		delete m_pEdConnectString;
		m_pEdConnectString = NULL;
	}
}

void CMFCSessionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCSessionDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ITEM_BTNCREATE, OnCreateSession)
END_MESSAGE_MAP()

// CMFCSessionDlg 訊息處理常式
void CMFCSessionDlg::Init()
{
	
	m_pBtnCreateSession = new CButton;
	m_pBtnCreateSession->Create(_T("CreateSession"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 120, 20), this, ITEM_BTNCREATE);
	m_pEdConnectString = new CEdit;
	m_pEdConnectString->Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(130, 0, 1700, 20), this, ITEM_EDSESSTION);
	::CoInitialize(NULL);
	//COleException oExcep;
	//CLSID clsID;

	//HRESULT hr = ::CLSIDFromString(L"{9B78F0E6-3E05-4A5B-B2E8-E743A8956B65}", &clsID);
	//if (FAILED(hr)) {
	//	return;
	//}	
	//m_pSession = new CRDPSRAPISharingSession();
	//if (!m_pSession->CreateDispatch(clsID, &oExcep))
	//	return;
}


BOOL CMFCSessionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定
	Init(); 
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

int ConnectEvent(IUnknown* Container, REFIID riid, IUnknown* Advisor, IConnectionPointContainer** picpc, IConnectionPoint** picp)
{
	HRESULT hr = 0;
	unsigned long tid = 0;
	IConnectionPointContainer* icpc = 0;
	IConnectionPoint* icp = 0;
	*picpc = 0;
	*picp = 0;

	Container->QueryInterface(IID_IConnectionPointContainer, (void **)&icpc);
	if (icpc)
	{
		*picpc = icpc;
		icpc->FindConnectionPoint(riid, &icp);
		if (icp)
		{
			*picp = icp;
			hr = icp->Advise(Advisor, &tid);
			//icp->Release();
		}
		//icpc->Release();
	}
	return tid;
}

void OnAttendeeConnected(IDispatch *pAttendee){
	IRDPSRAPIAttendee *pRDPAtendee;
	pAttendee->QueryInterface(__uuidof(IRDPSRAPIAttendee), (void**)&pRDPAtendee);
	if (pRDPAtendee)
		pRDPAtendee->put_ControlLevel(CTRL_LEVEL::CTRL_LEVEL_INTERACTIVE);
	//AddText(infoLog, "An attendee connected!\r\n");
}

void OnAttendeeDisconnected(IDispatch *pAttendee){
	IRDPSRAPIAttendeeDisconnectInfo *info;
	ATTENDEE_DISCONNECT_REASON reason;
	pAttendee->QueryInterface(__uuidof(IRDPSRAPIAttendeeDisconnectInfo), (void**)&info);
	if (info->get_Reason(&reason) == S_OK){
		char *textReason = NULL;
		switch (reason){
		case ATTENDEE_DISCONNECT_REASON_APP:
			textReason = "Viewer terminated session!";
			break;
		case ATTENDEE_DISCONNECT_REASON_ERR:
			textReason = "Internal Error!";
			break;
		case ATTENDEE_DISCONNECT_REASON_CLI:
			textReason = "Attendee requested termination!";
			break;
		default:
			textReason = "Unknown reason!";
		}
		//AddText(infoLog, dupcat("Attendee disconnected\r\n   Reason: ", textReason, "\r\n", 0));
	}
	pAttendee->Release();
	//picp = 0;
	//picpc = 0;
	//disconnect();
}

void OnControlLevelChangeRequest(IDispatch  *pAttendee, CTRL_LEVEL RequestedLevel){
	IRDPSRAPIAttendee *pRDPAtendee;
	pAttendee->QueryInterface(__uuidof(IRDPSRAPIAttendee), (void**)&pRDPAtendee);
	if (pRDPAtendee->put_ControlLevel(RequestedLevel) == S_OK){
		switch (RequestedLevel){
		case CTRL_LEVEL_NONE:
			//AddText(infoLog, "Level changed to CTRL_LEVEL_NONE!\r\n");
			break;
		case CTRL_LEVEL_VIEW:
			//AddText(infoLog, "Level changed to CTRL_LEVEL_VIEW!\r\n");
			break;
		case CTRL_LEVEL_INTERACTIVE:
			//AddText(infoLog, "Level changed to CTRL_LEVEL_INTERACTIVE!\r\n");
			break;
		}
	}
}
class EventSink : public _IRDPSessionEvents {
public:
	EventSink(){
	}

	~EventSink(){
	}

	// IUnknown
	virtual HRESULT STDMETHODCALLTYPE  QueryInterface(
		REFIID iid, void**ppvObject){
		*ppvObject = 0;
		if (iid == IID_IUnknown || iid == IID_IDispatch || iid == __uuidof(_IRDPSessionEvents))
			*ppvObject = this;
		if (*ppvObject)
		{
			((IUnknown*)(*ppvObject))->AddRef();
			return S_OK;
		}
		return E_NOINTERFACE;
	}

	virtual ULONG STDMETHODCALLTYPE  AddRef(void){
		return 0;
	}

	virtual ULONG STDMETHODCALLTYPE  Release(void){
		return 0;
	}


	// IDispatch
	virtual HRESULT STDMETHODCALLTYPE  GetTypeInfoCount(
		__RPC__out UINT *pctinfo){
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE  GetTypeInfo(
		UINT iTInfo,
		LCID lcid,
		__RPC__deref_out_opt ITypeInfo **ppTInfo){
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE  GetIDsOfNames(
		__RPC__in REFIID riid,
		__RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
		UINT cNames,
		LCID lcid,
		__RPC__out_ecount_full(cNames) DISPID *rgDispId){
		return E_NOTIMPL;
	}

	virtual HRESULT STDMETHODCALLTYPE  EventSink::Invoke(
		DISPID dispIdMember,
		REFIID riid,
		LCID lcid,
		WORD wFlags,
		DISPPARAMS FAR* pDispParams,
		VARIANT FAR* pVarResult,
		EXCEPINFO FAR* pExcepInfo,
		unsigned int FAR* puArgErr){


		switch (dispIdMember){
		case DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_CONNECTED:
			OnAttendeeConnected(pDispParams->rgvarg[0].pdispVal);
			break;
		case DISPID_RDPSRAPI_EVENT_ON_ATTENDEE_DISCONNECTED:
			OnAttendeeDisconnected(pDispParams->rgvarg[0].pdispVal);
			break;
		case DISPID_RDPSRAPI_EVENT_ON_CTRLLEVEL_CHANGE_REQUEST:
			OnControlLevelChangeRequest(pDispParams->rgvarg[1].pdispVal, (CTRL_LEVEL)pDispParams->rgvarg[0].intVal);
			break;
		}
		return S_OK;
	}
};

EventSink ev;

void CMFCSessionDlg::OnCreateSession()
{
	
	//m_pSession->Open();
	//CRDPSRAPIInvitationManager Mgr = m_pSession->get_Invitations();
	//CRDPSRAPIInvitation pInvation = Mgr.CreateInvitation(L"baseAuth", L"groupName", L"", 64);
	//CString strConnectionString = pInvation.get_ConnectionString();
	IConnectionPointContainer* picpc = NULL;
	IConnectionPoint* picp = NULL;
	HRESULT hr;
	hr = CoCreateInstance(__uuidof(RDPSession), NULL, CLSCTX_INPROC_SERVER, __uuidof(IRDPSRAPISharingSession), (void**)&m_pSession);
	if (FAILED(hr))
		return ;

	hr = m_pSession->Open();

	if (FAILED(hr))
		return ;

	IRDPSRAPIInvitationManager* pInvitationMgr;

	hr = m_pSession->get_Invitations(&pInvitationMgr);

	if (FAILED(hr))
		return ;

	CString strAuth = _T("baseAuth"), strGroup = _T("groupName"), strPwd = _T("");
	BSTR bsAuth = strAuth.AllocSysString(), bsGroup = strGroup.AllocSysString(), bsPwd = strPwd.AllocSysString();
	IRDPSRAPIInvitation * pInvatition;
	hr = pInvitationMgr->CreateInvitation(bsAuth, bsGroup, bsPwd, 64, &pInvatition);
	SysFreeString(bsAuth);
	SysFreeString(bsGroup);
	SysFreeString(bsPwd);
	if (FAILED(hr))
		return ;

	BSTR bsConnectionString;
	hr = pInvatition->get_ConnectionString(&bsConnectionString);

	if (FAILED(hr))
		return ;

	CString strConnectionString = bsConnectionString;
	SysFreeString(bsConnectionString);
	m_pEdConnectString->SetWindowText(strConnectionString);

	ConnectEvent((IUnknown*)m_pSession, __uuidof(_IRDPSessionEvents), (IUnknown*)&ev, &picpc, &picp);
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFCSessionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMFCSessionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

