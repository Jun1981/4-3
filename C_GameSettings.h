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
 
	

	int mode;//�Q�[�����[�h




	

	//void setResoXY(int X,int Y);
	inline void C_GameSettings::setResoXY(int X,int Y){ResoX=X;ResoY=Y;}
	inline int getResoX(){return ResoX;}
	inline int getResoY(){return ResoY;}




protected:

	

	int ResoX,ResoY;//��ʉ𑜓x

};

//�O���錾
void GameMain();
void StgSelFinalize();//�I������

extern C_GameSettings Game;
extern Fonts fonts;//�t�H���g�N���X




