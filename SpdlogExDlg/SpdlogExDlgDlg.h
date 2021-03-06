
// SpdlogExDlgDlg.h : header file
//

#pragma once
//spdlog #1
#include <spdlog/sinks/basic_file_sink.h> 

// CSpdlogExDlgDlg dialog
class CSpdlogExDlgDlg : public CDialogEx
{
// Construction
public:
	CSpdlogExDlgDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPDLOGEXDLG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
	//spdlog #2
	std::shared_ptr<spdlog::logger> m_logger;
public:
	afx_msg void OnBnClickedBtnBasicLogger();
};
