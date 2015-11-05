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



	key_chk();//キーチェック


	switch(Game.mode){
	case 0://初期化

		//TitleInit();
		//StgSelInit();

		//Game.mode=1;//タイトルへ
		Game.mode=1;//ステージセレクトへ
		break;
	case 1://タイトル


		TitleMain();

		//Debug();
	//	int z;

		break;

	case 2://ステージセレクト

		StgSelMain();

		
		break;
	case 3://キャラセレクト
		
		charSelMain();
		//DrawString(300,400,"キャラセレクト",GetColor(255,255,255),0);


		break;

	}
}

