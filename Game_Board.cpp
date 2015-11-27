#include "C_MAP.h"
#include "Game_Board.h"
#include "../DxLib/DxLib.h"

#include "C_GameSettings.h"
#include "Image.h"


#include "C_Character.h"
#include "key.h"


#include "map1.h"

#include "Fonts.h"

#include "common.h"

#include <time.h>

#include "C_TableMenu.h"


C_MAP map1; //クラス宣言


#define Char_Zure_Y 0
#define Char_Zure_X 48

C_TableMenu upDown(2,1,C_TableMenu::ver);//メニュークラス
namespace Board{

	C_Character player1;


	//画像クラス
	Image bg;

	Image roulette;//ルーレット画像
	Image finger;//指画像
	Image numBg;//
	Image arrow;//矢印画像クラス

	Fonts Digital;



	enum ARROW{
		UP=0,
		DOWN=1
	};

};using namespace Board;

int digital30;//フォントハンドら用
int digital82;//フォントハンドら用６０

int rouletteNum=1;//ルーレットの数字(1~6)

int arrowDir=UP;//矢印のデフォルト

static int rouletteMode=0;//ルーレットモード　（０：数字を決める　１：移動　２：分岐選択）

//static int moveWaitTime=30;


static int moveSpd=30;
	static int moveCnt=moveSpd;




void GameBoardInit(){
	map1.setResoXY(Game.getResoX(),Game.getResoY());//解像度設定
	map1.setMapChipSize(100,100);
	map1.setMapRowCol(21,60);
	map1.setMapDataArray(map1.row,map1.col);


	//マップスタート地点計算
	for(int i=0;i<21;i++){
		for(int j=0;j<60;j++){
			if(map1EvtData[i][j]==11){			

				map1.nowRow=i;map1.nowCol=j;
				map1.setStartXYinMap(map1.chipSizeX*j,map1.chipSizeY*i-100);			
				goto LoopOut;
			}		
		}
	}
LoopOut://ループ抜け用


	//フォント読み込み
	Digital.loadFont("fonts/Let's go Digital Regular.ttf");
	//フォント作成

	digital30= CreateFontToHandle( "Let's go Digital Regular",30,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	digital82= CreateFontToHandle( "Let's go Digital Regular",82,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;



	map1.loadMapChip("img/map/mapChip.png",13,1);


	//プレイヤー１の画像サイズ設定
	player1.setSizeXY(150,160);
	//プレイヤー１のｊ初期位置（画面内）設定
	player1.SetXYinDisp(
		Game.getResoX()/2-player1.getWidth()/2,

		Game.getResoY()/2-player1.getHeight()/2+100
		);


	//プレイヤーの下

	//背景画像取り込み
	bg.setGh("img/map/bg.png");

	//キャラ画像取り込み
	player1.setGh("img/Chara/Hansel/normal_half.png");
	//ルーレット画像読み込み
	roulette.setGh("img/board/roulette.png");
	//数字の背景
	numBg.setGh("img/board/numBg.png");

	//矢印画像
	arrow.setGh("img/board/arrowRight.png");

	srand((unsigned)time(NULL));//時間からランダム設定

	int z=0;

}

void GameBoardMain(){

	static int once=0;

	//初期化
	if(once==0){
		GameBoardInit();
		once=1;

	}
	GameBoardCal();
	GameBoardDraw();

	int z;


}


void GameBoardDraw(){


	//SetDrawArea(50,50,750,550 ) ;


	//背景表示

	bg.draw(255);

	//マス表示
	for(int i=map1.mapSI;i<map1.mapEI;i++){
		for(int j=map1.mapSJ;j<map1.mapEJ;j++){

			if(i==map1.nowRow && j==map1.nowCol){
				DrawGraph(
					map1.getLX()+map1.chipSizeX*j,
					map1.getUY()+map1.chipSizeY*i,

					map1.mapChipGH[ map1Data[i][j] ],
					1
					);


				int z=0;
			}else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA,200 ) ;
				DrawGraph(
					map1.getLX()+map1.chipSizeX*j,
					map1.getUY()+map1.chipSizeY*i,

					map1.mapChipGH[ map1Data[i][j] ],
					1
					);

				SetDrawBlendMode( DX_BLENDMODE_NOBLEND,255 ) ;


			}

		}
	}
	//方向選択の矢印表示
	if(rouletteMode==2){

		if(upDown.getNum()==0){

			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2-100,1.0,-90,0,255);//上
			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2+100,1.0,90,0,55);//下
		}
		else if(upDown.getNum()==1) {
			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2+100,1.0,90,0,255);//下
			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2-100,1.0,-90,0,55);//上
		}

	}



	//キャラ表示
	player1.draw2(player1.XinDisp+Char_Zure_X+20,player1.YinDisp,1.0,0,1);


	//ルーレット表示
	//roulette.draw2(player1.XinDisp+player1.getWidth()/2,70,1.0,0,0);


	//真ん中上の数字
	//数字の背景
	SetDrawBlendMode(DX_BLENDMODE_MULA,200 ) ;

	numBg.draw(350,0,200);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND,255 ) ;

	//数字表示
	DrawFormatStringToHandle(380,10,WHITE,digital82,"%d",rouletteNum);


	//	SetDrawArea(0,0,800,600 ) ;
	//デバッグ
	DrawFormatString(100,570,GetColor(255,255,255),"SJ:%d EJ:%d map1.mapSI,:%d map1.mapEI:%d,map1.startX:%d,map1.getDispLXinMap():%d",
		map1.mapSJ,
		map1.mapEJ,
		map1.mapSI,
		map1.mapEI,
		map1.startXinMap,
		map1.getDispLXinMap()

		);


}


