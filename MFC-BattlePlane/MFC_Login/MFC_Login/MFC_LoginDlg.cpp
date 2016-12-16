
// MFC_LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "MFC_LoginDlg.h"
#include "afxdialogex.h"
#include "TipDlg.h"
#include "TipDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFC_LoginDlg 对话框



CMFC_LoginDlg::CMFC_LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_LoginDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_LoginDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_LoginDlg::OnBnClickedButton1)
//	ON_EN_CHANGE(IDC_EDIT1, &CMFC_LoginDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_LoginDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFC_LoginDlg 消息处理程序

BOOL CMFC_LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_LoginDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_LoginDlg::OnPaint()
{
	CPaintDC dc(this); // 用于绘制的设备上下文

//************************************************************
//***************背景图片插入代码，等爸爸会变透明了再加
/*		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_BITMAP1);
		CBrush brush;
		brush.CreatePatternBrush(&bitmap);
		CBrush* pOldBrush=dc.SelectObject(&brush);
		dc.Rectangle(0,0,866,481);
		dc.SelectObject(pOldBrush);
		*/
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_LoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//****************************************【进入游戏的代码实现】*************************************

void CMFC_LoginDlg::OnBnClickedButton1(){
	INT_PTR nRes;
	CTipDlg tipDlg; // 构造对话框类CTipDlg的实例 
	nRes=tipDlg.DoModal();// 弹出对话框  
	if(IDCANCEL==nRes)return;// 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行
	//CDialogEx::OnOK();
}

void CMFC_LoginDlg::OnBnClickedButton2(){
	// TODO: 在此添加控件通知处理程序代码
	INT_PTR nRes;
	CTipDlg1 tipDlg; // 构造对话框类CTipDlg的实例 
	nRes=tipDlg.DoModal();// 弹出对话框  
	if(IDCANCEL==nRes)return;// 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行
}

void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//要输入点新手模式时跳转的代码啊么么哒！
	CDialogEx::OnOK();
}

//*********************************************************************************************************

void CMFC_LoginDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

