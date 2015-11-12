

#pragma once 


class C_MAP{
public:
	int mapSI,mapSJ,mapEI,mapEJ;//�}�b�v�ߖ�p


	int row;//�c�̌�
	int col;//���̌�
	int *mapChipGH;
	int **mapData;
	int chipSizeX;//�}�b�v�`�b�v�T�C�Y�w
	int chipSizeY;//�}�b�v�`�b�v�T�C�Y�x

	int dispW,dispH;//�f�B�X�v���C�𑜓x

	
	
	//C_MAP();//�R���X�g���N�^ �`�b�v�T�C�Y


	//�Z�b�^�[
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

	
	//�Q�b�^�[
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
	int LX,UY;//�}�b�v�̌��݂̍���̍��W

	int dispLXinMap;//�f�B�X�v���C�̃}�b�vX���W�@���@�E
	int dispUYinMap;//�f�B�X�v���C�̌���Y���W�@��Ɖ�



	



};