void GameBoardCal(){

	


	//キーチェック　デバッグ用
	//if(key_Trg==keyLeft){	

	//	map1.setLX(map1.getLX()+map1.chipSizeX*2);
	//	map1.setDispLXinMap(map1.getDispLXinMap()-map1.chipSizeX*2);

	//	map1.nowCol-=2;
	//}
	//if(key_Trg==keyRight){

	//	map1.setLX(map1.getLX()-map1.chipSizeX*2);
	//	map1.setDispLXinMap(map1.getDispLXinMap()+map1.chipSizeX*2);

	//	map1.nowCol+=2;
	//}
	//if(key_Trg==keyDown){

	//	map1.setUY(map1.getUY()-map1.chipSizeX*2);
	//	map1.setDispUYinMap(map1.getDispUYinMap()+map1.chipSizeX*2);

	//	map1.nowRow+=2;
	//}
	//if(key_Trg==keyUp){

	//	map1.setUY(map1.getUY()+map1.chipSizeX*2);
	//	map1.setDispUYinMap(map1.getDispUYinMap()-map1.chipSizeX*2);

	//		map1.nowRow-=2;
	//}

	//描画してない部分を切る関数
	map1.calLoopStartEnd();
	//
	switch(rouletteMode){
	case 0://ルーレット受付
		GameBoardRoulette();
		break;
	case 1://ルーレット移動中（キャラ移動　キー受付なし）



		if(rouletteNum==0){			
			rouletteMode=0;//キーを受け付ける
		}
		else{
			moveCnt--;

			if(moveCnt<=0){
				if(map1DirData[map1.nowRow][map1.nowCol]==6){//方向が右だったら
					map1.setLX(map1.getLX()-map1.chipSizeX*2);
					map1.setDispLXinMap(map1.getDispLXinMap()+map1.chipSizeX*2);

					map1.nowCol+=2;
					rouletteNum--;

					moveCnt=moveSpd;

				}else if(map1DirData[map1.nowRow][map1.nowCol]==2){//方向が下だったら
					map1.setUY(map1.getUY()-map1.chipSizeX*2);
					map1.setDispUYinMap(map1.getDispUYinMap()+map1.chipSizeX*2);

					map1.nowRow+=2;
						rouletteNum--;

					moveCnt=moveSpd;

				}else if(map1DirData[map1.nowRow][map1.nowCol]==8){//方向が上だったら
				
				map1.setUY(map1.getUY()+map1.chipSizeX*2);
				map1.setDispUYinMap(map1.getDispUYinMap()-map1.chipSizeX*2);
				
					map1.nowRow-=2;
					rouletteNum--;
					moveCnt=moveSpd;
				
				
				}
				
				else if(map1DirData[map1.nowRow][map1.nowCol]==28){//方向が上下だったら
					rouletteMode=2;//ルーレットを受け付けない
				}
			}
		}
		break;
	case 2://選択モード

		static bool mvMode=0;
		upDown.calVer();

		if(mvMode==0){
			if(key_Trg==keyEnter)//エンターキーが押されたら
				mvMode=1;
			moveCnt=moveSpd;
		}else{

			moveCnt--;
			if(moveCnt<=0){

				if(upDown.getNum()==UP){//上だったら
					rouletteMode=1;//移動モードに移す
					map1.setUY(map1.getUY()+map1.chipSizeX*2);
					map1.setDispUYinMap(map1.getDispUYinMap()-map1.chipSizeX*2);

					map1.nowRow-=2;
					rouletteNum--;

					moveCnt=moveSpd;

					upDown.reset();


				}
				else if(upDown.getNum()==DOWN){
					rouletteMode=1;//移動モードに移す
					map1.setUY(map1.getUY()-map1.chipSizeX*2);
					map1.setDispUYinMap(map1.getDispUYinMap()+map1.chipSizeX*2);
					map1.nowRow+=2;


					rouletteNum--;

					moveCnt=moveSpd;


				}


			}
		}
		break;


	}



}

//ルーレット関数
void  GameBoardRoulette(){
	//カウント


	static int rouletteStartTime=100;
	static bool start=0;
	static int waitTime=6;//ルーレットが始まってから次にキーを受け付けるまでの時間
	static int waitCnt=waitTime;

	static int rouletteCnt=0;
	static int rouletteSpd=0;//ルーレットの回るスピード


	switch(start){
	case 0:
		if(key_Trg==keySpace){//スペースが押されたら
			start=1;
			rouletteSpd=rand()%3+2;//ランダムでルーレットスピード決定
			rouletteCnt=rouletteSpd;
		}


		break;
	case 1:
		rouletteCnt--;
		waitCnt--;
		if(rouletteCnt<=0){
			rouletteCnt=rouletteSpd;

			//ルーレットの数字を＋＋
			if(rouletteNum<6)
				rouletteNum++;
			else
				rouletteNum=1;
		}

		if(waitCnt<=0){
			//スペースが押されたら
			if(key_Trg==keySpace){
				waitCnt=waitTime;
				start=0;//止める

				rouletteMode=1;//ルーレットモード終了
			}		
		}
		break;
	}

}






