//2015/10/18作成

#pragma once

class C_TableMenu {
	
protected:

	int num;//現在の項目番号
	int dir;//メニューの方向　水平＝hori　垂直 ver
	int row;//行
	int column;//列
	int numOfTables;//項目数


	int **tableGh;//グラフィックハンドら

	int **tableX,**tableY;//項目の座標
	int **tableInitX, **tableInitY;//項目の初期座標

	

	int dWidth,dHeight;//描画領域の　幅　高さ
	int dUpLeftX,dUpLeftY;//描画領域の左上の座標

	int tWidth,tHeight;//各テーブルの幅　高さ

	int nRow,nColumn;//今の行　列

	int nowTabX,nowTabY;//今のテーブル座標
public:	
	int dirNext;//方向
	//enum
	enum Direction{hori=0,ver=1};//水平０、垂直１
	//コンストラクタ
	C_TableMenu();//既定コンストラクタ
	
	C_TableMenu(
		/// <summary>
  /// メッセージを出力ウインドウへ表示する
  /// </summary>
  /// <param name="mess">表示文字列を入れる</param>

		int row,//縦の行
		int col,//列
		int width,//メニュー幅
		int height,//メニューの高さ
		int ulX,int ulY,//メニューの左上座標	
		int dir//水平0か垂直1
		);//格子状メニュー作成
	C_TableMenu(int r,int c,Direction d);//自由選択系
	~C_TableMenu();//デストラクタ



	void Initialize();//初期化
	void Finalize();//終了処理



	//セッター	
	//void setArrayTableInitXY();//アイテム座標の初期位置
	void setArrayTableXY();

	void setTableInitXY();//アイテムの初期位置セットｘｙ　何個目のメニューか
	void setTableGh(
		int ,
		int ,
		const char* gPath
		);
	//
	void setNowTabXY();//現在のテーブル位置
	//void setNowCurXY();//カーソル用座標
	//

	//ゲッター

	int getNowTabX(), getNowTabY();
	int getNowCurX(),getNowCurY();
	int getTableX(int ROW,int COLUMN);
	int getTableY(int ROW, int COLUMN);
		

	//計算関係
	inline void reset(){num=nRow=nColumn=0;};//リセット

	void calHori( );//計算 横　メニュー(項目数）　現在の番号を返す
	void calVer( );//計算 縦　メニュー(項目数）　現在の番号を返す
    void draw(int row,int col,int Brightness);//描画
	void draw2(int row,int col,double zoom,int deg,int Brightness);//DrawRotaGraph(); 回転やズームを利用 (倍率、角度）
		
	//インライン関数
	inline int getNum(){return num;}
	inline int getRow(){return row;}
	inline int getColumn(){return column;}
	inline int getNRow(){return nRow;}
	inline int getNColumn(){return nColumn;}
	inline int C_TableMenu::getTWidth(){return tWidth;}
	inline int C_TableMenu::getTHeight(){return tHeight;}


};

