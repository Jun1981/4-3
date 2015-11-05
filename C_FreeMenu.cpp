#include "C_FreeMenu.h"
#include "key.h"


//コンストラクタ
C_FreeMenu::C_FreeMenu(int row,int col,int dir){	 
	this->row=row;this->column=col;this->dir=dir;
	this->numOfTables=row*col;

	this->setArrayTableXY();
	/* this->setTableInitXY();*/

};

void C_FreeMenu::Finalize(){
	
	row=0;
	column=0;
	numOfTables=0;
	delete[] tableX;
	delete[] tableY;
	delete[]	tableInitX;
	delete[] tableInitY;
	delete[]	gh;


}

void C_FreeMenu::calHori(){

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


}

//配列作成
void C_FreeMenu::setArrayTableXY(){

	tableX=new int*[row];
	tableInitX=new int*[row];
	tableY=new int*[row];
	tableInitY=new int*[row];

	gh=new int*[row];

	for(int i=0;i<row;i++){		
		tableX[i]=new int[column];
		tableY[i]=new int[column];
		tableInitX[i]=new int[column];
		tableInitY[i]=new int[column];

		gh[i]=new int[column];
	}



}
////テーブル座標初期化
//void C_FreeMenu::setTableInitXY(int ROW,int COL,int X,int Y){
//
//		tableX[ROW][COL]=X;
//		tableY[ROW][COL]=Y;
//	
//
// 


//}
////テーブル位置設定
//void C_FreeMenu::setTableXY(int X,int Y){



//}

//グラフィックハンドラ要配列作成