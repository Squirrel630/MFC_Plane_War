// PlaneWar.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "PlaneWar.h"
#include "afxdialogex.h"


// PlaneWar 对话框

IMPLEMENT_DYNAMIC(PlaneWar, CDialogEx)

PlaneWar::PlaneWar(CWnd* pParent /*=NULL*/)
	: CDialogEx(PlaneWar::IDD, pParent)
{

}

PlaneWar::~PlaneWar()
{
}

void PlaneWar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PlaneWar, CDialogEx)
END_MESSAGE_MAP()


// PlaneWar 消息处理程序
