
#pragma once
#include "C_GameSettings.h"


extern C_GameSettings Game;

//前方宣言
void GameMain();
void StgSelFinalize();//終了処理

//色指定
#define WHITE GetColor(255,255,255)
#define BLACK GetColor(0,0,0)