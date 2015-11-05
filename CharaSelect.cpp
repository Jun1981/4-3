#include "CharaSelect.h"
#include "Image.h"
#include "key.h"
#include "GameMain.h"
#include "StageSelect.h"

#include "../DxLib/DxLib.h"

C_TableMenu *charSelMenu;

namespace charSel{
 Image bg;//背景クラス宣言
 Image cursor;//カーソル画像

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
	charSelMenu->draw2(0,i,0.5,0,255);
		
	}

//文字描画

	//キャラネーム
	SetFontSize(30);	// 見やすさのため、フォントサイズを大きく
	DrawFormatString(charSelMenu->getTableX(0,0)-60,charSelMenu->getTableY(0,0)+100,BLACK,"ヘンゼル");
	DrawFormatString(charSelMenu->getTableX(0,1)-70,charSelMenu->getTableY(0,0)+100,BLACK,"グレーテル");
	DrawFormatString(charSelMenu->getTableX(0,2)-40,charSelMenu->getTableY(0,0)+100,BLACK,"ルーヴ");
	DrawFormatString(charSelMenu->getTableX(0,3)-40,charSelMenu->getTableY(0,0)+100,BLACK,"プシー");

	//左上難易度　表示

	  if(diff==easy)DrawFormatString(50,50,WHITE,"かんたん");






	//カーソル描画
	cursor.setXY(charSelMenu->getNowCurX()-80,charSelMenu->getNowCurY()-30);
	cursor.draw2(0.2,90,255);



	







}