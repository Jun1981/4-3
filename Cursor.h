#pragma once

//カーソルクラスです。
//メニュークラスを使います

#include "Image.h"//画像クラス
#include "Menu.h"//メニュークラス

class Cursor :public Image{
public:

	Cursor(int,int);//コンストラクタ（画像サイズ指定）
	virtual void draw(int,int,int BRIGHTNESS);//カーソル描画 画像の真ん中に合わせる






};