#pragma once
#include "Image.h"

class C_Character: public Image{
public:
	//�Z�b�^�[
	inline void SetXYinDisp(int X,int Y){XinDisp=X,YinDisp=Y;}
	inline void SetXYinMap(int X,int Y){XinMap=X;YinMap=Y;}


	int XinDisp,YinDisp;//�f�B�X�v���C���̍��W
	int XinMap,YinMap;//�}�b�v�����W	

protected:
	

};