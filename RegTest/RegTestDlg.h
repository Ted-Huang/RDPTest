
// RegTestDlg.h : 標頭檔
//

#pragma once
#include "afxwin.h"


// CRegTestDlg 對話方塊
class CRegTestDlg : public CDialogEx
{
// 建構
public:
	CRegTestDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_REGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

private:
	void Init();
	void AddMsg(CString strMsg);
	void ExecuteCommand(CString strCmd, bool bExeAsBat);
	void SaveWinLogon(HKEY hCurKey, CString strKey, CString strValue);
// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CListBox m_ls;
};
