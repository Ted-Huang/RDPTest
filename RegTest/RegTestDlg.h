
// RegTestDlg.h : ���Y��
//

#pragma once
#include "afxwin.h"


// CRegTestDlg ��ܤ��
class CRegTestDlg : public CDialogEx
{
// �غc
public:
	CRegTestDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_REGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩

private:
	void Init();
	void AddMsg(CString strMsg);
	void ExecuteCommand(CString strCmd, bool bExeAsBat);
	void SaveWinLogon(HKEY hCurKey, CString strKey, CString strValue);
// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListBox m_ls;
};
