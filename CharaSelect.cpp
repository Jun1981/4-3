#include "CharaSelect.h"
#include "Image.h"
#include "key.h"
#include "GameMain.h"
#include "StageSelect.h"

#include "../DxLib/DxLib.h"

C_TableMenu *charSelMenu;

namespace charSel{
 Image bg;//�w�i�N���X�錾
 Image cursor;//�J�[�\���摜

}
using namespace charSel;


void charSelMain(){
	static int initFlag=0;
	if(initFlag==0){
		charSelInit();
		initFlag=1;
	}

	//�v�Z
	charSelCal();

	//�`��
	 charSelDraw();



}

//������
void charSelInit(){

	//���j���[�N���X�Ƀ������m��
	charSelMenu=new C_TableMenu(1,4,700,100,135,400,0);
	////////////////

	ChangeFont( "������t�H���g", DX_CHARSET_DEFAULT );
	//�摜�ǂݍ���
	//�w�i
	bg.setGh("./img/StageSelect/bg1.png");//�w�i�摜

	//�L����
	charSelMenu->setTableGh(0,0,"img/Chara/Hansel/normal.png");//�w���[��
	charSelMenu->setTableGh(0,1,"img/Chara/Gretel/normal.png");//�O���[�e��
	charSelMenu->setTableGh(0,2,"img/Chara/Roove/normal.png");//���[��
	charSelMenu->setTableGh(0,3,"img/Chara/Puss/normal.png");//�v�V�[

	//�J�[�\���摜�ǂݍ���
	cursor.setGh("./img/cursor/finger1.png");//�J�[�\���摜

	

	


	int z=0;
	
	
	




}


void charSelCal(){	

	charSelMenu->calHori();//�J�[�\������
	if(charSelMenu->getNum()==0){
		if(key_Trg==0x100){
			//Game.mode=4;//�Z���N�g��ʂ�
			//StgSelFinalize();//�I������
		}	
	}

}

void charSelDraw(){

	
//�`��
	//�w�i
	bg.draw(255);
	//�L����
	for(int i=0;i<4;i++){
	charSelMenu->draw2(0,i,0.5,0,255);
		
	}

//�����`��

	//�L�����l�[��
	SetFontSize(30);	// ���₷���̂��߁A�t�H���g�T�C�Y��傫��
	DrawFormatString(charSelMenu->getTableX(0,0)-60,charSelMenu->getTableY(0,0)+100,BLACK,"�w���[��");
	DrawFormatString(charSelMenu->getTableX(0,1)-70,charSelMenu->getTableY(0,0)+100,BLACK,"�O���[�e��");
	DrawFormatString(charSelMenu->getTableX(0,2)-40,charSelMenu->getTableY(0,0)+100,BLACK,"���[��");
	DrawFormatString(charSelMenu->getTableX(0,3)-40,charSelMenu->getTableY(0,0)+100,BLACK,"�v�V�[");

	//�����Փx�@�\��

	  if(diff==easy)DrawFormatString(50,50,WHITE,"���񂽂�");






	//�J�[�\���`��
	cursor.setXY(charSelMenu->getNowCurX()-80,charSelMenu->getNowCurY()-30);
	cursor.draw2(0.2,90,255);



	







}