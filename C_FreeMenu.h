#pragma once


class C_FreeMenu{
public:
		enum Direction{hori=0,ver=1};//水平０、垂直１


	C_FreeMenu(int,int,int);//コンストラクタ（縦、横、方向０＝水平　１＝垂直）
	
	void Initialize();//初期化処理
	void Finalize();//終了処理

	void calHori();
	//セッター
	void setTableInitXY(int,int);//アイテムの初期位置セットｘｙ　何個目のメニューか
	void setTableXY(int,int);//テーブルの位置設定
	void setArrayTableXY();//配列作成

	//ゲッター
	int getNowTabX(), getNowTabY();
	int getNowCurX(),getNowCurY();
	int getTableX(int ROW,int COLUMN);
	int getTableY(int ROW, int COLUMN);




	//インライン関数
	inline int getNum(){return num;}
	inline int getRow(){return row;}
	inline int getColumn(){return column;}
	inline int getNRow(){return nRow;}
	inline int getNColumn(){return nColumn;}

	
	
	int num;//現在の項目番号
	
protected:
    int dir;//メニューの方向　水平＝hori　垂直 ver
	int row;//行
	int column;//列

	int nRow,nColumn;//今の行　列
	int numOfTables;//項目数

	int **tableX,**tableY;//項目の座標
	int **tableInitX, **tableInitY;//項目の初期座標
	int **gh;//グラフィックハンドら
	
		int nowTabX,nowTabY;//今のテーブル座標


};