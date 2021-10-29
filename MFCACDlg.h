
// MFCACDlg.h: 헤더 파일
//

#pragma once


// CMFCACDlg 대화 상자
class CMFCACDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCACDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	enum FourOP m_selectedOP;
	int m_nFirstOperand;
	int m_nSecondOperand;
	int m_nResult;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_EDitDisplay;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButtonmultiply();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButtonequl();
	afx_msg void OnBnClickedButtonall();
};

enum FourOP {
	PLUS = 1001,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NONE
};

