#include "C_TableMenu.h"
#include "key.h"

#include "../DxLib/DxLib.h"

C_TableMenu::C_TableMenu(){};
//�R���X�g���N�^
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

	tWidth=dWidth/column;//�e�[�u���̕�
	tHeight=dHeight/row;//�e�[�u���̍���

	//�֐�
	setArrayTableXY();
	setTableInitXY();

		

}
//�f�X�g���N�^
C_TableMenu::~C_TableMenu(){

	//delete[] tableX,tableY,tableInitX,tableInitY;
}
////�I������
void C_TableMenu::Finalize(){
	
	if(tableGh!=0)delete[] tableGh;	
	if(tableX!=0) delete[] tableX;
	if(tableY!=0) delete[] tableY;
	if(tableInitX!=0) delete[] tableInitX;
	if(tableInitY!=0) delete[] tableInitY;


}
//�z��쐬
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
//�v�Z
void C_TableMenu::calHori(){//�����j���[�̌v�Z

	//�E�������ꂽ��
	if(key_Trg==keyRight){
		if(nColumn<column-1){num++;nColumn++;/*���ݔԍ��{�{*/}//�E�[�ɃC�Ȃ�������
		else/*�E�[�ɂ�����*/if(num==numOfTables-1){num=nRow=nColumn=0;}//�Ō�Ȃ�ԍ����Z�b�g		
		else {num++;nColumn=0;nRow+=1;/*���̍s�ɍ��[�Ɉڂ�*/}

	}	

	//������������
	if(key_Trg==0x01){
		if(nColumn>0)/*���[�ɃC�Ȃ�������*/{num--;nColumn--;}
		else /*���[�ɂ�����*/if(num==0){num=numOfTables-1;nRow=row-1;nColumn=column-1;}/*����ɂ�����*/
		else /*0�ȊO*/{num--;nRow--;nColumn+=column-1;/*�E���*/}
	}

	setNowTabXY();//���݃e�[�u���ʒu���Z�b�g
	

}
//�`��
void C_TableMenu::draw(int row,int col,int Brightness){
	SetDrawBright(Brightness,Brightness,Brightness);//���邳��ݒ�
	DrawGraph(tableX[row][col],tableY[row][col],tableGh[row][col],1);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
}

//DrawRotaGraph(); ��]��Y�[���𗘗p (�{���A�p�x�j
void C_TableMenu::draw2(int row,int col,double zoom,int deg,int Brightness){
		SetDrawBright(Brightness,Brightness,Brightness);//���邳��ݒ�
	DrawRotaGraph(tableX[row][col],tableY[row][col],zoom,(double)(deg/180.0)*3.14,tableGh[row][col],1,0);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
	}

//�Z�b�^�[
//�e�[�u��������W�Z�b�g
void C_TableMenu::setNowTabXY(){
	nowTabX=dUpLeftX+nColumn*tWidth;
	nowTabY=dUpLeftY+nRow*tHeight;

}
//�J�[�\���p���W�Z�b�g
//void C_TableMenu::setNowCurXY(){
//	nowTabX=dUpLeftX+nColumn*tWidth;
//	nowTabY=dUpLeftY+nRow*tHeight+tHeight/2;
//
//}
void C_TableMenu::setTableGh(int row,int col,char* gPath){

	this->tableGh[row][col]=LoadGraph(gPath,0);
}


//�ޯ��
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

