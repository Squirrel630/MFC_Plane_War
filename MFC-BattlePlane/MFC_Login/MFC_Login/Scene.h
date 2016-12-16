#pragma once
#include <atlimage.h>
#include <Mmsystem.h>
#include "MyRect.h"

#pragma comment(lib, "Winmm.lib")
//
//struct ClienSize{
//	int Width;
//	int Height;
//};

class CScene{
	DECLARE_DYNAMIC(CScene)
public:
	int Width;
	int Height;
		CImage images;

private:
	int		beginY;//背景的Y坐标
	bool	isStart;//是否开始
public:
	CScene();  // 标准构造函数
	virtual ~CScene();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

	bool InitScene();//初始化场景
	void StickScene(CDC* pDC, int index, CRect rClient);//传入index-1表示输出开始图片
	void ReleaseScene();//释放内存资源
protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	//DECLARE_MESSAGE_MAP()
};
