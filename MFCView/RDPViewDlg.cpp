#include "stdafx.h"
#include "RDPViewDlg.h"

#define CONTROL_HEIGHT	25

IMPLEMENT_DYNCREATE(CRDPSRAPIViewer, CWnd)

CRDPViewDlg::CRDPViewDlg(CWnd* pParent /*=NULL*/, vector<pair<int, CString>>* pvConnString): CDialogEx()
{
	memset(m_xUi, 0, sizeof(m_xUi));
	m_pParentWnd = pParent;
	m_strCaption = _T("RDP Viewer");
	m_DialogTemplate.style = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | DS_SETFONT | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPCHILDREN /*ref: https://www.codeproject.com/Questions/729379/MFC-ActiveX-not-properly-redrawn*/;
	m_DialogTemplate.dwExtendedStyle = WS_EX_DLGMODALFRAME;
	m_DialogTemplate.x = 0;
	m_DialogTemplate.y = 0;
	m_DialogTemplate.cx = 0;
	m_DialogTemplate.cy = 0;
	m_DialogTemplate.cdit = 0;
	m_pvConnectionString = pvConnString;
	m_pFont = NULL;
}

CRDPViewDlg::~CRDPViewDlg()
{
	Finalize();
}

INT_PTR CRDPViewDlg::DoModal()
{
	CFont* pParentFont = m_pParentWnd->GetFont();

	if (pParentFont == NULL && AfxGetApp()->m_pActiveWnd != NULL) {
		pParentFont = AfxGetApp()->m_pActiveWnd->GetFont();
	}
	LOGFONT LogFont;
	memset(&LogFont, 0x00, sizeof(LogFont));
	if (pParentFont != NULL) {
		pParentFont->GetLogFont(&LogFont);
	}
	else {
		_tcscpy_s(LogFont.lfFaceName, LF_FACESIZE, _T("MS Sans Serif"));
		LogFont.lfHeight = 8;
	}

	//Prework for setting font in dialog...
	int cWC = _tcslen(LogFont.lfFaceName) + 1;

	int nFontNameLen = cWC + 1;
	WCHAR *szFontName = new WCHAR[nFontNameLen];
	// Copy the string
	_tcscpy_s(szFontName, nFontNameLen, LogFont.lfFaceName);

	szFontName[cWC] = 0;
	nFontNameLen = (cWC)* sizeof(WCHAR);

	//Prework for setting caption in dialog...
	cWC = _tcslen(m_strCaption) + 1;

	int szBoxLen = cWC + 1;
	WCHAR *szBoxCaption = new WCHAR[szBoxLen];
	// Copy the string
	_tcscpy_s(szBoxCaption, szBoxLen, m_strCaption);

	szBoxCaption[cWC] = 0;
	szBoxLen = (cWC)* sizeof(WCHAR);

	INT_PTR iRet = -1;
	//Here 's the stuff to build the dialog template in memory
	//without the controls being in the template
	//(Our first try, was this same template with some additional code
	//for each control placed on it, that's why this class is cold Ex :)
	//This gave some problems on WIN9x systems, where EDIT boxes
	//were not shown with 3D-look, but as flat controls)
	int nBufferSize = sizeof(DLGTEMPLATE) + (2 * sizeof(WORD)) /*menu and class*/ + szBoxLen /*size of caption*/
		+ sizeof(WORD) /*fontsize*/ + nFontNameLen /*size of fontname*/;

	HLOCAL hLocal = LocalAlloc(LHND, nBufferSize);
	if (hLocal != NULL) {
		BYTE*	pBuffer = (BYTE*)LocalLock(hLocal);
		if (pBuffer == NULL) {
			LocalFree(hLocal);
			AfxMessageBox(_T("CRDPViewDlg::DoModal() : LocalLock Failed"));
		}
		BYTE *pdest = pBuffer;

		// transfer DLGTEMPLATE structure to the buffer
		memcpy(pdest, &m_DialogTemplate, sizeof(DLGTEMPLATE));	// DLGTemplate
		pdest += sizeof(DLGTEMPLATE);
		*(WORD*)pdest = 0;									// no menu						 -- WORD to say it is 0 bytes
		pdest += sizeof(WORD);								// Increment
		*(WORD*)(pdest + 1) = 0;							// use default window class -- WORD to say it is 0 bytes
		pdest += sizeof(WORD);								// Increment
		memcpy(pdest, szBoxCaption, szBoxLen);			// Caption
		pdest += szBoxLen;
		*(WORD*)pdest = (unsigned short)LogFont.lfHeight;						// font size

		pdest += sizeof(WORD);
		memcpy(pdest, szFontName, nFontNameLen);		// font name
		pdest += nFontNameLen;


		//Next lines to make sure that MFC makes no ASSERTION when PREVIOUS/NEXT is pressed:)
		if (m_lpDialogTemplate != NULL) {
			m_lpDialogTemplate = NULL;
		}

		iRet = CreateIndirect((LPDLGTEMPLATE)pBuffer, m_pParentWnd);

		LocalUnlock(hLocal);
		LocalFree(hLocal);

		delete[] szBoxCaption;
		delete[] szFontName;
		return iRet;
	}
	else {
		AfxMessageBox(_T("CRDPViewDlg::DoModal() : LocalAllock Failed"));
		return -1;
	}
}

