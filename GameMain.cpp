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



Fonts fonts;//フォントクラス

int Uzura16;
int Uzura20;
int Uzura24;
int Uzura30;
int Uzura60;



void GameMain(){


	key_chk();//キーチェック


	switch(Game.mode){
	case 0://初期化


		
	//フォント系
	fonts.loadFont("Fonts/uzura.ttf");
	//フォント作成
	 Uzura16= CreateFontToHandle( "うずらフォント",16,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	 Uzura20= CreateFontToHandle( "うずらフォント",20,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	 	 Uzura24= CreateFontToHandle( "うずらフォント",24,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	  Uzura30= CreateFontToHandle( "うずらフォント",30,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;
	 Uzura60= CreateFontToHandle( "うずらフォント",60,-1,DX_FONTTYPE_ANTIALIASING_4X4) ;

	/* fonts.crtFHndl(24,"うずらフォント");
	 fonts.crtFHndl(60,"うずらフォント");*/

		

		


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

	case 4://マップ
			//DrawString(300,400,"キャラセレクト",GetColor(255,255,255),0);

		//DrawStringToHandle(300,400,"マップ",GetColor(255,255,255),Uzura24);


		GameBoardMain();


		break;

	}
}

