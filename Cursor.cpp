#include "Cursor.h"
#include "Image.h"
#include "../DxLib/DxLib.h"

//コンストラクタ
Cursor::Cursor(int w,int h){//画像サイズ指定

	this->imgWidth=w;this->imgHeight=h;
}

void Cursor::draw(int a,int b,int BRIGHTNESS){
	SetDrawBright(BRIGHTNESS,BRIGHTNESS,BRIGHTNESS);//明るさを設定
	DrawGraph(a,b-imgHeight/2,gh,1);
	SetDrawBright(255,255,255);//明るさを元に戻す
}

