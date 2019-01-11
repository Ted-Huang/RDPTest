
// MFCViewDlg.h : 標頭檔
//

#pragma once
#include <vector>
using namespace std;
// CMFCViewDlg 對話方塊
class CMFCViewDlg : public CDialogEx
{
private:
	enum{
		ITEM_START = 100, 
		ITEM_BTNCONNECT,
		ITEM_BTNDISCONNECT,
		ITEM_EDSESSTION,
		ITEM_VIEW,
		ITEM_END,
	};
// 建構
public:
	CMFCViewDlg(CWnd* pParent = NULL);	// 標準建構函式
	~CMFCViewDlg();
// 對話方塊資料
	enum { IDD = IDD_MFCVIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援
private:
	void Init();

// 程式碼實作
protected:
	HICON m_hIcon;
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnCancel();
	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnConnect();
	afx_msg void OnDisConnect();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CButton* m_pBtnConnect;
	CButton* m_pBtnDisconnect;
	CEdit* m_pEdSession;
	vector<pair<int, CString>> m_v;
	//CRDPSRAPIViewer* m_pViewer;
};
