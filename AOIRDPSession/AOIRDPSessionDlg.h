
// AOIRDPSessionDlg.h : 標頭檔
//

#pragma once
#include "RDPSession.h"

// CAOIRDPSessionDlg 對話方塊
class CAOIRDPSessionDlg : public CDialogEx
{
// 建構
public:
	CAOIRDPSessionDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_AOIRDPSESSION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

private:
	void Init();

// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnRequest(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
private:
	void SendConnectionString();
private:
	CRDPSession m_xRDPSession;
};
