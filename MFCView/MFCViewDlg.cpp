
// MFCViewDlg.cpp : ��@��
//

#include "stdafx.h"
#include "MFCView.h"
#include "MFCViewDlg.h"
#include "afxdialogex.h"
#include "RDPViewDlg.h"
//CRDPSRAPIViewer  �Ӧ�C:\Windows\System32\rdpencom.dll

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCViewDlg ��ܤ��



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


// CMFCViewDlg �T���B�z�`��

BOOL CMFCViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO:  �b���[�J�B�~����l�]�w
	Init();
	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
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
// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CMFCViewDlg::OnPaint()
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
HCURSOR CMFCViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

