#pragma once


#include "../DxLib/DxLib.h"
#include <vector>
using namespace std;

class C_ScrollLine{

public:

	//�R���X�g���N�^
	C_ScrollLine();//�f�t�H���g�R���X�g���N�^
	C_ScrollLine(
		int NumOfLine,
		int LineSpace,//�s��		
		int CharSpace=0//�����Ԋu�@
		);//�R���X�g���N�^
	//C_ScrollLine(int NumOfLine);//�R���X�g���N�^(�s���w��j

	//�֐�
	void setString(
		int n,//���s�ڂ�
		char* STR//������
		);
	
	void scrollLine(
		int X,int Y,//�����J�n�ʒu���W				
		//�f�t�H���g		
		int fHandle,//�t�H���g�n���h��
		
		
		int Color=GetColor(0,0,0),//�F(�f�t�H���g���j
		int Speed=5,//���b�Z�[�W�X�s�[�h
		int LineSpace=32 //�s��
		);//��������
	void resetLine();
	//void scrollLine();
	void setCharColor(int R,int G,int B);//�F�ݒ�
	//void changeFontHandle(int);


	//�ޯ��
	inline int getRowNum(){return numOfLine;}

	//char **str;		


	int nowRowNum;//���̍s
protected:
	
	unsigned int i;//���Ԗڂ̕�����
	int spdCnt;//�X�s�[�h�����p�J�E���^
	int speed;//��������X�s�[�h
	//int spdCnt;//�X�s�[�h�J�E���^
	vector<char*> V_Str;
	char  str[5][256];//�����\���p�z��	

	int charSpace;//�����Ԋu�@
	int lineSpace;//�s��
	int charColor;//�F

	int numOfLine;//�s��
	char* tempStr;//�����������

};
