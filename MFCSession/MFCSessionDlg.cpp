
// MFCSessionDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCSession.h"
#include "MFCSessionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSessionDlg 對話方塊



CMFCSessionDlg::CMFCSessionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSessionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	COleException oExcep;
	CLSID clsID;

	HRESULT hr = ::CLSIDFromString(L"{9B78F0E6-3E05-4A5B-B2E8-E743A8956B65}", &clsID);
	if (FAILED(hr)) {
		return;
	}	
	m_pSession = new CRDPSRAPISharingSession();
	if (!m_pSession->CreateDispatch(clsID, &oExcep))
		return;

	//m_pSession->OnAttendeeConnected(this->m_lpDispatch);

}

void CMFCSessionDlg::OnAttendeeConnected(COleDispatchDriver *pAttendee)
{
	TRACE(L"arrr \n");
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

void CMFCSessionDlg::OnCreateSession()
{
	
	m_pSession->Open();
	
	CRDPSRAPIInvitationManager Mgr = m_pSession->get_Invitations();
	CRDPSRAPIInvitation pInvation = Mgr.CreateInvitation(L"baseAuth", L"groupName", L"", 64);
	CString strConnectionString = pInvation.get_ConnectionString();
	m_pEdConnectString->SetWindowText(strConnectionString);
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

