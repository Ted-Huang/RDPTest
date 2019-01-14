
// AOIRDPSessionDlg.cpp : ��@��
//

#include "stdafx.h"
#include "AOIRDPSession.h"
#include "AOIRDPSessionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAOIRDPSessionDlg ��ܤ��



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


// CAOIRDPSessionDlg �T���B�z�`��

BOOL CAOIRDPSessionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO:  �b���[�J�B�~����l�]�w
	Init();
	SendConnectionString();
	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CAOIRDPSessionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
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