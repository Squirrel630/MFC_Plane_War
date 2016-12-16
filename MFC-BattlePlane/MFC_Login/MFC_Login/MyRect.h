#pragma once
#include "afx.h"

class CMyRect : public CRect
{
	CRect rClient;
public:
	void setCMyRect(){
		rClient.right=rClient.right-100;
		rClient.bottom=rClient.bottom-100;
	   }
};