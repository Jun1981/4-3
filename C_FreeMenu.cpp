#include "C_FreeMenu.h"
#include "key.h"


//�R���X�g���N�^
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


}

//�z��쐬
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
////�e�[�u�����W������
//void C_FreeMenu::setTableInitXY(int ROW,int COL,int X,int Y){
//
//		tableX[ROW][COL]=X;
//		tableY[ROW][COL]=Y;
//	
//
// 


//}
////�e�[�u���ʒu�ݒ�
//void C_FreeMenu::setTableXY(int X,int Y){



//}

//�O���t�B�b�N�n���h���v�z��쐬