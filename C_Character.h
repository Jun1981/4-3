#pragma once
#include "Image.h"

class C_Character: public Image{
public:
	//セッター
	inline void SetXYinDisp(int X,int Y){XinDisp=X,YinDisp=Y;}
	inline void SetXYinMap(int X,int Y){XinMap=X;YinMap=Y;}


	int XinDisp,YinDisp;//ディスプレイ内の座標
	int XinMap,YinMap;//マップ内座標	

protected:
	

};