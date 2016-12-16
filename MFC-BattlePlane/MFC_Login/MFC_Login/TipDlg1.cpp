// TipDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "TipDlg1.h"
#include "afxdialogex.h"


// CTipDlg1 对话框

IMPLEMENT_DYNAMIC(CTipDlg1, CDialogEx)

CTipDlg1::CTipDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTipDlg1::IDD, pParent)
{

}

CTipDlg1::~CTipDlg1()
{
}

void CTipDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTipDlg1, CDialogEx)
END_MESSAGE_MAP()


// CTipDlg1 消息处理程序
