#include "C_MAP.h"

#include "C_GameSettings.h"

#include "../DxLib/DxLib.h"

//セッター
void C_MAP::setMapDataArray(int row,int col){

	mapData = new int* [row];	
	for(int i=0;i<row;i++){
	mapData[i]=new int [col];
	}

}


void C_MAP::setMapChipSize(int x,int y){
	chipSizeX=x;
	chipSizeY=y;
}

void C_MAP::setMapRowCol(int Row,int Col){

	row=Row;
	col=Col;

}


//void C_MAP::setDefCharXY(){
//
//
//}

void C_MAP::loadMapChip(const char* fileName,int numOfChipX,int numOfChipY){


	mapChipGH=new int[numOfChipX*numOfChipY];
	LoadDivGraph(fileName,numOfChipX*numOfChipY,numOfChipX,numOfChipY,chipSizeX,chipSizeY,mapChipGH);
	
}



	void C_MAP::calLoopStartEnd(){

		if(getDispUYinMap()>=chipSizeY){//上端
		mapSI=getDispUYinMap()/chipSizeY;
	}
	else{ mapSI=0; }


	if(getDispLXinMap()>=chipSizeX){//左端
		mapSJ=getDispLXinMap()/chipSizeX;
	}
	else{mapSJ=0;}

	if(getDispDYinMap()<chipSizeY*row) {//下端
		
	

		mapEI=getDispDYinMap()/chipSizeY+1;

	}else {mapEI=row;}
	
	if( getDispRXinMap()<chipSizeX*col) {//右端
		
		mapEJ=getDispRXinMap()/chipSizeX+1;
	}else{ mapEJ=col;}
	
	}


	void C_MAP::setStartXYinMap(int X,int Y){
		startXinMap=X;startYinMap=Y;

			setLX(resoX/2-chipSizeX/2-startXinMap);
				setUY(resoY/2-chipSizeY/2-startYinMap);

				setDispLXinMap(-1*getLX());
				setDispUYinMap(-1*getUY());
	}