// GameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Login.h"
#include "GameDlg.h"
#include "afxdialogex.h"
#include "atlimage.h"
#include <Mmsystem.h>
//#include "TipDlg2.h"
// CGameDlg 对话框

IMPLEMENT_DYNAMIC(CGameDlg, CDialogEx)

	CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGameDlg::IDD, pParent)
	, m_FlyTime(0)
	, m_Grade(0)
	, m_Blood(0)
	, m_Honor(_T(""))
{
	m_FlyTime=0;
	m_Grade=0;
	m_Blood=100;
	m_Honor="无名小兵";
	begin=0;
	//	isProtect=false;
	//m_isUpdate=false;
}

CGameDlg::~CGameDlg()
{
}

void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, m_FlyTime);
	DDX_Text(pDX, IDC_EDIT2, m_Grade);
	DDX_Text(pDX, IDC_EDIT3, m_Blood);
	DDX_Text(pDX, IDC_EDIT4, m_Honor);
	//	DDX_Control(pDX, IDC_PLANE_STATIC, m_PlanePic);
	//DDX_Control(pDX, IDC_CHECK2, m_isUpdate);
	//	DDX_Control(pDX, IDC_CHECK4, m_isProtect);
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CGameDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CGameDlg::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_STN_CLICKED(IDC_GAME_SIZE, &CGameDlg::OnStnClickedGameSize)
	ON_BN_CLICKED(IDCANCEL, &CGameDlg::OnBnClickedCancel)
	//	ON_BN_CLICKED(IDC_CHECK2, &CGameDlg::OnBnClickedCheck2)
	//ON_BN_CLICKED(IDC_CHECK4, &CGameDlg::OnBnClickedCheck4)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CGameDlg 消息处理程序

//************【定时器】****************************
void CGameDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//ChangeCoordinate();  ();  
	//ChangeCoordinate();
	switch(nIDEvent){
	case 1:{
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
		isUpdate = (bool)pBtn->GetCheck();
		CButton* pBtn2 = (CButton*)GetDlgItem(IDC_CHECK4);
		isProtect = (bool)pBtn2->GetCheck();
		SetDlgItemInt(IDC_EDIT5,++m_FlyTime);//刷新飞行时间的显示框
		SetDlgItemInt(IDC_EDIT2,m_Grade);
		SetDlgItemInt(IDC_EDIT3,m_Blood);
		if(m_Grade>200){
			if(m_Grade<400)m_Honor="飞行小战士";
			else{
				if(m_Grade<600)m_Honor="光荣飞行员";
				else m_Honor="飞行小英雄";
			}
		}
		SetDlgItemText(IDC_EDIT4,m_Honor);
		   }break;
	case 2:{
		//CDialogEx::OnPaint();
		Invalidate();
		   }break;
	}
	//CView::OnTimer(nIDEvent);
	//if(plane)
	CDialogEx::OnTimer(nIDEvent);
}

//********************【开始游戏】********************
void CGameDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(over==TRUE){
		m_FlyTime=0;
		m_Grade=0;
		m_Blood=100;
		m_Honor="无名小兵";
		begin=0;
		OnCreat();
		over=FALSE;
	}
	begin=1;
	SetTimer(1,1000,NULL); 
	SetTimer(2,100,NULL);
}


void CGameDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(1);
	KillTimer(2);
	//PlaySound((LPCTSTR)IDR_WAV_GAMEOVER, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

}

void CGameDlg::OnCreat(){
	CMyPlane::LoadImage();
	CMyPlane::LoadImageProtect();
	CBomb::LoadImage();
	CEnemy::LoadImage();
	CBoss::LoadImage();
	CExplosion::LoadImage();
	CBall::LoadImageDown();
	scene.InitScene();
	isPause=0;
	over=FALSE;
	enemycreat=0;
	bossLoaded=FALSE;
	isBoss=FALSE;
	isUpdate=FALSE;
	speed=5;
	ballcreat=0;
	bossBlood=7;
	isProtect=FALSE;
	//	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
	//	pBtn->SetCheck(0);
	//CMyPlane::LoadImageProtect();
	myplane = new CMyPlane(FALSE);
	//	OnPaint();
	//game.play();
}

void CGameDlg::GetClientSize(){
	CRect clientrect;
	GetDlgItem(IDC_GAME_SIZE)->GetClientRect(clientrect);
	clientsize.Width = clientrect.Width();
	clientsize.Height = clientrect.Height();
	clientsize.Height /= 15;
	clientsize.Width /= 15;
}