void CRDPViewDlg::Init()
{
	memset(m_xUi, 0, sizeof(m_xUi));
}

void CRDPViewDlg::Finalize()
{
	if (m_pFont){
		delete m_pFont;
		m_pFont = NULL;
	}
	DestroyUi();
}

void CRDPViewDlg::InitUiRectPos()
{
	POINT ptBase = { 0, 0 };
	POINT ptSize = { 0, 0 };
	CRect rcClient;
	GetClientRect(rcClient);
	for (int i = UI_POS_ITEM_BEGIN; i < UI_POS_ITEM_END; i++){
		UINT uImgId = 0;
		UINT uLanId = 0;
		switch (i){
			//BTN
		case UI_POS_BTN_CONNECT:
			ptBase = { 0, 0 };
			ptSize = { 50, CONTROL_HEIGHT };
			break;
			//CB
		case UI_POS_CB_SLAVES:
			ptBase = { 50, 0 };
			ptSize = { 100, CONTROL_HEIGHT };
			break;
			//edit
		case UI_POS_EDIT_CONNTIONSTRING: //for test
			ptBase = { 150, 0 };
			ptSize = { 1500, CONTROL_HEIGHT };
			break;
			//view
		case UI_POS_RDPVIEW_RDPVIEW:
			ptBase = { 0, CONTROL_HEIGHT };
			ptSize = { rcClient.Width(), rcClient.Height() - CONTROL_HEIGHT };
			break;
		}

		m_xUi[i].rcUi = { ptBase.x, ptBase.y, ptBase.x + ptSize.x, ptBase.y + ptSize.y };
	}
}

