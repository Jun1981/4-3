#include "C_GameMain.h"

#include "../DxLib/DxLib.h"

#include "Title.h"
#include "key.h"
#include "Title.h"
#include "StageSelect.h"

#include "Debug.h"

#include "CharaSelect.h"


C_GameMain Game;

void GameMain(){



	key_chk();//�L�[�`�F�b�N


	switch(Game.mode){
	case 0://������

		//TitleInit();
		//StgSelInit();

		//Game.mode=1;//�^�C�g����
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

	}
}

