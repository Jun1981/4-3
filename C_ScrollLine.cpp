#include "C_ScrollLine.h"
#include "../DxLib/DxLib.h"

#include <string.h>
#include <mbstring.h>
#include <vector>
using namespace std;
//�R���X�g���N�^
C_ScrollLine::C_ScrollLine(){

	charSpace=10;
	lineSpace=32;

}
C_ScrollLine::C_ScrollLine(

	int NumOfLine,//�s��
	int LineSpace,//�s��
	int CharSpace//�����Ԋu�@

	){

		charSpace=CharSpace;
		lineSpace=LineSpace;

		//numOfLine=NumOfLine;

		//rowNum=RowNum;//�s���ݒ�
		//str= new char*[RowNum];

		//str= new string[RowNum];
		//int z=0;
}


//�֐��{��
void C_ScrollLine::setString(
	int n,
	char* STR){		
		V_Str.push_back(STR);
		numOfLine++;
}
void C_ScrollLine::scrollLine(
	int X,int Y,//�����J�n�ʒu���W
	
	int fHandle,//�t�H���g�n���h��
	
	
	int Color,//�F(�f�t�H���g�͔��j
	int Speed,//���b�Z�[�W�X�s�[�h
	int LineSpace//�s��
	){
		static int S=0;
		//static  char* STRING;


		//speed=Speed;

		if(S==0){spdCnt=Speed;S=1;}//�X�s�[�h

		//STRING=sTRING;
		//	V_Str[nowRowNum];

		if(spdCnt>=-10)
			spdCnt--;//�X�s�[�h�J�E���g�}�C�i�X�P

		//static unsigned int i=0;
		//�ۑ����������񂩂�ꕶ�������o���ĕ\���p�ϐ��ɓ����

		if(nowRowNum<numOfLine){
			if(spdCnt<=0){
				if(V_Str[nowRowNum][i]!='\0'){
					spdCnt=Speed;//���Z�b�g

					str[nowRowNum][i]=V_Str[nowRowNum][i];
					str[nowRowNum][i+1]=V_Str[nowRowNum][i+1];
					str[nowRowNum][i+2]='\0';
					i+=2;
					//	break;
				}else{
					spdCnt=Speed;//���Z�b�g
					i=0;
					nowRowNum++;				
				}
				//}
			}		
		}
		for(int j=0;j<numOfLine;j++){
			//DrawFormatString(X,Y+lineSpace*j,Color,str[j]);
			DrawStringToHandle(X,Y+lineSpace*j,str[j],Color,fHandle);

		}



}



void C_ScrollLine::resetLine(){
	i=0;
	nowRowNum=0;

	for(int j=0;j<5;j++){
		for(int k=0;k<256;k++){
			str[j][k]='\0';
		}

	}
	//tempStr[0]='\0';
}
//�Z�b�^�[
void C_ScrollLine::setCharColor(int R,int G,int B){
	charColor=GetColor(R,G,B);
}

//
//void C_ScrollLine::changeFontHandle(int n){
//
//	
//
//
//}