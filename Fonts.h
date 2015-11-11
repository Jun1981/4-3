#pragma once
#include <vector>
#include "../DxLib/DxLib.h"

class Fonts{

public:

		std::vector<int> fontHandle;//フォントハンドル

	void crtFHndl(int,char*);//文字サイズ、フォント名

	LPSTR path;//フォントのパス名
	void loadFont(LPSTR Path);//フォントを読み込む
	void deleteFont();//読み込んだフォントを消す


protected:
	
};