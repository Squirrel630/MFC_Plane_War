// TipDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "TipDlg.h"
#include "afxdialogex.h"
#include "GameDlg.h"


// CTipDlg 对话框

IMPLEMENT_DYNAMIC(CTipDlg, CDialogEx)

CTipDlg::CTipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTipDlg::IDD, pParent)
{

}

CTipDlg::~CTipDlg()
{
}

void CTipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTipDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTipDlg 消息处理程序


void CTipDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	INT_PTR nRes;
	CGameDlg gameDlg; // 构造对话框类CTipDlg的实例 
	nRes=gameDlg.DoModal();// 弹出对话框  
	if(IDCANCEL==nRes)return;// 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行
}
