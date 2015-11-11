#include "common.h"

#include "CharaSelect.h"
#include "Image.h"
#include "key.h"
#include "GameMain.h"
#include "StageSelect.h"
#include "C_ScrollLine.h"

#include "../DxLib/DxLib.h"

C_TableMenu *charSelMenu;

C_ScrollLine charSelLine;

namespace charSel{
 Image bg;//背景クラス宣言
 Image cursor;//カーソル画像
 Image fukidashi;//吹き出し画像
 Image fairy;//妖精画像

}
using namespace charSel;


void charSelMain(){
	static int initFlag=0;
	if(initFlag==0){
		charSelInit();
		initFlag=1;
	}

	//計算
	charSelCal();

	//描画
	 charSelDraw();



}

//初期化
void charSelInit(){

	//メニュークラスにメモリ確保
	charSelMenu=new C_TableMenu(1,4,700,100,135,400,0);
	////////////////

	ChangeFont( "うずらフォント", DX_CHARSET_DEFAULT );
	//画像読み込み
	//背景
	bg.setGh("./img/StageSelect/bg1.png");//背景画像

	//キャラ
	charSelMenu->setTableGh(0,0,"img/Chara/Hansel/normal.png");//ヘンゼル
	charSelMenu->setTableGh(0,1,"img/Chara/Gretel/normal.png");//グレーテル
	charSelMenu->setTableGh(0,2,"img/Chara/Roove/normal.png");//ルーヴ
	charSelMenu->setTableGh(0,3,"img/Chara/Puss/normal.png");//プシー

	//カーソル画像読み込み
	cursor.setGh("./img/cursor/finger1.png");//カーソル画像
	fairy.setGh("./img/object/pixy.png");//妖精画像
	
	//吹き出し
	fukidashi.setGh("./img/object/fukidashi3.png");//吹き出し画像
	fukidashi.setInitXY(450,200);//吹き出しの画像座標初期設定
	
	
	//吹き出しの文字
	charSelLine.setString(0, "ではプレイヤーさん、");
	charSelLine.setString(1,  "キャラクターを選んでください。");
	charSelLine.setString(2, "←・→：選択　Ｅｎｔｅｒ：決定");
		int z=0;


}


void charSelCal(){	

	charSelMenu->calHori();//カーソル処理
	if(charSelMenu->getNum()==0){
		if(key_Trg==0x100){
			//Game.mode=4;//セレクト画面へ
			//StgSelFinalize();//終了処理
		}	
	}

}

void charSelDraw(){

	
//描画
	//背景
	bg.draw(255);
	//キャラ
	for(int i=0;i<4;i++){

	if(charSelMenu->getNum()==i)charSelMenu->draw2(0,i,0.5,0,255);
	else charSelMenu->draw2(0,i,0.5,0,155);
		
	}

//文字描画

	//キャラネーム
	//SetFontSize(30);	// 見やすさのため、フォントサイズを大きく
	//DrawFormatString(charSelMenu->getTableX(0,0)-60,charSelMenu->getTableY(0,0)+100,BLACK,"ヘンゼル");
	//DrawFormatString(charSelMenu->getTableX(0,1)-70,charSelMenu->getTableY(0,0)+100,BLACK,"グレーテル");
	//DrawFormatString(charSelMenu->getTableX(0,2)-40,charSelMenu->getTableY(0,0)+100,BLACK,"ルーヴ");
	//DrawFormatString(charSelMenu->getTableX(0,3)-40,charSelMenu->getTableY(0,0)+100,BLACK,"プシー");

	DrawStringToHandle(charSelMenu->getTableX(0,0)-60,charSelMenu->getTableY(0,0)+100,"ヘンゼル",BLACK,Uzura30);
	DrawStringToHandle(charSelMenu->getTableX(0,1)-70,charSelMenu->getTableY(0,0)+100,"グレーテル",BLACK,Uzura30);
	DrawStringToHandle(charSelMenu->getTableX(0,2)-40,charSelMenu->getTableY(0,0)+100,"ルーヴ",BLACK,Uzura30);
	DrawStringToHandle(charSelMenu->getTableX(0,3)-40,charSelMenu->getTableY(0,0)+100,"プシー",BLACK,Uzura30);



	//左上難易度　表示

	  if(Game.diff==easy)DrawStringToHandle(10,50,"ステージ：かんたん",WHITE,Uzura24);

	  //吹き出し表示

	  SetDrawBlendMode(DX_BLENDMODE_MULA , 220 ) ;
	  fukidashi.draw2(fukidashi.getX(),fukidashi.getY(),0.65,180,255);
	    SetDrawBlendMode(DX_BLENDMODE_NOBLEND , 255 ) ;

	//吹き出し内の文字のｘ座標
	static int fukidashiMojiX=fukidashi.getX()-180;
	
	charSelLine.scrollLine(fukidashiMojiX , fukidashi.getY()-50,Uzura20,WHITE);

	//妖精表示
	fairy.draw2(700,100,0.5,0,255);





	//カーソル描画
	cursor.setXY(charSelMenu->getNowCurX()-80,charSelMenu->getNowCurY()-30);
	cursor.draw2(0.2,90,255);



	







}