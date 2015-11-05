
#include "../DxLib/DxLib.h"

#include "C_FreeMenu.h"
#include "Image.h"
#include "Title.h"

#include "key.h"
#include "GameMain.h"

 C_FreeMenu tMenu(1,2,0);
Image bal[2];//風船　画像クラス生成
Image bg[1];//背景


void TitleMain(){
	
	static int initFlag=0;
	if(initFlag==0){
		TitleInit();
		initFlag=1;
	}
	TitleCal();
	TitleDraw();

	//描画

	//int z=0;
}


//タイトル初期化

void TitleInit(){
	//画像読み込み

	//位置設定
	bal[0].setInitXY(150,100);
	bal[1].setInitXY(500,100);

	bal[0].setGh("./img/title/NewGame.png");
	bal[1].setGh("./img/title/EndGame.png");
	bg[0].setGh("./img/title/bg.png");



}


//タイトル計算
void TitleCal(){
	tMenu.calHori();

	if(tMenu.getNum()==0){
		if(key_Trg==0x100){
			Game.mode=2;//ステージセレクトへ
			tMenu.Finalize();
		}
	}

	if(tMenu.getNum()==1){
		if(key_Trg==0x100){
			exit(0);//ステージセレクトへ
		tMenu.Finalize();
		}
	}

}
//タイトル描画
void TitleDraw(){

	bg[0].draw(255);//背景描画

	if(tMenu.num==0){
		bal[0].draw(255);//バルーン０描画
		bal[1].draw(155);//バルーン１描画
	}
	else{ 
		bal[0].draw(155);//バルーン０描画
		bal[1].draw(255);//バルーン１描画
	}


}