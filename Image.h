#pragma once
#include <tchar.h>
#include "../DxLib/DxLib.h"


///<summary>
///いろんな画像全般クラス　
///</summary>
//抽象クラスです。継承して使ってください。
class Image{//画像全般くらす

public:
	Image(int,int);//コンストラクタ（画像サイズ指定）
	Image();//コンストラクタ（０）
	void Initialize();//初期化
	void Finalize();//終了処理

	//関数
	void setGh(const TCHAR *);//ghのセッター Dxlib.initが終わってからじゃないとLoadGraphが使えないので
	void setSizeXY(int,int);//サイズ指定
	
	
	inline void setXY(int a,int b){x=a;y=b;}//xとｙのセッター
	inline void setInitXY(int a,int b){initX=x=a;initY=y=b;}//初期位置セッター

	void resetXY();//現在位置を初期位置にリセット
	int getGh();//ghのゲッター
	int getWidth(),getHeight();//画像サイズを得る
	
	//画像描画関数
	virtual void draw(int Brightness);//DrawGraph現在位置(透過あり）
	virtual void draw2(double zoom,int deg,int Brightness);//DrawRotaGraph(); 回転やズームを利用 (倍率、角度）

	//ｹﾞｯﾀｰ
	inline int getX(){
		return x;
	}
	inline int getY(){
		return y;
	}




	//変数

	
	//void getArrayAnimGh(int);
protected:	
	int x,y;//現在座標（左上）
	
	int initX,initY;//初期位置
	int imgWidth,imgHeight;//画像サイズ　横　縦
	int gh;//画像ハンドラ		
};