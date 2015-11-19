#include "Image.h"
#include "../DxLib/DxLib.h"
#include <tchar.h>

//コンストラクタ
Image::Image(int w,int h){//画像サイズ指定

	this->imgWidth=w;this->imgHeight=h;
}
Image::Image(){
	x=y=initX=initY=gh=0;

}
//セッター
void Image::setGh(const char *str){

 gh=LoadGraph(str,0);

}
void Image::setSizeXY(int w,int h){

	imgWidth=w;imgHeight=h;

}
//void Image::setXY(int a, int b){
//	x=a;y=b;
//}

//ゲッター

int Image::getGh(){
	return gh;
}


//アニメ―ション用ハンドら
//void Image::getArrayAnimGh(int n){
//
//	animGh=new int[n];
//
//
//
//}

//DrawGraph現在位置(透過あり）
void Image::draw(int Brightness){
	SetDrawBright(Brightness,Brightness,Brightness);//明るさを設定
	DrawGraph(x,y,gh,1);
	SetDrawBright(255,255,255);//明るさを元に戻す
}
//DrawRotaGraph(); 回転やズームを利用 (倍率、角度）クラス内座標を使用
void Image::draw2(double zoom,int deg,int Brightness){
		SetDrawBright(Brightness,Brightness,Brightness);//明るさを設定
	DrawRotaGraph(x,y,zoom,(double)(deg/180.0)*3.14,gh,1,0);
	SetDrawBright(255,255,255);//明るさを元に戻す
	}

void Image::draw2(int X,int Y,double zoom,int deg,int flip,int Brightness){
		SetDrawBright(Brightness,Brightness,Brightness);//明るさを設定
	DrawRotaGraph(X,Y,zoom,(double)(deg/180.0)*3.14,gh,1,flip);
	SetDrawBright(255,255,255);//明るさを元に戻す
	}

void Image::resetXY(){
	x=initX;y=initY;
}
//ゲッター

int Image::getWidth(){
	return imgWidth;
}

int Image::getHeight(){
	return imgHeight;
}