void CRDPViewDlg::InitUi()
{
	CString strCaption;
	//BTN
	for (int i = UI_POS_BTN_BEGIN; i < UI_POS_BTN_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CButton();
			strCaption = (i == UI_POS_BTN_CONNECT) ? L"�s�u" : L"";
			((CButton*)m_xUi[i].pCtrl)->Create(strCaption, WS_VISIBLE | WS_CHILD | WS_TABSTOP , m_xUi[i].rcUi, this, i);
			((CButton*)m_xUi[i].pCtrl)->SetFont(m_pFont);
		}
	}
	//CB
	for (int i = UI_POS_CB_BEGIN; i < UI_POS_CB_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CComboBox();
			((CComboBox*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_TABSTOP | WS_VISIBLE | CBS_DROPDOWNLIST, m_xUi[i].rcUi, this, i);
			((CComboBox*)m_xUi[i].pCtrl)->SetFont(m_pFont);
		}
		if (m_pvConnectionString && m_xUi[UI_POS_CB_SLAVES].pCtrl){
			for (int i = 0; i < m_pvConnectionString->size(); i++){
				CString str;
				str.Format(_T("Slave: %d"), m_pvConnectionString->at(i).first + 1);
				((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->AddString(str);
				((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->SetItemData(i, (DWORD)&m_pvConnectionString->at(i));
			}

		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN; i < UI_POS_EDIT_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CEdit();
			((CEdit*)m_xUi[i].pCtrl)->Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_LEFT | WS_BORDER, m_xUi[i].rcUi, this, i);
		}
	}
	//RDPVIEW
	for (int i = UI_POS_RDPVIEW_BEGIN; i < UI_POS_RDPVIEW_END; i++){
		if (!m_xUi[i].pCtrl){
			m_xUi[i].pCtrl = new CRDPSRAPIViewer();
			((CRDPSRAPIViewer*)m_xUi[i].pCtrl)->Create(L"", WS_CHILD | WS_VISIBLE, m_xUi[i].rcUi, this, i);
		}
	}

}

void CRDPViewDlg::DestroyUi()
{
	//BTN
	for (int i = UI_POS_BTN_BEGIN; i < UI_POS_BTN_END; i++){
		if (m_xUi[i].pCtrl){
			CButton* pBtn = ((CButton*)m_xUi[i].pCtrl);
			pBtn->DestroyWindow();
			delete pBtn;
			pBtn = NULL;
		}
	}
	//CB
	for (int i = UI_POS_CB_BEGIN; i < UI_POS_CB_END; i++){
		if (m_xUi[i].pCtrl){
			CComboBox* pCB = ((CComboBox*)m_xUi[i].pCtrl);
			pCB->DestroyWindow();
			delete pCB;
			pCB = NULL;
		}
	}
	//EDIT
	for (int i = UI_POS_EDIT_BEGIN ; i < UI_POS_EDIT_END; i++){
		if (m_xUi[i].pCtrl){
			CEdit* pEdit = ((CEdit*)m_xUi[i].pCtrl);
			pEdit->DestroyWindow();
			delete pEdit;
			pEdit = NULL;
		}
	}

	//RDPVIEW
	for (int i = UI_POS_RDPVIEW_BEGIN; i < UI_POS_RDPVIEW_END; i++){
		if (m_xUi[i].pCtrl){
			CRDPSRAPIViewer* pView = ((CRDPSRAPIViewer*)m_xUi[i].pCtrl);
			pView->DestroyWindow();
			delete pView;
			pView = NULL;
		}
	}

}

BEGIN_MESSAGE_MAP(CRDPViewDlg, CDialogEx)
	ON_BN_CLICKED(UI_POS_BTN_CONNECT, OnConnect)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_NCDESTROY()
END_MESSAGE_MAP()

BOOL CRDPViewDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wControlID = LOWORD(wParam);
	WORD wMessageID = HIWORD(wParam);

	if (wControlID != 0) {
		switch (wControlID) {
		case IDCANCEL:
			OnCancel();
			return TRUE;
			break;
		default:
			CDialogEx::OnCommand(wParam, lParam);
			break;
		}
	}
}

void CRDPViewDlg::OnCancel()
{
	DestroyWindow();
}

BOOL CRDPViewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CRect rcDesktop;
	// Get a handle to the desktop window
	HWND hDesktop = ::GetDesktopWindow();
	// Get the size of screen to the variable desktop
	::GetWindowRect(hDesktop, &rcDesktop);
	MoveWindow(0, 0, rcDesktop.Width(), rcDesktop.Height());

	Init();
	InitUiRectPos();
	InitUi();

	return TRUE;
}

void CRDPViewDlg::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	delete this;
}

void CRDPViewDlg::OnConnect()
{
	if (!m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl || !m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl){
		return;
	}

	int nSel = ((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->GetCurSel();
	if (nSel == -1)
		return;
	pair<int, CString>* pData = (pair<int, CString>*)((CComboBox*)m_xUi[UI_POS_CB_SLAVES].pCtrl)->GetItemData(nSel);
	CString strSession = pData->second;
	CString strEdit;
	((CEdit*)m_xUi[UI_POS_EDIT_CONNTIONSTRING].pCtrl)->GetWindowText(strEdit);
	if (strEdit.GetLength() > 0)
		strSession = strEdit;
	try
	{
		((CRDPSRAPIViewer*)m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl)->Connect(strSession, L"groupName", L"");
	}
	catch (...)
	{
		AfxMessageBox(L"RDP error!");
	}
}


int CRDPViewDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (m_pFont == NULL) {
		LOGFONT LogFont;

		memset(&LogFont, 0x00, sizeof(LogFont));
		_tcscpy_s(LogFont.lfFaceName, LF_FACESIZE, _T("MS Sans Serif"));

		LogFont.lfHeight = 8;

		m_pFont = new CFont;
		m_pFont->CreateFontIndirect(&LogFont);
		SetFont(m_pFont);
	}


	return 0;
}

void CRDPViewDlg::OnPaint()
{
	CDialogEx::OnPaint();
	((CRDPSRAPIViewer*)m_xUi[UI_POS_RDPVIEW_RDPVIEW].pCtrl)->Invalidate();
}