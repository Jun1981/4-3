
#include "../DxLib/DxLib.h"

#include "C_FreeMenu.h"
#include "Image.h"
#include "Title.h"

#include "key.h"
#include "GameMain.h"

 C_FreeMenu tMenu(1,2,0);
Image bal[2];//���D�@�摜�N���X����
Image bg[1];//�w�i


void TitleMain(){
	
	static int initFlag=0;
	if(initFlag==0){
		TitleInit();
		initFlag=1;
	}
	TitleCal();
	TitleDraw();

	//�`��

	//int z=0;
}


//�^�C�g��������

void TitleInit(){
	//�摜�ǂݍ���

	//�ʒu�ݒ�
	bal[0].setInitXY(150,100);
	bal[1].setInitXY(500,100);

	bal[0].setGh("./img/title/NewGame.png");
	bal[1].setGh("./img/title/EndGame.png");
	bg[0].setGh("./img/title/bg.png");



}


//�^�C�g���v�Z
void TitleCal(){
	tMenu.calHori();

	if(tMenu.getNum()==0){
		if(key_Trg==0x100){
			Game.mode=2;//�X�e�[�W�Z���N�g��
			tMenu.Finalize();
		}
	}

	if(tMenu.getNum()==1){
		if(key_Trg==0x100){
			exit(0);//�X�e�[�W�Z���N�g��
		tMenu.Finalize();
		}
	}

}
//�^�C�g���`��
void TitleDraw(){

	bg[0].draw(255);//�w�i�`��

	if(tMenu.num==0){
		bal[0].draw(255);//�o���[���O�`��
		bal[1].draw(155);//�o���[���P�`��
	}
	else{ 
		bal[0].draw(155);//�o���[���O�`��
		bal[1].draw(255);//�o���[���P�`��
	}


}