

#pragma once 


class C_MAP{
public:
	int mapSI,mapSJ,mapEI,mapEJ;//マップ節約用


	int row;//縦の個数
	int col;//横の個数
	int *mapChipGH;
	int **mapData;
	int chipSizeX;//マップチップサイズＸ
	int chipSizeY;//マップチップサイズＹ

	int dispW,dispH;//ディスプレイ解像度

	
	
	//C_MAP();//コンストラクタ チップサイズ


	//セッター
	void setMapChipSize(int x,int y);
	void setMapDataArray(int row,int col);
	void setMapRowCol(int Row,int Col);
	inline void setDispWH(int w,int h){dispW=w;dispH=h;}
	inline void setDispXY(int lX,int uY){
		LX=lX;UY=uY;
		dispLXinMap=-1*LX; 
		dispUYinMap=-1*UY; 
	}

	inline void setDispLXinMap(int X){ dispLXinMap=X;}
	
	inline void setDispUYinMap(int Y){ dispUYinMap=Y;}
	inline void setLX(int X){LX=X;}
	inline void setUY(int Y){UY=Y;}

	
	//ゲッター
	inline int getDispLXinMap(){return dispLXinMap;}
	inline int getDispRXinMap(){return dispLXinMap+dispW;}
	inline int getDispUYinMap(){return dispUYinMap;}
	inline int getDispDYinMap(){return dispUYinMap+dispH;}

	inline int getLX(){return LX;}
	inline int getRX(){return LX+chipSizeX*col;}
	inline int getUY(){return UY;}
	inline int getDY(){return UY+chipSizeY*row;}


	void loadMapChip(const char* fileName,int numOfChipX,int numOfChipY);


	void draw();
	//void cal();

	void initialize();

	void calLoopStartEnd();




protected:
	int LX,UY;//マップの現在の左上の座標

	int dispLXinMap;//ディスプレイのマップX座標　左　右
	int dispUYinMap;//ディスプレイの現在Y座標　上と下



	



};