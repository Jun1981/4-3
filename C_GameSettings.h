#pragma once
#include "Fonts.h"

	enum DIFF{
		easy,
		normal,
		hard
	};

class C_GameSettings{

public:

	DIFF diff;
 
	

	int mode;//ゲームモード




	

	//void setResoXY(int X,int Y);
	inline void C_GameSettings::setResoXY(int X,int Y){ResoX=X;ResoY=Y;}
	inline int getResoX(){return ResoX;}
	inline int getResoY(){return ResoY;}




protected:

	

	int ResoX,ResoY;//画面解像度

};

//前方宣言
void GameMain();
void StgSelFinalize();//終了処理

extern C_GameSettings Game;
extern Fonts fonts;//フォントクラス




