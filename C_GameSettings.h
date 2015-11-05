#pragma once

class C_GameSettings{

public:
	//void setResoXY(int X,int Y);
	inline void C_GameSettings::setResoXY(int X,int Y){ResoX=X;ResoY=Y;}
	inline int getResoX(){return ResoX;}
	inline int getResoY(){return ResoY;}
protected:
	int ResoX,ResoY;//‰æ–Ê‰ð‘œ“x

};