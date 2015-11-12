#include "C_GameSettings.h"


#include "../DxLib/DxLib.h"

#include "Title.h"
#include "key.h"
#include "Title.h"
#include "StageSelect.h"

#include "Debug.h"


#include "CharaSelect.h"

#include "C_MAP.h"
#include "Game_Board.h"



Fonts fonts;//�t�H���g�N���X

int Uzura16;
int Uzura20;
int Uzura24;
int Uzura30;
int Uzura60;



void GameMain(){


	key_chk();//�L�[�`�F�b�N


	switch(Game.mode){
	case 0://������


		
	//�t�H���g�n
	fonts.loadFont("Fonts/uzura.ttf");
	//�t�H���g�쐬
	 Uzura16= CreateFontToHandle( "������t�H���g",16,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	 Uzura20= CreateFontToHandle( "������t�H���g",20,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	 	 Uzura24= CreateFontToHandle( "������t�H���g",24,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	  Uzura30= CreateFontToHandle( "������t�H���g",30,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	 Uzura60= CreateFontToHandle( "������t�H���g",60,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;

	/* fonts.crtFHndl(24,"������t�H���g");
	 fonts.crtFHndl(60,"������t�H���g");*/

		

		


		Game.mode=1;//�X�e�[�W�Z���N�g��
		break;
	case 1://�^�C�g��


		TitleMain();

		//Debug();
	//	int z;

		break;

	case 2://�X�e�[�W�Z���N�g

		StgSelMain();

		
		break;
	case 3://�L�����Z���N�g
		
		charSelMain();
		//DrawString(300,400,"�L�����Z���N�g",GetColor(255,255,255),0);


		break;

	case 4://�}�b�v
			//DrawString(300,400,"�L�����Z���N�g",GetColor(255,255,255),0);

		//DrawStringToHandle(300,400,"�}�b�v",GetColor(255,255,255),Uzura24);


		GameBoardMain();


		break;

	}
}

