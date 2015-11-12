#include "C_MAP.h"
#include "Game_Board.h"
#include "../DxLib/DxLib.h"

#include "C_GameSettings.h"

#include "key.h"

C_MAP map1; //クラス宣言

int mapData1[21][60]={
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,1,6,1,6,1,255,255,255,255,255,255,255,255,255,255,255,255,255,1,6,2,6,1,6,3,6,1,6,1,6,1,6,3,6,1,6,1,6,1,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255													   ,
	255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,8,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255		   ,
	255,255,255,255,255,255,1,255,255,255,3,6,1,6,2,6,1,6,1,6,4,255,255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,2,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255							   ,
	255,255,255,255,255,255,7,255,255,255,7,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255		   ,
	255,255,255,255,255,255,3,255,255,255,1,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,1,6,1,6,2,6,1,6,1,255,255,255,255,255,255,255,255,255,255,255						   ,
	255,255,255,255,255,255,7,255,255,255,7,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255		   ,
	255,255,255,255,255,255,1,255,255,255,1,255,255,255,255,255,255,255,255,255,1,6,3,6,2,6,1,6,2,6,1,6,4,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,255,255,255,255								   ,
	255,255,255,255,255,255,7,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,9,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,9,255,255,255,255,255,255,255,255,255,255,255		   ,
	255,255,255,255,255,255,1,6,1,6,1,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,1,6,1,6,1,6,2,6,1,6,3,6,2,6,1,6,2,6,1,6,1,6,2,6,3,6,2,6,11,255																   ,
	255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,8,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,8,255,255,255,255,255,255,255,255,255,255,255	   ,
	255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,255,255,2,6,1,6,1,6,3,6,1,6,2,6,4,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,255,255,255,255							   ,
	255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255		   ,
	255,255,255,255,255,255,255,255,255,255,2,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,1,6,1,6,2,6,1,6,1,255,255,255,255,255,255,255,255,255,255,255						   ,
	255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255		   ,
	255,255,255,255,255,255,255,255,255,255,1,6,1,6,3,6,1,6,1,6,4,255,255,255,255,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,1,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255						   ,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,9,255,255,255,255,255,255,255,7,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255	   ,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,1,6,1,6,3,6,1,6,2,6,1,6,1,6,3,6,1,6,2,6,1,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255										   ,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
};


void GameBoardInit(){
	map1.setMapChipSize(100,100);
	map1.setMapRowCol(21,60);
	map1.setMapDataArray(map1.row,map1.col);


	map1.loadMapChip("img/map/mapChip.jpg",11,1);

	//map1.setDispWH(Game.getResoX(),Game.getResoY());//描画域解像度取得
	map1.setDispWH(800,600);//ディスプレイ解像度取得
	map1.setDispXY(0,0);




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

	

	

	for(int i=map1.mapSI;i<map1.mapEI;i++){
		for(int j=map1.mapSJ;j<map1.mapEJ;j++){


			DrawGraph(
				map1.getLX()+j*map1.chipSizeX,
				map1.getUY()+map1.chipSizeY*i,
				map1.mapChipGH[ mapData1[i][j] ],
				1
				);


			int z=0;
		}
	}
	//デバッグ
	DrawFormatString(300,400,GetColor(255,255,255),"SJ:%d EJ:%d map1.mapSI,:%d map1.mapEI:%d",
		map1.mapSJ,
		map1.mapEJ,
		map1.mapSI,
		map1.mapEI
	);


}


void GameBoardCal(){

	if(key_Info==keyLeft){	

		map1.setLX(map1.getLX()+20);
		map1.setDispLXinMap(map1.getDispLXinMap()-20);
	}
	if(key_Info==keyRight){

		map1.setLX(map1.getLX()-20);
		map1.setDispLXinMap(map1.getDispLXinMap()+20);
	}
	if(key_Info==keyDown){

		map1.setUY(map1.getUY()-20);
		map1.setDispUYinMap(map1.getDispUYinMap()+20);
	}
	if(key_Info==keyUp){

		map1.setUY(map1.getUY()+20);
		map1.setDispUYinMap(map1.getDispUYinMap()-20);
	}



	//節約用　ループスタートと終わりの設定
	//if(map1.getDispUYinMap()>=0){//上端
	//	map1.mapSI=map1.getDispUYinMap()/map1.chipSizeY;
	//}
	//else{ map1.mapSI=0; }


	//if(map1.getDispLXinMap()>=0){//左端
	//	map1.mapSJ=map1.getDispLXinMap()/map1.chipSizeX;
	//}
	//else{map1.mapSJ=0;}

	//if(map1.getDispDYinMap()<map1.chipSizeY*map1.row) {//下端
	//	
	//	map1.mapEI=map1.row-
	//		(map1.chipSizeY*map1.row-map1.getDispDYinMap())
	//		/map1.chipSizeY+1;

	//}else {map1.mapEI=map1.row;}
	//
	//if( map1.getDispRXinMap()<map1.chipSizeX*map1.col) {//右端
	//	map1.mapEJ=	map1.col-	
	//		(map1.chipSizeX*map1.col-map1.getDispRXinMap())/map1.chipSizeX ;
	//}else{ map1.mapEJ=map1.col;}
	map1.calLoopStartEnd();
	

}








