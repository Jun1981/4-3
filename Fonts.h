#pragma once
#include <vector>
#include "../DxLib/DxLib.h"

class Fonts{

public:

		std::vector<int> fontHandle;//�t�H���g�n���h��

	void crtFHndl(int,char*);//�����T�C�Y�A�t�H���g��

	LPSTR path;//�t�H���g�̃p�X��
	void loadFont(LPSTR Path);//�t�H���g��ǂݍ���
	void deleteFont();//�ǂݍ��񂾃t�H���g������


protected:
	
};