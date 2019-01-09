
// MFCViewDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MFCView.h"
#include "MFCViewDlg.h"
#include "afxdialogex.h"
#include "RDPViewDlg.h"
//CRDPSRAPIViewer  來自C:\Windows\System32\rdpencom.dll

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCViewDlg 對話方塊



CMFCViewDlg::CMFCViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCViewDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CMFCViewDlg::Init()
{
	CRect rcWnd;
	GetClientRect(rcWnd);
	m_pBtnConnect = new CButton;
	m_pBtnConnect->Create(_T("Connect"), WS_CHILD | WS_VISIBLE, CRect(0, 0, 120, 20), this, ITEM_BTNCONNECT);
	m_pBtnConnect = new CButton;
	m_pBtnConnect->Create(_T("DisConnect"), WS_CHILD | WS_VISIBLE, CRect(0, 20, 120, 40), this, ITEM_BTNDISCONNECT);
	m_pEdSession = new CEdit;
	m_pEdSession->Create(WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(130, 0, 1700, 20), this, ITEM_EDSESSTION);
	m_pViewer = new CRDPSRAPIViewer;
	m_pViewer->Create(_T("View"), WS_CHILD | WS_VISIBLE, CRect(0, 50, 1700, 900), this, ITEM_VIEW);
}

BEGIN_MESSAGE_MAP(CMFCViewDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ITEM_BTNCONNECT, OnConnect)
	ON_BN_CLICKED(ITEM_BTNDISCONNECT, OnDisConnect)
END_MESSAGE_MAP()


// CMFCViewDlg 訊息處理常式

BOOL CMFCViewDlg::OnInitDialog()
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

void CMFCViewDlg::OnConnect()
{
	CRDPViewDlg dlg(this);
	int nn = dlg.DoModal();
/*
	CString strSession;
	m_pEdSession->GetWindowText(strSession);

	m_pViewer->Connect(strSession, L"groupName", L"");*/
}

void CMFCViewDlg::OnDisConnect()
{
	m_pViewer->Disconnect();
}
// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMFCViewDlg::OnPaint()
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
HCURSOR CMFCViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

