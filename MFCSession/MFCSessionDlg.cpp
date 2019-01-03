
// MFCSessionDlg.cpp : ��@��
//

#include "stdafx.h"
#include "MFCSession.h"
#include "MFCSessionDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSessionDlg ��ܤ��



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


// CMFCSessionDlg �T���B�z�`��
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

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO:  �b���[�J�B�~����l�]�w
	Init(); 
	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

void CMFCSessionDlg::OnCreateSession()
{
	
	m_pSession->Open();
	
	CRDPSRAPIInvitationManager Mgr = m_pSession->get_Invitations();
	CRDPSRAPIInvitation pInvation = Mgr.CreateInvitation(L"baseAuth", L"groupName", L"", 64);
	CString strConnectionString = pInvation.get_ConnectionString();
	m_pEdConnectString->SetWindowText(strConnectionString);
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CMFCSessionDlg::OnPaint()
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
HCURSOR CMFCSessionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