void CGameDlg::OnPaint(){
	if(begin==0){
		OnCreat();
	}

	CPaintDC dc(this);
	//CClientDC dc(this);

	CDC *pDC = GetDC();
	//获得客户区矩形区域
	GetClientRect(&rect);
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


	//刷新显示战机
	if(scene.images!=NULL){
		scene.StickScene(&cdc, 0, rect);
	}
	if (myplane != NULL) {
		myplane->Draw(&cdc,FALSE,isProtect);
	}

	//战机发射子弹
	if (myplane != NULL&& isPause == 0){
		//声明战机子弹位置
		POSITION posBomb = NULL, tBomb = NULL;
		posBomb = bombList.GetHeadPosition();
		while (posBomb != NULL){
			tBomb = posBomb;
			bomb = (CBomb *)bombList.GetNext(posBomb);
			if (bomb->GetPoint().x<rect.left || bomb->GetPoint().x>825
				|| bomb->GetPoint().y<rect.top || bomb->GetPoint().y>490){
					//删除越界的子弹
					bombList.RemoveAt(tBomb);
					delete  bomb;
			}//if
			else
				bomb->Draw(&cdc, FALSE);
		}//while
	}

	//随机添加敌机,敌机随机发射炸弹，
	if (myplane != NULL && isPause == 0&&isBoss==FALSE){
		if(enemycreat==8){
			int direction = 1;//设置敌机的方向，从上方飞出
			CEnemy *enemy = new CEnemy(direction, rect.right, rect.bottom);
			enemyList.AddTail(enemy);//随机产生敌机
			//	}
			enemycreat=0;
		}
		else{
			enemycreat++;
		}
	}

	//超出边界的敌机进行销毁
	POSITION stPos = NULL, tPos = NULL;
	stPos = enemyList.GetHeadPosition();
	int direction = 1;
	while (stPos != NULL){
		tPos = stPos;
		CEnemy *enemy = (CEnemy *)enemyList.GetNext(stPos);
		//判断敌机是否出界
		if (enemy->GetPoint().x<rect.left || enemy->GetPoint().x>870
			|| enemy->GetPoint().y<rect.top || enemy->GetPoint().y>500){
				enemyList.RemoveAt(tPos);
				delete enemy;
		}//if
		else{
			//没出界，绘制
			enemy->Draw(&cdc,0, FALSE);
		}//else
	}//while

	//添加爆炸效果，战机子弹打中敌机
	if (myplane != NULL&& isPause == 0){
		//声明战机子弹位置，敌机位置
		POSITION bombPos, bombTemp, enemyPos, enemyTemp;
		for (bombPos = bombList.GetHeadPosition(); (bombTemp = bombPos) != NULL;){
			bomb = (CBomb *)bombList.GetNext(bombPos);
			for (enemyPos = enemyList.GetHeadPosition(); (enemyTemp = enemyPos) != NULL;){
				enemy = (CEnemy *)enemyList.GetNext(enemyPos);
				//获得战机子弹的矩形区域
				CRect bombRect = bomb->GetRect();
				//获得敌机的矩形区域
				CRect enemyRect = enemy->GetRect();
				//判断两个矩形区域是否有交接
				CRect tempRect;
				if (tempRect.IntersectRect(&bombRect, enemyRect)){
					//将爆炸对象添加到爆炸链表中
					CExplosion *explosion = new CExplosion((bomb->GetPoint().x + BOMB_WIDTH / 2 - EXPLOSION_WIDTH / 2), (bomb->GetPoint().y + BOMB_HEIGHT / 2 - EXPLOSION_WIDTH / 2));
					explosionList.AddTail(explosion);
					//	PlaySound((LPCTSTR)IDR_WAV_EXPLOSION, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//爆炸后删除子弹
					bombList.RemoveAt(bombTemp);
					delete  bomb;
					//指向下一个
					bomb = NULL;
					//敌机生命值减少
					enemy->life -= (1 + isUpdate);
					if (enemy->life <= 0) {
						//增加得分
						m_Grade=m_Grade+20;

						//删除敌机
						enemyList.RemoveAt(enemyTemp);
						delete  enemy;
					}
					//炮弹已删除，直接跳出本循环
					break;
				}
			}
			if (isBoss == TRUE&&bomb != NULL) {
				//获得战机子弹的矩形区域
				CRect bombRect = bomb->GetRect();
				//获得Boss的矩形区域
				CRect bossRect = boss->GetRect();
				//判断两个矩形区域是否有交接
				CRect tempRect;
				if (tempRect.IntersectRect(&bombRect, bossRect)){
					//将爆炸对象添加到爆炸链表中
					CExplosion *explosion = new CExplosion((bomb->GetPoint().x + BOMB_WIDTH / 2 - EXPLOSION_WIDTH / 2), (bomb->GetPoint().y + BOMB_HEIGHT / 2 - EXPLOSION_WIDTH / 2));
					explosionList.AddTail(explosion);
					//	PlaySound((LPCTSTR)IDR_WAV_EXPLOSION, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
					//爆炸后删除子弹
					bombList.RemoveAt(bombTemp);
					delete  bomb;
					bomb = NULL;
					//是Boss，不删除敌机，只扣血
					bossBlood -=2;
					if (bossBlood <= 0) {
						CExplosion *explosion1 = new CExplosion(boss->GetPoint().x , boss->GetPoint().y );
						explosionList.AddTail(explosion1);
						CExplosion *explosion2 = new CExplosion((boss->GetPoint().x + BOSS_WIDTH ), (boss->GetPoint().y + BOSS_HEIGHT ));
						explosionList.AddTail(explosion2);
						CExplosion *explosion3 = new CExplosion((boss->GetPoint().x + BOSS_WIDTH ), (boss->GetPoint().y ));
						explosionList.AddTail(explosion3);
						CExplosion *explosion4 = new CExplosion((boss->GetPoint().x ), (boss->GetPoint().y + BOSS_HEIGHT ));
						explosionList.AddTail(explosion4);
						CExplosion *explosion5 = new CExplosion((boss->GetPoint().x + BOSS_WIDTH / 2 - EXPLOSION_WIDTH / 2), (boss->GetPoint().y + BOSS_HEIGHT / 2 - EXPLOSION_WIDTH / 2));
						explosion5->SetBossDie(TRUE);//标记最后一个炸弹，炸完之后跳入下一关
						explosionList.AddTail(explosion5);
						delete boss;
						boss = NULL;
						m_Grade=m_Grade+40;
						//			delete  myplane;
						//		myplane = NULL;
						//	isPass = 1;
						isBoss = FALSE;
					}
				}
			}
		}
	}//for

	//（2）添加爆炸效果，敌机炸弹打中战机
	if (myplane != NULL&& isPause == 0)
	{
		//声明敌机炸弹位置坐标，战机位置myPlanePos
		POSITION ballPos, ballTemp;
		for (ballPos = ballList.GetHeadPosition(); (ballTemp = ballPos) != NULL;){
			ball = (CBall *)ballList.GetNext(ballPos);
			//获得敌机炸弹的矩形区域
			CRect ballRect = ball->GetRect();
			//获得战机的矩形区域
			CRect myPlaneRect = myplane->GetRect();
			//判断两个矩形区域是否有交接
			CRect tempRect;
			//如果敌机炸弹打中战机，则使战机爆炸
			if (tempRect.IntersectRect(&ballRect, myPlaneRect)){
				//将爆炸对象加入爆炸链表中
				CExplosion *explosion = new CExplosion((ball->GetPoint().x + BALL_WIDTH / 2 - EXPLOSION_WIDTH / 2), (ball->GetPoint().y + BALL_HEIGHT / 2 - EXPLOSION_WIDTH / 2));
				//		PlaySound((LPCTSTR)IDR_WAV_EXPLOSION, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				explosionList.AddTail(explosion);
				if (isProtect == FALSE)
					//战机生命值减1
						m_Blood-=20;
				//删除敌机炸弹
				ballList.RemoveAt(ballTemp);
				delete  ball;
				//游戏结束
				if (m_Blood<0){
					//lifeNum--;
					//	if (lifeNum <= 0) {
					//删除战机对象
					//isPause = TRUE;
					//CMyPlane* temp = myplane;
					//myplane = NULL;
					////myplane = new CMyPlane(FALSE);
					//delete  temp;
					//temp = NULL;
					//	KillTimer(2);
					gameOver(pDC,cdc, cacheBitmap);
					break;
					//}
					//else {
					//myLife = DEFAULT_LIFE;
					//	}
				}//if
			}//if
		}//for
	}//if

	//添加爆炸效果，敌机与战机相撞
	if (myplane != NULL&& isPause == 0){
		//获得战机的矩形区域
		CRect myPlaneRect = myplane->GetRect();
		POSITION enemyPos, enemyTemp;
		for (enemyPos = enemyList.GetHeadPosition(); (enemyTemp = enemyPos) != NULL;){
			enemy = (CEnemy *)enemyList.GetNext(enemyPos);
			//获得敌机的矩形区域
			CRect enemyRect = enemy->GetRect();
			//判断两个矩形区域是否有交接
			CRect tempRect;
			if (tempRect.IntersectRect(&enemyRect, myPlaneRect)){
				CExplosion *explosion = new CExplosion(myplane->GetPoint().x + PLANE_WIDTH / 2 - EXPLOSION_WIDTH / 2, myplane->GetPoint().y + PLANE_HEIGHT / 2 - EXPLOSION_WIDTH / 2);
				//	PlaySound((LPCTSTR)IDR_WAV_EXPLOSION, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				explosionList.AddTail(explosion);
				if (isProtect == FALSE)
					//战机生命值减1
						m_Blood=m_Blood-20;
				//敌机生命值减少
				enemy->life--;
				if (enemy->life <= 0) {
					//得分
					//				passScore++;
					//删除敌机
					enemyList.RemoveAt(enemyTemp);
					delete  enemy;
				}
			}
		}
	}

	//显示爆炸效果
	if (myplane != NULL&&isPause == FALSE) {
		POSITION explosionPos, explosionTemp;
		explosionPos = explosionList.GetHeadPosition();
		//检索爆炸链表，非空时在所在位置显示
		while (explosionPos != NULL){
			explosionTemp = explosionPos;
			explosion = (CExplosion *)explosionList.GetNext(explosionPos);
			BOOL flag = explosion->Draw(&cdc, FALSE);
			//爆炸8帧结束，删除爆炸对象
			if (flag == EXPLOSION_STATUS_STOP) {
				//删除爆炸对象
				explosionList.RemoveAt(explosionTemp);
				delete explosion;
			}
		}//while
	}

	//显示Boss
	if((m_Grade==300||m_Grade==500||m_Grade==700||m_Grade==900) && isBoss==FALSE){
		//isBoss=TRUE;
		//进入Boss
		isBoss = TRUE;
		boss = new CBoss(1, rect.right, rect.bottom);
		boss->SetSpeed(BOSS_SPEED+0-1);
		boss->life = BOSS_LIFE + 2 * 50;//Boss总血量
		bossBlood= BOSS_LIFE + 2 * 50;
		bossLoaded = FALSE;
	}
	if (myplane != NULL &&boss!=NULL&& isPause == 0 && isBoss == TRUE) {
		BOOL status = boss->Draw(&cdc,0, FALSE);
		if (status == TRUE)
			bossLoaded = TRUE;
	}

	//Boss产生炮弹
	if (myplane != NULL && isPause == 0 && isBoss == TRUE) {
		if(ballcreat==3){
			//Boss发射子弹
			//敌机炸弹产生定时器触发
			//	if (nIDEvent == 3) {
			//设置定时器产生敌机炸弹
			//		PlaySound((LPCTSTR)IDR_WAV_BALL, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			CBall * ball1 = new CBall(boss->GetPoint().x + BOSS_WIDTH / 2, boss->GetPoint().y + BOSS_HEIGHT, 1);
			ball1->SetBallSpeed(BALL_SPEED );
			ballList.AddTail(ball1);
			CBall * ball2 = new CBall(boss->GetPoint().x +5, boss->GetPoint().y + BOSS_HEIGHT, 1);
			ball2->SetBallSpeed(BALL_SPEED );
			ballList.AddTail(ball2);
			//CBall * ball3 = new CBall(boss->GetPoint().x + BOSS_WIDTH -5, boss->GetPoint().y + BOSS_HEIGHT,1);
			//	ball3->SetBallSpeed(BALL_SPEED );
			//	ballList.AddTail(ball3);
			CBall * ball4 = new CBall(boss->GetPoint().x + BOSS_WIDTH / 2+85, boss->GetPoint().y + BOSS_HEIGHT, 1);
			ball4->SetBallSpeed(BALL_SPEED );
			ballList.AddTail(ball4);
			CBall * ball5 = new CBall(boss->GetPoint().x + BOSS_WIDTH / 2-85, boss->GetPoint().y + BOSS_HEIGHT, 1);
			ball5->SetBallSpeed(BALL_SPEED );
			ballList.AddTail(ball5);

			//	}
			//显示Boss炸弹
			//判断产生的敌机炸弹是否出界，若已经出界，则删除该敌机炸弹
			POSITION stBallPos = NULL, tBallPos = NULL;
			stBallPos = ballList.GetHeadPosition();
			while (stBallPos != NULL){
				tBallPos = stBallPos;
				ball = (CBall *)ballList.GetNext(stBallPos);
				if (ball->GetPoint().x<rect.left || ball->GetPoint().x>rect.right
					|| ball->GetPoint().y<rect.top || ball->GetPoint().y>rect.bottom){
						ballList.RemoveAt(tBallPos);
						delete  ball;
				}//if
				else
				{
					ball->Draw(&cdc, FALSE);
				}//else
			}//while
			ballcreat=0;
		}
		else{
			ballcreat++;
		}
	}

	//死亡
	if (m_Blood<0){
		/*	CMyPlane* temp = myplane;
		myplane = NULL;
		delete  temp;
		temp = NULL;
		CBitmap* tCache = cacheBitmap;
		cacheBitmap = new CBitmap;
		cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
		cdc.SelectObject(cacheBitmap);
		delete tCache;*/
		gameOver(pDC,cdc, cacheBitmap);
		//KillTimer(2);
	}//if

	//将二级缓冲cdc中的数据推送到一级级缓冲pDC中，即输出到屏幕中
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	//释放二级cdc
	cdc.DeleteDC();
	//释放缓冲位图
	cacheBitmap->DeleteObject();
	//释放一级pDC
	ReleaseDC(pDC);

}


