// Play.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "Play.h"
#include "afxdialogex.h"


// Play 对话框

IMPLEMENT_DYNAMIC(Play, CDialogEx)

Play::Play(CWnd* pParent /*=NULL*/)
	: CDialogEx(Play::IDD, pParent)
{

}

Play::~Play()
{
}

void Play::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Play, CDialogEx)
END_MESSAGE_MAP()


// Play 消息处理程序
