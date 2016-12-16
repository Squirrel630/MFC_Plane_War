// Game.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "Game.h"
#include "afxdialogex.h"


// CGame 对话框

IMPLEMENT_DYNAMIC(CGame, CDialogEx)

CGame::CGame(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGame::IDD, pParent)
{

}

CGame::~CGame()
{
}

void CGame::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGame, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CGame 消息处理程序


//void CGame::OnTimer(UINT_PTR nIDEvent)
//{
//
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//
//	//双缓冲
//	CDC *pDC = GetDC();
//
//	//获得客户区矩形区域
//	GetClientRect(&rect);
//	//内存缓冲CDC
//	CDC cdc;
//
//	//内存中承载临时图像的缓冲位图
//	CBitmap* cacheBitmap = new CBitmap;
//	//用当前设备CDC初始化缓冲CDC
//	cdc.CreateCompatibleDC(pDC);
//	//绑定pDC和缓冲位图的关系，cdc先输出到缓冲位图中，输出完毕之后再一次性将缓冲位图输出到屏幕
//	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
//	//替换cdc原本的缓冲区为缓冲位图，这样cdc输出的内容就写到了缓冲位图中
//	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
//	
//	//scene.StickScene(&cdc, 0, rect);
//	//刷新显示战机
//	if (myplane != NULL) {
//		myplane->Draw(&cdc,FALSE,isProtect);
//	}
//
//
//	//将二级缓冲cdc中的数据推送到一级级缓冲pDC中，即输出到屏幕中
//	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
//	//释放二级cdc
//	cdc.DeleteDC();
//	//释放缓冲位图
//	cacheBitmap->DeleteObject();
//	//释放一级pDC
//	ReleaseDC(pDC);
//	CDialogEx::OnTimer(nIDEvent);
//}
//
//void CGame::play(){
//	SetTimer(2,1000,NULL); 
//}

void CGame::draw()
{

	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//双缓冲
	CDC *pDC = GetDC();

	//获得客户区矩形区域
	//GetClientRect(&rect);
	CRect rect;
	CWnd *pWnd = GetDlgItem(IDC_STATIC);//参数为控件ID。
	pWnd->GetClientRect(&rect);
	//内存缓冲CDC
	CDC cdc;

	//内存中承载临时图像的缓冲位图
	CBitmap* cacheBitmap = new CBitmap;
	//用当前设备CDC初始化缓冲CDC
	cdc.CreateCompatibleDC(pDC);
	//绑定pDC和缓冲位图的关系，cdc先输出到缓冲位图中，输出完毕之后再一次性将缓冲位图输出到屏幕
	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//替换cdc原本的缓冲区为缓冲位图，这样cdc输出的内容就写到了缓冲位图中
	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	
	//scene.StickScene(&cdc, 0, rect);
	//刷新显示战机
	if (myplane != NULL) {
		myplane->Draw(&cdc,FALSE,isProtect);
	}


	//将二级缓冲cdc中的数据推送到一级级缓冲pDC中，即输出到屏幕中
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	//释放二级cdc
	cdc.DeleteDC();
	//释放缓冲位图
	cacheBitmap->DeleteObject();
	//释放一级pDC
	ReleaseDC(pDC);
}