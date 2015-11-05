#pragma once
#include "C_TableMenu.h"
#include "Image.h"
#include "Fonts.h"

void StgSelMain();
void StgSelInit();
void StgSelCal();
void StgSelDraw();

void StgSeleFinalize();//�I������



//extern C_TableMenu *stgMenu;
	
	

extern C_TableMenu *stgMenu;



namespace stgSel{

	extern Image bg;//�w�i
	extern Image cursor;//�J�[�\��
	extern Image fairy;//�d���C���[�W
	extern Image fukidashi;//�����o���摜�N���X
	extern Image board;//�g�i�E�㕶���w�i�j�N���X
	extern Fonts fonts;//�t�H���g�N���X	
	
};




enum DIFF{
		easy,
		normal,
		hard
	};
extern DIFF diff;