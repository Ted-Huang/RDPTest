
// MFCViewDlg.h : ���Y��
//

#pragma once
#include <vector>
using namespace std;
// CMFCViewDlg ��ܤ��
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
// �غc
public:
	CMFCViewDlg(CWnd* pParent = NULL);	// �зǫغc�禡
	~CMFCViewDlg();
// ��ܤ�����
	enum { IDD = IDD_MFCVIEW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩
private:
	void Init();

// �{���X��@
protected:
	HICON m_hIcon;
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void OnCancel();
	// ���ͪ��T�������禡
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
