#include "C_MAP.h"

#include "../DxLib/DxLib.h"


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


void C_MAP::loadMapChip(const char* fileName,int numOfChipX,int numOfChipY){


	mapChipGH=new int[numOfChipX*numOfChipY];
	LoadDivGraph(fileName,numOfChipX*numOfChipY,numOfChipX,numOfChipY,chipSizeX,chipSizeY,mapChipGH);
	
}



	void C_MAP::calLoopStartEnd(){

		if(getDispUYinMap()>=0){//上端
		mapSI=getDispUYinMap()/chipSizeY;
	}
	else{ mapSI=0; }


	if(getDispLXinMap()>=0){//左端
		mapSJ=getDispLXinMap()/chipSizeX;
	}
	else{mapSJ=0;}

	if(getDispDYinMap()<chipSizeY*row) {//下端
		
		mapEI=row-
			(chipSizeY*row-getDispDYinMap())
			/chipSizeY+1;

	}else {mapEI=row;}
	
	if( getDispRXinMap()<chipSizeX*col) {//右端
		mapEJ=	col-	
			(chipSizeX*col-getDispRXinMap())/chipSizeX ;
	}else{ mapEJ=col;}
	
	}


