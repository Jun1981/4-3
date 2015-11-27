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


C_MAP map1; //�N���X�錾


#define Char_Zure_Y 0
#define Char_Zure_X 48

C_TableMenu upDown(2,1,C_TableMenu::ver);//���j���[�N���X
namespace Board{

	C_Character player1;


	//�摜�N���X
	Image bg;

	Image roulette;//���[���b�g�摜
	Image finger;//�w�摜
	Image numBg;//
	Image arrow;//���摜�N���X

	Fonts Digital;



	enum ARROW{
		UP=0,
		DOWN=1
	};

};using namespace Board;

int digital30;//�t�H���g�n���h��p
int digital82;//�t�H���g�n���h��p�U�O

int rouletteNum=1;//���[���b�g�̐���(1~6)

int arrowDir=UP;//���̃f�t�H���g

static int rouletteMode=0;//���[���b�g���[�h�@�i�O�F���������߂�@�P�F�ړ��@�Q�F����I���j

//static int moveWaitTime=30;


static int moveSpd=30;
	static int moveCnt=moveSpd;




void GameBoardInit(){
	map1.setResoXY(Game.getResoX(),Game.getResoY());//�𑜓x�ݒ�
	map1.setMapChipSize(100,100);
	map1.setMapRowCol(21,60);
	map1.setMapDataArray(map1.row,map1.col);


	//�}�b�v�X�^�[�g�n�_�v�Z
	for(int i=0;i<21;i++){
		for(int j=0;j<60;j++){
			if(map1EvtData[i][j]==11){			

				map1.nowRow=i;map1.nowCol=j;
				map1.setStartXYinMap(map1.chipSizeX*j,map1.chipSizeY*i-100);			
				goto LoopOut;
			}		
		}
	}
LoopOut://���[�v�����p


	//�t�H���g�ǂݍ���
	Digital.loadFont("fonts/Let's go Digital Regular.ttf");
	//�t�H���g�쐬

	digital30= CreateFontToHandle( "Let's go Digital Regular",30,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	digital82= CreateFontToHandle( "Let's go Digital Regular",82,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;



	map1.loadMapChip("img/map/mapChip.png",13,1);


	//�v���C���[�P�̉摜�T�C�Y�ݒ�
	player1.setSizeXY(150,160);
	//�v���C���[�P�̂������ʒu�i��ʓ��j�ݒ�
	player1.SetXYinDisp(
		Game.getResoX()/2-player1.getWidth()/2,

		Game.getResoY()/2-player1.getHeight()/2+100
		);


	//�v���C���[�̉�

	//�w�i�摜��荞��
	bg.setGh("img/map/bg.png");

	//�L�����摜��荞��
	player1.setGh("img/Chara/Hansel/normal_half.png");
	//���[���b�g�摜�ǂݍ���
	roulette.setGh("img/board/roulette.png");
	//�����̔w�i
	numBg.setGh("img/board/numBg.png");

	//���摜
	arrow.setGh("img/board/arrowRight.png");

	srand((unsigned)time(NULL));//���Ԃ��烉���_���ݒ�

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
	//�����I���̖��\��
	if(rouletteMode==2){

		if(upDown.getNum()==0){

			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2-100,1.0,-90,0,255);//��
			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2+100,1.0,90,0,55);//��
		}
		else if(upDown.getNum()==1) {
			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2+100,1.0,90,0,255);//��
			arrow.draw2(player1.XinDisp+200,player1.YinDisp+player1.getHeight()/2-100,1.0,-90,0,55);//��
		}

	}



	//�L�����\��
	player1.draw2(player1.XinDisp+Char_Zure_X+20,player1.YinDisp,1.0,0,1);


	//���[���b�g�\��
	//roulette.draw2(player1.XinDisp+player1.getWidth()/2,70,1.0,0,0);


	//�^�񒆏�̐���
	//�����̔w�i
	SetDrawBlendMode(DX_BLENDMODE_MULA,200 ) ;

	numBg.draw(350,0,200);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND,255 ) ;

	//�����\��
	DrawFormatStringToHandle(380,10,WHITE,digital82,"%d",rouletteNum);


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

	


	//�L�[�`�F�b�N�@�f�o�b�O�p
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

	//�`�悵�ĂȂ�������؂�֐�
	map1.calLoopStartEnd();
	//
	switch(rouletteMode){
	case 0://���[���b�g��t
		GameBoardRoulette();
		break;
	case 1://���[���b�g�ړ����i�L�����ړ��@�L�[��t�Ȃ��j



		if(rouletteNum==0){			
			rouletteMode=0;//�L�[���󂯕t����
		}
		else{
			moveCnt--;

			if(moveCnt<=0){
				if(map1DirData[map1.nowRow][map1.nowCol]==6){//�������E��������
					map1.setLX(map1.getLX()-map1.chipSizeX*2);
					map1.setDispLXinMap(map1.getDispLXinMap()+map1.chipSizeX*2);

					map1.nowCol+=2;
					rouletteNum--;

					moveCnt=moveSpd;

				}else if(map1DirData[map1.nowRow][map1.nowCol]==2){//����������������
					map1.setUY(map1.getUY()-map1.chipSizeX*2);
					map1.setDispUYinMap(map1.getDispUYinMap()+map1.chipSizeX*2);

					map1.nowRow+=2;
						rouletteNum--;

					moveCnt=moveSpd;

				}else if(map1DirData[map1.nowRow][map1.nowCol]==8){//�������ゾ������
				
				map1.setUY(map1.getUY()+map1.chipSizeX*2);
				map1.setDispUYinMap(map1.getDispUYinMap()-map1.chipSizeX*2);
				
					map1.nowRow-=2;
					rouletteNum--;
					moveCnt=moveSpd;
				
				
				}
				
				else if(map1DirData[map1.nowRow][map1.nowCol]==28){//�������㉺��������
					rouletteMode=2;//���[���b�g���󂯕t���Ȃ�
				}
			}
		}
		break;
	case 2://�I�����[�h

		static bool mvMode=0;
		upDown.calVer();

		if(mvMode==0){
			if(key_Trg==keyEnter)//�G���^�[�L�[�������ꂽ��
				mvMode=1;
			moveCnt=moveSpd;
		}else{

			moveCnt--;
			if(moveCnt<=0){

				if(upDown.getNum()==UP){//�ゾ������
					rouletteMode=1;//�ړ����[�h�Ɉڂ�
					map1.setUY(map1.getUY()+map1.chipSizeX*2);
					map1.setDispUYinMap(map1.getDispUYinMap()-map1.chipSizeX*2);

					map1.nowRow-=2;
					rouletteNum--;

					moveCnt=moveSpd;

					upDown.reset();


				}
				else if(upDown.getNum()==DOWN){
					rouletteMode=1;//�ړ����[�h�Ɉڂ�
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

//���[���b�g�֐�
void  GameBoardRoulette(){
	//�J�E���g


	static int rouletteStartTime=100;
	static bool start=0;
	static int waitTime=6;//���[���b�g���n�܂��Ă��玟�ɃL�[���󂯕t����܂ł̎���
	static int waitCnt=waitTime;

	static int rouletteCnt=0;
	static int rouletteSpd=0;//���[���b�g�̉��X�s�[�h


	switch(start){
	case 0:
		if(key_Trg==keySpace){//�X�y�[�X�������ꂽ��
			start=1;
			rouletteSpd=rand()%3+2;//�����_���Ń��[���b�g�X�s�[�h����
			rouletteCnt=rouletteSpd;
		}


		break;
	case 1:
		rouletteCnt--;
		waitCnt--;
		if(rouletteCnt<=0){
			rouletteCnt=rouletteSpd;

			//���[���b�g�̐������{�{
			if(rouletteNum<6)
				rouletteNum++;
			else
				rouletteNum=1;
		}

		if(waitCnt<=0){
			//�X�y�[�X�������ꂽ��
			if(key_Trg==keySpace){
				waitCnt=waitTime;
				start=0;//�~�߂�

				rouletteMode=1;//���[���b�g���[�h�I��
			}		
		}
		break;
	}

}






