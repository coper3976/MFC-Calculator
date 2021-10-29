
// MFCACDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCAC.h"
#include "MFCACDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCACDlg 대화 상자



CMFCACDlg::CMFCACDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAC_DIALOG, pParent)
	, m_EDitDisplay(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EDitDisplay);
}

BEGIN_MESSAGE_MAP(CMFCACDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCACDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCACDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCACDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCACDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCACDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCACDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCACDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCACDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCACDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCACDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTONPLUS, &CMFCACDlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTONMINUS, &CMFCACDlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTONMULTIPLY, &CMFCACDlg::OnBnClickedButtonmultiply)
	ON_BN_CLICKED(IDC_BUTTONDIVIDE, &CMFCACDlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTONEQUL, &CMFCACDlg::OnBnClickedButtonequl)
	ON_BN_CLICKED(IDC_BUTTONALL, &CMFCACDlg::OnBnClickedButtonall)
END_MESSAGE_MAP()


// CMFCACDlg 메시지 처리기

BOOL CMFCACDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_selectedOP = NONE;
	m_nFirstOperand = 0;
	m_nSecondOperand = 0;

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCACDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCACDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCACDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCACDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '1';
	UpdateData(FALSE);


}


void CMFCACDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '2';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '3';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '4';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '5';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '6';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '7';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '8';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '9';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_EDitDisplay = m_EDitDisplay + '0';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButtonplus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_selectedOP = PLUS;
	m_nFirstOperand = _ttoi(m_EDitDisplay);
	m_EDitDisplay = ' ';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButtonminus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_selectedOP = MINUS;
	m_nFirstOperand = _ttoi(m_EDitDisplay);
	m_EDitDisplay = ' ';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButtonmultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_selectedOP = MULTIPLY;
	m_nFirstOperand = _ttoi(m_EDitDisplay);
	m_EDitDisplay = ' ';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButtondivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_selectedOP = DIVIDE;
	m_nFirstOperand = _ttoi(m_EDitDisplay);
	m_EDitDisplay = ' ';
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButtonequl()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nSecondOperand = _ttoi(m_EDitDisplay);

	switch (m_selectedOP) {
	case PLUS:
		m_nResult = m_nFirstOperand + m_nSecondOperand;
		break;

	case MINUS:
		m_nResult = m_nFirstOperand - m_nSecondOperand;
		break;

	case MULTIPLY:
		m_nResult = m_nFirstOperand * m_nSecondOperand;
		break;

	case DIVIDE:
		m_nResult = m_nFirstOperand / m_nSecondOperand;
		break;

	}

	m_EDitDisplay.Format(_T("%d"), m_nResult);
	UpdateData(FALSE);
}


void CMFCACDlg::OnBnClickedButtonall()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_nFirstOperand = 0;
	m_nSecondOperand = PLUS;
	m_nResult = 0;
	m_EDitDisplay = ' ';
	UpdateData(FALSE);
}
