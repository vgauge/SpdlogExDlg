
// SpdlogExDlgDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "SpdlogExDlg.h"
#include "SpdlogExDlgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSpdlogExDlgDlg dialog



CSpdlogExDlgDlg::CSpdlogExDlgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPDLOGEXDLG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSpdlogExDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSpdlogExDlgDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_BASIC_LOGGER, &CSpdlogExDlgDlg::OnBnClickedBtnBasicLogger)
END_MESSAGE_MAP()


// CSpdlogExDlgDlg message handlers

BOOL CSpdlogExDlgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	//spdlog #3
	m_logger = spdlog::basic_logger_mt("basic_logger", "log/basic-log.txt");

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSpdlogExDlgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSpdlogExDlgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSpdlogExDlgDlg::OnBnClickedBtnBasicLogger()
{
	//spdlog #4
	m_logger->info("test");
	m_logger->error("error {}", 1234);
	m_logger->warn("Easy padding in numbers like {:08d}", 12);
	m_logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
	m_logger->info("Support for floats {:03.2f}", 1.23456);
	m_logger->info("Positional args are {1} {0}..", "too", "supported");
	m_logger->info("{:<30}", "left aligned");
	m_logger->set_level(spdlog::level::trace); // Set global log level to debug
	m_logger->trace("This message should be displayed..");
	m_logger->info("Function name is {}", __FUNCTION__);

	if (m_logger)	m_logger->flush();
}
