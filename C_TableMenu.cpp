#include "C_TableMenu.h"
#include "key.h"

#include "../DxLib/DxLib.h"

C_TableMenu::C_TableMenu(){};
//コンストラクタ
C_TableMenu::C_TableMenu(int r,int c,Direction d){
	row=r;column=c;
	numOfTables=row*column;
	nowTabX=nowTabY=0;
	dir=d;
}
C_TableMenu::C_TableMenu(
	int row,
	int col,
	int width,
	int height,
	int ulX,
	int ulY,
	int dir)
{
	num=0;
	this->row=row;this->column=col;
	numOfTables=row*column;
	dWidth=width;dHeight=height;
	dUpLeftX=ulX;dUpLeftY=ulY;	 
	this->dir=dir;

	nRow=nColumn=0;
	nowTabX=dUpLeftX;nowTabY=dUpLeftY;

	tWidth=dWidth/column;//テーブルの幅
	tHeight=dHeight/row;//テーブルの高さ

	//関数
	setArrayTableXY();
	setTableInitXY();

		

}
//デストラクタ
C_TableMenu::~C_TableMenu(){

	//delete[] tableX,tableY,tableInitX,tableInitY;
}
////終了処理
void C_TableMenu::Finalize(){
	
	if(tableGh!=0)delete[] tableGh;	
	if(tableX!=0) delete[] tableX;
	if(tableY!=0) delete[] tableY;
	if(tableInitX!=0) delete[] tableInitX;
	if(tableInitY!=0) delete[] tableInitY;


}
//配列作成
void C_TableMenu::setArrayTableXY(){

	tableX=new int*[row];
	tableInitX=new int*[row];
	tableY=new int*[row];
	tableInitY=new int*[row];

	tableGh=new int*[row];

	for(int i=0;i<row;i++){		
		tableX[i]=new int[column];
		tableY[i]=new int[column];
		tableInitX[i]=new int[column];
		tableInitY[i]=new int[column];

		tableGh[i]=new int[column];
	}
}

void C_TableMenu::setTableInitXY(){

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			tableX[i][j]=dUpLeftX+tWidth*j;
			tableY[i][j]=dUpLeftY+tHeight*i;
		}
	}
}
//計算
void C_TableMenu::calHori(){//横メニューの計算

	//右が押されたら
	if(key_Trg==keyRight){
		if(nColumn<column-1){num++;nColumn++;/*現在番号＋＋*/}//右端にイなかったら
		else/*右端にいたら*/if(num==numOfTables-1){num=nRow=nColumn=0;}//最後なら番号リセット		
		else {num++;nColumn=0;nRow+=1;/*下の行に左端に移る*/}

	}	

	//左を押したら
	if(key_Trg==0x01){
		if(nColumn>0)/*左端にイなかったら*/{num--;nColumn--;}
		else /*左端にいたら*/if(num==0){num=numOfTables-1;nRow=row-1;nColumn=column-1;}/*左上にいたら*/
		else /*0以外*/{num--;nRow--;nColumn+=column-1;/*右上に*/}
	}

	setNowTabXY();//現在テーブル位置をセット
	

}
//描画
void C_TableMenu::draw(int row,int col,int Brightness){
	SetDrawBright(Brightness,Brightness,Brightness);//明るさを設定
	DrawGraph(tableX[row][col],tableY[row][col],tableGh[row][col],1);
	SetDrawBright(255,255,255);//明るさを元に戻す
}

//DrawRotaGraph(); 回転やズームを利用 (倍率、角度）
void C_TableMenu::draw2(int row,int col,double zoom,int deg,int Brightness){
		SetDrawBright(Brightness,Brightness,Brightness);//明るさを設定
	DrawRotaGraph(tableX[row][col],tableY[row][col],zoom,(double)(deg/180.0)*3.14,tableGh[row][col],1,0);
	SetDrawBright(255,255,255);//明るさを元に戻す
	}

//セッター
//テーブル左上座標セット
void C_TableMenu::setNowTabXY(){
	nowTabX=dUpLeftX+nColumn*tWidth;
	nowTabY=dUpLeftY+nRow*tHeight;

}
//カーソル用座標セット
//void C_TableMenu::setNowCurXY(){
//	nowTabX=dUpLeftX+nColumn*tWidth;
//	nowTabY=dUpLeftY+nRow*tHeight+tHeight/2;
//
//}
void C_TableMenu::setTableGh(int row,int col,char* gPath){

	this->tableGh[row][col]=LoadGraph(gPath,0);
}


//ｹﾞｯﾀｰ
int C_TableMenu::getNowTabX(){
	return nowTabX;
}
int C_TableMenu::getNowTabY(){
	return nowTabY;
}
int C_TableMenu::getNowCurX(){
		return nowTabX;
}
int C_TableMenu::getNowCurY(){
	return nowTabY+tHeight/2;
}

int C_TableMenu::getTableX(int ROW,int COLUMN){

	return tableX[ROW][COLUMN];
}
int C_TableMenu::getTableY(int ROW,int COLUMN){

	return tableY[ROW][COLUMN];
}