void CGameDlg::OnStnClickedGameSize()
{
	// TODO: 在此添加控件通知处理程序代码
} 

/**********************重写键盘响应函数********/
BOOL CGameDlg::PreTranslateMessage(MSG* pMsg){
	// TODO:  在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN){
		switch (pMsg->wParam){
		case VK_UP:{
			int y = myplane->GetPoint().y - speed;
			if (y < 24)
				y = 24;
			myplane->SetPoint(myplane->GetPoint().x, y);
				   }break;
		case VK_DOWN:{	
			int y = myplane->GetPoint().y + speed;
			if (y >490)
				y = 490;
			myplane->SetPoint(myplane->GetPoint().x, y);
					 }break;
		case VK_LEFT:{
			int x = myplane->GetPoint().x - speed;
			if (x < 24)
				x = 24;
			myplane->SetPoint(x, myplane->GetPoint().y);
					 }break;
		case VK_RIGHT:{	
			int x = myplane->GetPoint().x + speed;
			if (x >825)
				x = 825;
			myplane->SetPoint(x, myplane->GetPoint().y);
					  }break;
		case 83: {//S键发射子弹
			if(isUpdate=FALSE){
				CBomb *Bomb1 = new CBomb(myplane->GetPoint().x+45, myplane->GetPoint().y, 1,isUpdate);
				//	PlaySound((LPCTSTR)IDR_WAV_BOMB, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				bombList.AddTail(Bomb1);
				//	CBomb *Bomb2 = new CBomb(myplane->GetPoint().x + PLANE_WIDTH-50, myplane->GetPoint().y, 1, isUpdate);
				//	bombList.AddTail(Bomb2);
				//子弹自动飞行，在Timer中绘制
			}
			else{
				CBomb *Bomb1 = new CBomb(myplane->GetPoint().x+20, myplane->GetPoint().y, 1,isUpdate);
				//	PlaySound((LPCTSTR)IDR_WAV_BOMB, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				bombList.AddTail(Bomb1);
				CBomb *Bomb2 = new CBomb(myplane->GetPoint().x + PLANE_WIDTH-50, myplane->GetPoint().y, 1, isUpdate);
				bombList.AddTail(Bomb2);
				//子弹自动飞行，在Timer中绘制v
			}
				 }
				 break;

		default:
			break;

		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CGameDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CGameDlg::gameOver(CDC* pDC,CDC& cdc,CBitmap* cacheBitmap)
{
	//结束游戏界面
	//释放计时器
	KillTimer(1);
	KillTimer(2);
	over=TRUE;
	HFONT textFont;
	textFont = CreateFont(24, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 10, 0);
	cdc.SelectObject(textFont);
	cdc.SetTextColor(RGB(255, 0, 0));
	//设置透明背景
	cdc.SetBkMode(TRANSPARENT);
	cdc.TextOutW(250, 290, _T("GAME OVER！可点击开始重新开始游戏！"));
}


BOOL CGameDlg::OnEraseBkgnd(CDC* pDC){
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return true;
}

