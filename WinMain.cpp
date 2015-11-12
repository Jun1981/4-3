
#include "../DxLib/dxlib.h"
#include "C_GameSettings.h"

#include "C_GameSettings.h"




////#include "Title.h"

//#include "key.h"


C_GameSettings Game;

void GameMain();//前方宣言

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
		
	//
	
	Game.setResoXY(800,600);//解像度登録
	
	
	//解像度とウィンドウモード
	ChangeWindowMode(TRUE);                     // ウインドウモードに変更(ただし、２５６色)
	SetGraphMode(Game.getResoX(),Game.getResoY(),32);//画面解像度とカラービット数設定
	

	if (DxLib_Init() == -1) {                    // ＤＸライブラリ初期化処理
		return -1;                              // エラーが起きたら直ちに終了
	}

	//キーチェック

	/*
*/
	 ////////////////////////
	
	
	
	SetDrawScreen(DX_SCREEN_BACK);              // 描画先を裏画面へ


	
	

	//------ ゲームループ ------//
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) { // Escキーが押されるまでループ
		ClsDrawScreen();                        // 裏画面クリア


		// こっから書く
		
		//
	GameMain();
	
		///////////////////////

		ScreenFlip();                           // 裏画面を表画面へ
		if (ProcessMessage() == -1) {            // メッセージ処理
			break;                              // エラーが起きたらループから抜ける
		}
	}
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;// アプリケーションの終了

}