
// MFCViewDlg.h : 標頭檔
//

#pragma once
#include "CRDPSRAPIViewer.h"

// CMFCViewDlg 對話方塊
class CMFCViewDlg : public CDialogEx
{
private:
	enum{
		ITEM_START = 0, 
		ITEM_BTNCONNECT,
		ITEM_EDSESSTION,
		ITEM_VIEW,
		ITEM_END,
	};
// 建構
public:
	CMFCViewDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_MFCVIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援
private:
	void Init();

// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnConnect();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CButton* m_pBtnCreate;
	CEdit* m_pEdSession;
	CRDPSRAPIViewer* m_pViewer;
};
