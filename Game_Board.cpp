#include "C_MAP.h"
#include "Game_Board.h"
#include "../DxLib/DxLib.h"

#include "C_GameSettings.h"
#include "Image.h"


#include "C_Character.h"
#include "key.h"


#include "map1.h"

C_MAP map1; //�N���X�錾


#define Char_Zure_Y 0
#define Char_Zure_X 48

namespace Board{

Image bg;
C_Character player1;
};


using namespace Board;



void GameBoardInit(){
	map1.setResoXY(Game.getResoX(),Game.getResoY());//�𑜓x�ݒ�
	map1.setMapChipSize(100,100);
	map1.setMapRowCol(21,60);
	map1.setMapDataArray(map1.row,map1.col);

	//�}�b�v�X�^�[�g�n�_�v�Z
	for(int i=0;i<21;i++){
		for(int j=0;j<60;j++){
			if(map1EvtData[i][j]==11){
			  
				map1.setStartXYinMap(map1.chipSizeX*j,map1.chipSizeY*i);
				
				map1.setLX(Game.getResoX()/2-map1.chipSizeX/2-map1.startXinMap);
				map1.setUY(Game.getResoY()/2-map1.chipSizeY/2-map1.startYinMap);

				map1.setDispLXinMap(-1*map1.getLX());
				map1.setDispUYinMap(-1*map1.getUY());
			goto LoopOut;
				
			}
		
		}
	}
	LoopOut://���[�v�����p



	map1.loadMapChip("img/map/mapChip.png",13,1);


	//�v���C���[�P�̉摜�T�C�Y�ݒ�
	player1.setSizeXY(150,160);
	//�v���C���[�P�̂������ʒu�i��ʓ��j�ݒ�
	player1.SetXYinDisp(
		Game.getResoX()/2-player1.getWidth()/2,
		Game.getResoY()/2-player1.getHeight()/2
		);
		

	//�v���C���[�̉�
	
	//�w�i�摜��荞��
	bg.setGh("img/map/bg.png");
		

	//�L�����摜��荞��
	player1.setGh("img/Chara/Hansel/normal_half.png");
	
	int z=0;

}

void GameBoardMain(){

	static int once=0;

	//������
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
	

	//�w�i�\��

	bg.draw(255);

	//�}�X�\��
	for(int i=map1.mapSI;i<map1.mapEI;i++){
		for(int j=map1.mapSJ;j<map1.mapEJ;j++){


			DrawGraph(
				map1.getLX()+map1.chipSizeX*j,
				map1.getUY()+map1.chipSizeY*i,
			
				map1.mapChipGH[ map1Data[i][j] ],
				1
				);


			int z=0;
		}
	}


	//�L�����\��

	player1.draw2(player1.XinDisp+Char_Zure_X,player1.YinDisp,1.0,0,1);


//	SetDrawArea(0,0,800,600 ) ;
	//�f�o�b�O
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
	
		map1.calLoopStartEnd();

}








