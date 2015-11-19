#include "Image.h"
#include "../DxLib/DxLib.h"
#include <tchar.h>

//�R���X�g���N�^
Image::Image(int w,int h){//�摜�T�C�Y�w��

	this->imgWidth=w;this->imgHeight=h;
}
Image::Image(){
	x=y=initX=initY=gh=0;

}
//�Z�b�^�[
void Image::setGh(const char *str){

 gh=LoadGraph(str,0);

}
void Image::setSizeXY(int w,int h){

	imgWidth=w;imgHeight=h;

}
//void Image::setXY(int a, int b){
//	x=a;y=b;
//}

//�Q�b�^�[

int Image::getGh(){
	return gh;
}


//�A�j���\�V�����p�n���h��
//void Image::getArrayAnimGh(int n){
//
//	animGh=new int[n];
//
//
//
//}

//DrawGraph���݈ʒu(���߂���j
void Image::draw(int Brightness){
	SetDrawBright(Brightness,Brightness,Brightness);//���邳��ݒ�
	DrawGraph(x,y,gh,1);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
}
//DrawRotaGraph(); ��]��Y�[���𗘗p (�{���A�p�x�j�N���X�����W���g�p
void Image::draw2(double zoom,int deg,int Brightness){
		SetDrawBright(Brightness,Brightness,Brightness);//���邳��ݒ�
	DrawRotaGraph(x,y,zoom,(double)(deg/180.0)*3.14,gh,1,0);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
	}

void Image::draw2(int X,int Y,double zoom,int deg,int flip,int Brightness){
		SetDrawBright(Brightness,Brightness,Brightness);//���邳��ݒ�
	DrawRotaGraph(X,Y,zoom,(double)(deg/180.0)*3.14,gh,1,flip);
	SetDrawBright(255,255,255);//���邳�����ɖ߂�
	}

void Image::resetXY(){
	x=initX;y=initY;
}
//�Q�b�^�[

int Image::getWidth(){
	return imgWidth;
}

int Image::getHeight(){
	return imgHeight;
}
