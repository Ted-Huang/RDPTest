
// RegTestDlg.cpp : ��@��
//

#include "stdafx.h"
#include "RegTest.h"
#include "RegTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRegTestDlg ��ܤ��



CRegTestDlg::CRegTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRegTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_ls);
}

BEGIN_MESSAGE_MAP(CRegTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CRegTestDlg �T���B�z�`��

BOOL CRegTestDlg::OnInitDialog()
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

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C
void CRegTestDlg::Init()
{
	CString strMsg;
	HKEY	hCurKey;
	CString strKeyValue = _T("");
	DWORD mySize = 256;
	strKeyValue.Preallocate(mySize);
	DWORD myType = REG_SZ;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon"), 0, KEY_ENUMERATE_SUB_KEYS | KEY_QUERY_VALUE | KEY_SET_VALUE, &hCurKey) == ERROR_SUCCESS)
	{
		SaveWinLogon(hCurKey, L"AutoAdminLogon", L"1");
		SaveWinLogon(hCurKey, L"DefaultUserName", L"Aoi");
		SaveWinLogon(hCurKey, L"DefaultPassword", L"");
	}
	else
		AddMsg(L"RegOpenKeyEx error !");

	RegCloseKey(hCurKey);


	CString strCmd;
	strCmd.Format(_T("NET USER %s %s /ADD"), L"AOI_SHARE", L"5436AOI4885");
	ExecuteCommand(strCmd, false);
	AddMsg(L"add net user finish!");
}

void CRegTestDlg::AddMsg(CString strMsg)
{
	m_ls.AddString(strMsg);
	m_ls.SetCurSel(m_ls.GetCount() - 1);
}

void CRegTestDlg::OnPaint()
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
HCURSOR CRegTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRegTestDlg::ExecuteCommand(CString strCmd, bool bExeAsBat)
{
	//eric chao 201407
	// For MkLink & Rd Command,can't direct using in WinExec~
	// It only can execute by bat file~
	if (!bExeAsBat){
		WinExec(CW2A(strCmd.GetBuffer()), SW_HIDE);
		strCmd.ReleaseBuffer();
	}
	else{
		CFile xCmdFile;
		xCmdFile.Open(_T("IpcCmd.bat"), CFile::modeCreate | CFile::modeWrite, NULL);
		int nLen = strCmd.GetLength();
		xCmdFile.Write(CW2A(strCmd.GetBuffer()), nLen);
		CString strFullName = xCmdFile.GetFilePath();
		xCmdFile.Flush();
		xCmdFile.Close();
		strCmd.ReleaseBuffer();
		DWORD dwStart = ::GetTickCount();
		bool bFileError = false;
		for (;;){ //eric chao 20141031
			CFileStatus st;
			if (CFile::GetStatus(strFullName, st)){
				break;
			}
			else{
				::Sleep(100);
			}
			if ((::GetTickCount() - dwStart) > 3000){ //waiting 3 sec for file
				bFileError = true;
				break;
			}
		}
		if (!bFileError){
			WinExec("IpcCmd.bat", SW_HIDE);
		}
	}
}

void CRegTestDlg::SaveWinLogon(HKEY hCurKey, CString strKey, CString strValue)
{
	CString strMsg;
	int nRtn = RegSetValueEx(hCurKey, strKey, NULL, REG_SZ, (unsigned char*)strValue.GetBuffer(), strValue.GetLength() * 2);
	if (nRtn == ERROR_SUCCESS){
		strMsg.Format(L"Save %s Success!", strKey);
	}
	else{
		strMsg.Format(L"Save %s Fail! : error code %d", strKey, nRtn);
	}
	AddMsg(strMsg);
}

void CRegTestDlg::OnBnClickedButton1()
{

}

void CRegTestDlg::OnBnClickedButton2()
{


}
