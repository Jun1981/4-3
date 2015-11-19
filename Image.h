#pragma once
#include <tchar.h>
#include "../DxLib/DxLib.h"


///<summary>
///�����ȉ摜�S�ʃN���X�@
///</summary>
//���ۃN���X�ł��B�p�����Ďg���Ă��������B
class Image{//�摜�S�ʂ��炷

public:
	Image(int,int);//�R���X�g���N�^�i�摜�T�C�Y�w��j
	Image();//�R���X�g���N�^�i�O�j
	void Initialize();//������
	void Finalize();//�I������

	//�֐�
	void setGh(const char *);//gh�̃Z�b�^�[ Dxlib.init���I����Ă��炶��Ȃ���LoadGraph���g���Ȃ��̂�
	void setSizeXY(int,int);//�T�C�Y�w��
	
	
	inline void setXY(int a,int b){x=a;y=b;}//x�Ƃ��̃Z�b�^�[
	inline void setInitXY(int a,int b){initX=x=a;initY=y=b;}//�����ʒu�Z�b�^�[

	void resetXY();//���݈ʒu�������ʒu�Ƀ��Z�b�g
	int getGh();//gh�̃Q�b�^�[
	int getWidth(),getHeight();//�摜�T�C�Y�𓾂�
	
	//�摜�`��֐�
	virtual void draw(int Brightness=255);//DrawGraph���݈ʒu(���߂���j
	virtual void draw2(double zoom=1.0,int deg=0,int Brightness=255);//DrawRotaGraph(); ��]��Y�[���𗘗p (�{���A�p�x�j
	virtual void draw2(int X,int Y,double zoom=1.0,int deg=0,int flip=0,int Brightness=255);//DrawRotaGraph(); ��]��Y�[���𗘗p (�{���A�p�x�j �ʒu���w��

	//�ޯ��
	inline int getX(){
		return x;
	}
	inline int getY(){
		return y;
	}




	//�ϐ�

	
	//void getArrayAnimGh(int);
protected:	
	int x,y;//���ݍ��W�i����j
	
	int initX,initY;//�����ʒu
	int imgWidth,imgHeight;//�摜�T�C�Y�@���@�c
	int gh;//�摜�n���h��		
};