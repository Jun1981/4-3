#include "StageSelect.h"
#include "GameMain.h"
#include "C_TableMenu.h"
#include "Image.h"
#include "Fonts.h"
C_TableMenu *stgMenu;

#include "key.h"


//enum�^
	DIFF diff;


//���O���
namespace stgSel{
	//�N���X�錾
	Image bg;//�w�i
	Image cursor;//�J�[�\��
	Image fairy;//�d���C���[�W
	Image fukidashi;//�����o���摜�N���X
	Image board;//�g�i�E�㕶���w�i�j�N���X
	Fonts fonts;//�t�H���g�N���X

	



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


	

	//�t�H���g�n
	fonts.loadFont("Fonts/uzura.ttf");

	ChangeFont( "������t�H���g", DX_CHARSET_DEFAULT );


	stgMenu=new C_TableMenu(1,3,700,100,30,200,0);

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
	
	board.setGh("./img/Object/waku.png");
	board.setXY(660,90);





	int z;

}

void StgSelDraw(){
	//�w�i�\��
	bg.draw(255);

	//���\��
	SetFontSize(60);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��
	


	if(stgMenu->getNum()==0)stgMenu->draw(0,0,255);
	else stgMenu->draw(0,0,155);
	DrawFormatString(stgMenu->getTableX(0,0)+80,stgMenu->getTableY(0,0)+310,BLACK,"����");

	if(stgMenu->getNum()==1)stgMenu->draw(0,1,255);
	else stgMenu->draw(0,1,155);
	DrawFormatString(stgMenu->getTableX(0,1)+85,stgMenu->getTableY(0,1)+310,BLACK,"����");

	if(stgMenu->getNum()==2)	stgMenu->draw(0,2,255);
	else stgMenu->draw(0,2,155);
	DrawFormatString(stgMenu->getTableX(0,2)+85,stgMenu->getTableY(0,2)+310,BLACK,"�㋉");


	//�d���\��
	fairy.draw2(0.25,0,255);
	//�����o���\��
	fukidashi.draw2(0.65,0,255);

	//�����o�����̕���
	static int fukidashiMojiX=fukidashi.getX()-116;

	SetFontSize(24);
	if(stgMenu->getNum()==0){
		DrawString( fukidashiMojiX , fukidashi.getY()-30, "���߂Ă̐l�͂����I", GetColor( 0 , 0 , 0 ) );//����
	DrawString( fukidashiMojiX , fukidashi.getY()-30+32, "3�K���ẴX�e�[�W�ł��B", GetColor( 0 , 0 , 0 ) );//����
	}
	
	if(stgMenu->getNum()==1){
	DrawString( fukidashiMojiX , fukidashi.getY()-30, "�����Ɋ���Ă����炱���I", GetColor( 0 , 0 , 0 ) );//����
	DrawString( fukidashiMojiX , fukidashi.getY()-30+32, "5�K���ẴX�e�[�W�ł��B", GetColor( 0 , 0 , 0 ) );//����
	}
	if(stgMenu->getNum()==2){
	DrawString( fukidashiMojiX , fukidashi.getY()-30, "���M������l�͂����I", GetColor( 0 , 0 , 0 ) );//����
	DrawString( fukidashiMojiX , fukidashi.getY()-30+32, "8�K���ẴX�e�[�W�ł��B", GetColor( 0 , 0 , 0 ) );//����
	}
	
	//�g�\��
	board.draw2(0.5,0,255);
	//�g������
	DrawString( board.getX()-80 , board.getY()-30, "���E�� �I��",GetColor( 255 ,255 ,255 ) );//����
	DrawString( board.getX()-80 , board.getY()+10, "Enter  ����", GetColor( 255 ,255 ,255 ) );//����



	
	//�J�[�\���`��
	cursor.setXY(stgMenu->getNowCurX()+60,stgMenu->getNowCurY());
	cursor.draw2(0.2,90,255);



}

void StgSelCal(){
	
	stgMenu->calHori();//�J�[�\������
	//�����̏�ɃJ�[�\������������
	if(stgMenu->getNum()==0){

		if(key_Trg==0x100){//�G���^�[�L�[�������ꂽ��
			diff=easy;//��Փx�ϐ��ݒ�

			Game.mode=3;//�L�����Z���N�g��ʂ�
			StgSelFinalize();//�I������

		}

	}
}

//�I������
void StgSelFinalize(){

	delete stgMenu;
	//stgMenu->Finalize();
}