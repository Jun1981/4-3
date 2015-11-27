#pragma once
#include "Fonts.h"
#include "C_GameSettings.h"

//グローバル

extern Fonts uzura;//フォントクラス
extern C_GameSettings Game;//ゲームセッティングクラス

//フォントハンドラ
//うずらフォント
extern int Uzura16;
extern int Uzura20;
extern int Uzura24;
extern int Uzura30;
extern int Uzura60;
//Let's go Digital Regular
extern int digital30;





//define
	//色指定
#define WHITE GetColor(255,255,255)
#define BLACK GetColor(0,0,0)