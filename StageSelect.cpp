
#include "common.h"

#include "StageSelect.h"
#include "C_GameSettings.h"
#include "C_TableMenu.h"
#include "Image.h"
#include "Fonts.h"
#include "C_ScrollLine.h"


#include <new>

C_TableMenu *stgMenu;

#include "key.h"
//static C_ScrollLine SLine(2,32);

static C_ScrollLine sLine[3];



//new(& (sLine[0]) )C_ScrollLIne(2,32);

//enum�^



//���O���
namespace stgSel{
	//�N���X�錾
	Image bg;//�w�i
	Image cursor;//�J�[�\��
	Image fairy;//�d���C���[�W
	Image fukidashi;//�����o���摜�N���X
	Image board;//�g�i�E�㕶���w�i�j�N���X

	
}
using namespace stgSel;

//���C��
void StgSelMain(){
	static int initFlag=0;

	if(initFlag==0){
		StgSelInit();
		initFlag=1;
	}


	StgSelDraw();
	StgSelCal();
}

//������
void StgSelInit(){
		stgMenu=new C_TableMenu(1,3,700,100,30,200,0);



	
	//ChangeFont( "������t�H���g", DX_CHARSET_DEFAULT );



		




	//�t�H���g�n
	//uzura.loadFont("Fonts/uzura.ttf");
	//�t�H���g�쐬
	/* Uzura24= CreateFontToHandle( "������t�H���g",24,1,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
	 Uzura60= CreateFontToHandle( "������t�H���g",60,1,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;*/

	 /*uzura.crtFHndl(24,"������t�H���g");
	 uzura.crtFHndl(60,"������t�H���g");*/
	
	 

	//C_TableMenu stgMenu(1,3,400,50,100,400,0);
	//�摜�ǂݍ���
	bg.setGh("./img/StageSelect/bg1.png");//�w�i�摜
	cursor.setGh("./img/cursor/finger1.png");//�J�[�\���摜
	fairy.setGh("./img/object/pixy.png");//�d���摜
	fukidashi.setGh("./img/object/fukidashi2.png");//�����o���摜

	//cursor.setInitXY(stgMenu->getTableX(),stgMenu->getTableY(),250);
	//���摜�ǂݍ���
	stgMenu->setTableGh(0,0,"./img/StageSelect/tower1.png");
	stgMenu->setTableGh(0,1,"./img/StageSelect/tower2.png");
	stgMenu->setTableGh(0,2,"./img/StageSelect/tower3.png");

	//stgMenu->setNowTabXY();

	fairy.setInitXY(100,140);//�d���̏����摜�ݒ�

	fukidashi.setInitXY(320,110);//�����o���̉摜���W�����ݒ�


	//�E��̍���
	board.setGh("./img/Object/waku.png");
	board.setXY(660,90);


	//�����������

	//���[�̕��D
		sLine[0].setString(0,"���߂Ă̐l�͂����I");
		sLine[0].setString(1,"�R�K���ẴX�e�[�W�ł��B");
	//�^�񒆂̕��D
		sLine[1].setString(0,"�����Ɋ���Ă����炱���I");
		sLine[1].setString(1,"�T�K���ẴX�e�[�W�ł��B");
	//�E�[�̕��D
		sLine[2].setString(0,"���M������l�͂����I");
		sLine[2].setString(1,"�W�K���ẴX�e�[�W�ł��B");
	

		


	int z;

}

void StgSelDraw(){


	//�w�i�\��
	bg.draw(255);

	//���\��
	//SetFontSize(60);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��


	if(stgMenu->getNum()==0)stgMenu->draw(0,0,255);
	else stgMenu->draw(0,0,155);
	//DrawFormatString(stgMenu->getTableX(0,0)+80,stgMenu->getTableY(0,0)+310,BLACK,"����");
	DrawStringToHandle(stgMenu->getTableX(0,0)+80,stgMenu->getTableY(0,0)+310,"����",BLACK,Uzura60);

	if(stgMenu->getNum()==1)stgMenu->draw(0,1,255);
	else stgMenu->draw(0,1,155);
	//DrawFormatString(stgMenu->getTableX(0,1)+85,stgMenu->getTableY(0,1)+310,BLACK,"����");
	DrawStringToHandle(stgMenu->getTableX(0,1)+85,stgMenu->getTableY(0,1)+310,"����",BLACK,Uzura60);
	
	if(stgMenu->getNum()==2)	stgMenu->draw(0,2,255);
	else stgMenu->draw(0,2,155);
	//DrawFormatString(stgMenu->getTableX(0,2)+85,stgMenu->getTableY(0,2)+310,BLACK,"�㋉");
	DrawStringToHandle(stgMenu->getTableX(0,2)+85,stgMenu->getTableY(0,2)+310,"�㋉",BLACK,Uzura60);


	//�d���\��
	fairy.draw2(0.5,0,255);
	//�����o���\��
	  SetDrawBlendMode(DX_BLENDMODE_MULA , 220 );
	fukidashi.draw2(0.65,0,255);
	  SetDrawBlendMode(DX_BLENDMODE_NOBLEND , 255 ) ;

	//�����o�����̕�����X���W
	static int fukidashiMojiX=fukidashi.getX()-116;

	//SetFontSize(24);
	static int L=0;
	
	//�����o�����̕���
	if(stgMenu->getNum()==0)sLine[0].scrollLine(fukidashiMojiX, fukidashi.getY()-30,Uzura24,WHITE);	
	if(stgMenu->getNum()==1)sLine[1].scrollLine(fukidashiMojiX, fukidashi.getY()-30,Uzura24,WHITE);	
	if(stgMenu->getNum()==2)sLine[2].scrollLine(fukidashiMojiX, fukidashi.getY()-30,Uzura24,WHITE);	
	

	//�g�\��
	 SetDrawBlendMode(DX_BLENDMODE_MULA , 120 );
	board.draw2(0.5,0,255);
	  SetDrawBlendMode(DX_BLENDMODE_NOBLEND , 255 ) ;
	//�g������
	//DrawString( board.getX()-80 , board.getY()-30, "���E�� �I��",GetColor( 255 ,255 ,255 ) );//����
	//DrawString( board.getX()-80 , board.getY()+10, "Enter  ����", GetColor( 255 ,255 ,255 ) );//����

	DrawStringToHandle(board.getX()-80,board.getY()-30,   "���E���@�I��",WHITE,Uzura24);
	DrawStringToHandle(board.getX()-75 , board.getY()+10, "Enter�@����",WHITE,Uzura24);



	//�J�[�\���`��
	cursor.setXY(stgMenu->getNowCurX()+60,stgMenu->getNowCurY());
	cursor.draw2(0.2,90,255);
	
	int z=0;
	
}

void StgSelCal(){

	stgMenu->calHori();//�J�[�\������
	//�����̏�ɃJ�[�\������������
	if(stgMenu->getNum()==0){

		if(key_Trg==0x100){//�G���^�[�L�[�������ꂽ��
			Game.diff=easy;//��Փx�ϐ��ݒ�


			Game.mode=3;//�L�����Z���N�g��ʂ�
			StgSelFinalize();//�I������

		}

	}else sLine[0].resetLine();
	
	if(stgMenu->getNum()==1){}
	else  sLine[1].resetLine();

	if(stgMenu->getNum()==2){}
	else  sLine[2].resetLine();
	
}

//�I������
void StgSelFinalize(){

	delete stgMenu;
	//stgMenu->Finalize();
}