#pragma once
#include "C_TableMenu.h"
#include "Image.h"
#include "Fonts.h"

void StgSelMain();
void StgSelInit();
void StgSelCal();
void StgSelDraw();

void StgSeleFinalize();//終了処理



//extern C_TableMenu *stgMenu;
	
	

extern C_TableMenu *stgMenu;



namespace stgSel{

	extern Image bg;//背景
	extern Image cursor;//カーソル
	extern Image fairy;//妖精イメージ
	extern Image fukidashi;//吹き出し画像クラス
	extern Image board;//板枠（右上文字背景）クラス
	extern Fonts fonts;//フォントクラス	
	
};




enum DIFF{
		easy,
		normal,
		hard
	};
extern DIFF diff;