
// AOIRDPSessionDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "AOIRDPSession.h"
#include "AOIRDPSessionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAOIRDPSessionDlg 對話方塊



CAOIRDPSessionDlg::CAOIRDPSessionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAOIRDPSessionDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAOIRDPSessionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CAOIRDPSessionDlg::Init()
{
	SetWindowText(L"AOIRDPSessionDlg");

	ShowWindow(SW_HIDE);
}
#define WM_RDPSESSION_MSG			(WM_APP+1105)
enum{
	REQUEST_CONNECTIONSTRING,
	RESPONSE_CONNECTIONSTRING
};
BEGIN_MESSAGE_MAP(CAOIRDPSessionDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_RDPSESSION_MSG, OnRequest)
	//ON_BN_CLICKED(123, SendConnectionString)
END_MESSAGE_MAP()


// CAOIRDPSessionDlg 訊息處理常式

BOOL CAOIRDPSessionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定
	Init();
	SendConnectionString();
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CAOIRDPSessionDlg::OnPaint()
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
HCURSOR CAOIRDPSessionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
LRESULT CAOIRDPSessionDlg::OnRequest(WPARAM wp, LPARAM lp)
{
	switch (wp){
	case REQUEST_CONNECTIONSTRING:
		SendConnectionString();
		return 1L;
		break;
	default:
		return 1L;
		break;
	}
}

void CAOIRDPSessionDlg::SendConnectionString()
{
	HWND hwnd = ::FindWindow(NULL, L"AOITek_MasterWork_Slave");
	CWnd* pWnd = CWnd::FromHandle(hwnd);
	if (pWnd){
		
		CString strConnectionString = m_xRDPSession.GetConnectionString(); 

		LPCTSTR lpszString = strConnectionString;
		COPYDATASTRUCT cds;
		cds.dwData = RESPONSE_CONNECTIONSTRING;  
		cds.cbData = sizeof(TCHAR) * (_tcslen(lpszString) + 1);
		cds.lpData = (PVOID)lpszString;
		pWnd->SendMessage(WM_COPYDATA, (WPARAM)hwnd, (LPARAM)&cds);
	}
}