#pragma once


#include "../DxLib/DxLib.h"
#include <vector>
using namespace std;

class C_ScrollLine{

public:

	//コンストラクタ
	C_ScrollLine();//デフォルトコンストラクタ
	C_ScrollLine(
		int NumOfLine,
		int LineSpace,//行間		
		int CharSpace=0//文字間隔　
		);//コンストラクタ
	//C_ScrollLine(int NumOfLine);//コンストラクタ(行数指定）

	//関数
	void setString(
		int n,//何行目か
		char* STR//文字列
		);
	
	void scrollLine(
		int X,int Y,//文字開始位置座標				
		//デフォルト		
		int fHandle,//フォントハンドル
		
		
		int Color=GetColor(0,0,0),//色(デフォルト黒）
		int Speed=5,//メッセージスピード
		int LineSpace=32 //行間
		);//文字送り
	void resetLine();
	//void scrollLine();
	void setCharColor(int R,int G,int B);//色設定
	//void changeFontHandle(int);


	//ｹﾞｯﾀｰ
	inline int getRowNum(){return numOfLine;}

	//char **str;		


	int nowRowNum;//今の行
protected:
	
	unsigned int i;//何番目の文字か
	int spdCnt;//スピード調整用カウンタ
	int speed;//文字送りスピード
	//int spdCnt;//スピードカウンタ
	vector<char*> V_Str;
	char  str[5][256];//文字表示用配列	

	int charSpace;//文字間隔　
	int lineSpace;//行間
	int charColor;//色

	int numOfLine;//行数
	char* tempStr;//文字列を入れる

};
