
// MFC_Login.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_LoginApp:
// �йش����ʵ�֣������ MFC_Login.cpp
//

class CMFC_LoginApp : public CWinApp
{
public:
	CMFC_LoginApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_LoginApp theApp;