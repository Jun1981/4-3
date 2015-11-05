#include "StageSelect.h"
#include "GameMain.h"
#include "C_TableMenu.h"
#include "Image.h"
#include "Fonts.h"
C_TableMenu *stgMenu;

#include "key.h"


//enum型
	DIFF diff;


//名前空間
namespace stgSel{
	//クラス宣言
	Image bg;//背景
	Image cursor;//カーソル
	Image fairy;//妖精イメージ
	Image fukidashi;//吹き出し画像クラス
	Image board;//板枠（右上文字背景）クラス
	Fonts fonts;//フォントクラス

	



}
using namespace stgSel;

//メイン
void StgSelMain(){
	static int initFlag=0;

	if(initFlag==0){
		StgSelInit();
		initFlag=1;
	}
	
	
	StgSelDraw();
	StgSelCal();
}

//初期化
void StgSelInit(){


	

	//フォント系
	fonts.loadFont("Fonts/uzura.ttf");

	ChangeFont( "うずらフォント", DX_CHARSET_DEFAULT );


	stgMenu=new C_TableMenu(1,3,700,100,30,200,0);

	//C_TableMenu stgMenu(1,3,400,50,100,400,0);
	//画像読み込み
	bg.setGh("./img/StageSelect/bg1.png");//背景画像
	cursor.setGh("./img/cursor/finger1.png");//カーソル画像
	fairy.setGh("./img/object/pixy.png");//妖精画像
	fukidashi.setGh("./img/object/fukidashi2.png");//吹き出し画像

	//cursor.setInitXY(stgMenu->getTableX(),stgMenu->getTableY(),250);
	//塔画像読み込み
	stgMenu->setTableGh(0,0,"./img/StageSelect/tower1.png");
	stgMenu->setTableGh(0,1,"./img/StageSelect/tower2.png");
	stgMenu->setTableGh(0,2,"./img/StageSelect/tower3.png");

	//stgMenu->setNowTabXY();

	fairy.setInitXY(100,140);//妖精の初期画像設定
	fukidashi.setInitXY(320,110);//吹き出しの画像座標初期設定
	
	board.setGh("./img/Object/waku.png");
	board.setXY(660,90);





	int z;

}

void StgSelDraw(){
	//背景表示
	bg.draw(255);

	//塔表示
	SetFontSize(60);	// 見やすさのため、フォントサイズを大きく
	


	if(stgMenu->getNum()==0)stgMenu->draw(0,0,255);
	else stgMenu->draw(0,0,155);
	DrawFormatString(stgMenu->getTableX(0,0)+80,stgMenu->getTableY(0,0)+310,BLACK,"初級");

	if(stgMenu->getNum()==1)stgMenu->draw(0,1,255);
	else stgMenu->draw(0,1,155);
	DrawFormatString(stgMenu->getTableX(0,1)+85,stgMenu->getTableY(0,1)+310,BLACK,"中級");

	if(stgMenu->getNum()==2)	stgMenu->draw(0,2,255);
	else stgMenu->draw(0,2,155);
	DrawFormatString(stgMenu->getTableX(0,2)+85,stgMenu->getTableY(0,2)+310,BLACK,"上級");


	//妖精表示
	fairy.draw2(0.25,0,255);
	//吹き出し表示
	fukidashi.draw2(0.65,0,255);

	//吹き出し内の文字
	static int fukidashiMojiX=fukidashi.getX()-116;

	SetFontSize(24);
	if(stgMenu->getNum()==0){
		DrawString( fukidashiMojiX , fukidashi.getY()-30, "初めての人はここ！", GetColor( 0 , 0 , 0 ) );//文字
	DrawString( fukidashiMojiX , fukidashi.getY()-30+32, "3階建てのステージです。", GetColor( 0 , 0 , 0 ) );//文字
	}
	
	if(stgMenu->getNum()==1){
	DrawString( fukidashiMojiX , fukidashi.getY()-30, "初級に慣れてきたらここ！", GetColor( 0 , 0 , 0 ) );//文字
	DrawString( fukidashiMojiX , fukidashi.getY()-30+32, "5階建てのステージです。", GetColor( 0 , 0 , 0 ) );//文字
	}
	if(stgMenu->getNum()==2){
	DrawString( fukidashiMojiX , fukidashi.getY()-30, "自信がある人はここ！", GetColor( 0 , 0 , 0 ) );//文字
	DrawString( fukidashiMojiX , fukidashi.getY()-30+32, "8階建てのステージです。", GetColor( 0 , 0 , 0 ) );//文字
	}
	
	//枠表示
	board.draw2(0.5,0,255);
	//枠内文字
	DrawString( board.getX()-80 , board.getY()-30, "←・→ 選択",GetColor( 255 ,255 ,255 ) );//文字
	DrawString( board.getX()-80 , board.getY()+10, "Enter  決定", GetColor( 255 ,255 ,255 ) );//文字



	
	//カーソル描画
	cursor.setXY(stgMenu->getNowCurX()+60,stgMenu->getNowCurY());
	cursor.draw2(0.2,90,255);



}

void StgSelCal(){
	
	stgMenu->calHori();//カーソル処理
	//初級の上にカーソルがあったら
	if(stgMenu->getNum()==0){

		if(key_Trg==0x100){//エンターキーが押されたら
			diff=easy;//難易度変数設定

			Game.mode=3;//キャラセレクト画面へ
			StgSelFinalize();//終了処理

		}

	}
}

//終了処理
void StgSelFinalize(){

	delete stgMenu;
	//stgMenu->Finalize();
}