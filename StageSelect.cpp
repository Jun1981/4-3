
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

//enum型



//名前空間
namespace stgSel{
	//クラス宣言
	Image bg;//背景
	Image cursor;//カーソル
	Image fairy;//妖精イメージ
	Image fukidashi;//吹き出し画像クラス
	Image board;//板枠（右上文字背景）クラス

	
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
		stgMenu=new C_TableMenu(1,3,700,100,30,200,0);



	
	//ChangeFont( "うずらフォント", DX_CHARSET_DEFAULT );



		




	//フォント系
	//uzura.loadFont("Fonts/uzura.ttf");
	//フォント作成
	/* Uzura24= CreateFontToHandle( "うずらフォント",24,1,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;
	 Uzura60= CreateFontToHandle( "うずらフォント",60,1,DX_FONTTYPE_ANTIALIASING_EDGE_4X4) ;*/

	 /*uzura.crtFHndl(24,"うずらフォント");
	 uzura.crtFHndl(60,"うずらフォント");*/
	
	 

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


	//右上の黒板
	board.setGh("./img/Object/waku.png");
	board.setXY(660,90);


	//文字列を入れる

	//左端の風船
		sLine[0].setString(0,"初めての人はここ！");
		sLine[0].setString(1,"３階建てのステージです。");
	//真ん中の風船
		sLine[1].setString(0,"初級に慣れてきたらここ！");
		sLine[1].setString(1,"５階建てのステージです。");
	//右端の風船
		sLine[2].setString(0,"自信がある人はここ！");
		sLine[2].setString(1,"８階建てのステージです。");
	

		


	int z;

}

void StgSelDraw(){


	//背景表示
	bg.draw(255);

	//塔表示
	//SetFontSize(60);	// 見やすさのため、フォントサイズを大きく


	if(stgMenu->getNum()==0)stgMenu->draw(0,0,255);
	else stgMenu->draw(0,0,155);
	//DrawFormatString(stgMenu->getTableX(0,0)+80,stgMenu->getTableY(0,0)+310,BLACK,"初級");
	DrawStringToHandle(stgMenu->getTableX(0,0)+80,stgMenu->getTableY(0,0)+310,"初級",BLACK,Uzura60);

	if(stgMenu->getNum()==1)stgMenu->draw(0,1,255);
	else stgMenu->draw(0,1,155);
	//DrawFormatString(stgMenu->getTableX(0,1)+85,stgMenu->getTableY(0,1)+310,BLACK,"中級");
	DrawStringToHandle(stgMenu->getTableX(0,1)+85,stgMenu->getTableY(0,1)+310,"中級",BLACK,Uzura60);
	
	if(stgMenu->getNum()==2)	stgMenu->draw(0,2,255);
	else stgMenu->draw(0,2,155);
	//DrawFormatString(stgMenu->getTableX(0,2)+85,stgMenu->getTableY(0,2)+310,BLACK,"上級");
	DrawStringToHandle(stgMenu->getTableX(0,2)+85,stgMenu->getTableY(0,2)+310,"上級",BLACK,Uzura60);


	//妖精表示
	fairy.draw2(0.5,0,255);
	//吹き出し表示
	  SetDrawBlendMode(DX_BLENDMODE_MULA , 220 );
	fukidashi.draw2(0.65,0,255);
	  SetDrawBlendMode(DX_BLENDMODE_NOBLEND , 255 ) ;

	//吹き出し内の文字のX座標
	static int fukidashiMojiX=fukidashi.getX()-116;

	//SetFontSize(24);
	static int L=0;
	
	//吹き出し内の文字
	if(stgMenu->getNum()==0)sLine[0].scrollLine(fukidashiMojiX, fukidashi.getY()-30,Uzura24,WHITE);	
	if(stgMenu->getNum()==1)sLine[1].scrollLine(fukidashiMojiX, fukidashi.getY()-30,Uzura24,WHITE);	
	if(stgMenu->getNum()==2)sLine[2].scrollLine(fukidashiMojiX, fukidashi.getY()-30,Uzura24,WHITE);	
	

	//枠表示
	 SetDrawBlendMode(DX_BLENDMODE_MULA , 120 );
	board.draw2(0.5,0,255);
	  SetDrawBlendMode(DX_BLENDMODE_NOBLEND , 255 ) ;
	//枠内文字
	//DrawString( board.getX()-80 , board.getY()-30, "←・→ 選択",GetColor( 255 ,255 ,255 ) );//文字
	//DrawString( board.getX()-80 , board.getY()+10, "Enter  決定", GetColor( 255 ,255 ,255 ) );//文字

	DrawStringToHandle(board.getX()-80,board.getY()-30,   "←・→　選択",WHITE,Uzura24);
	DrawStringToHandle(board.getX()-75 , board.getY()+10, "Enter　決定",WHITE,Uzura24);



	//カーソル描画
	cursor.setXY(stgMenu->getNowCurX()+60,stgMenu->getNowCurY());
	cursor.draw2(0.2,90,255);
	
	int z=0;
	
}

void StgSelCal(){

	stgMenu->calHori();//カーソル処理
	//初級の上にカーソルがあったら
	if(stgMenu->getNum()==0){

		if(key_Trg==0x100){//エンターキーが押されたら
			Game.diff=easy;//難易度変数設定


			Game.mode=3;//キャラセレクト画面へ
			StgSelFinalize();//終了処理

		}

	}else sLine[0].resetLine();
	
	if(stgMenu->getNum()==1){}
	else  sLine[1].resetLine();

	if(stgMenu->getNum()==2){}
	else  sLine[2].resetLine();
	
}

//終了処理
void StgSelFinalize(){

	delete stgMenu;
	//stgMenu->Finalize();
}