#include "Fonts.h"
#include "../DxLib/DxLib.h"
void Fonts::loadFont(LPSTR Path){
	if (AddFontResourceEx(Path, FR_PRIVATE, NULL) > 0) {
	} else {
		// フォント読込エラー処理
		MessageBox(NULL,"フォント読込失敗","",MB_OK);
	}
}

void Fonts::deleteFont(){
	if(RemoveFontResourceEx(path, FR_PRIVATE, NULL)) {
	} else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}

void Fonts::crtFHndl(int size,char* fontName){
		fontHandle.push_back(
		CreateFontToHandle( fontName,size,1,DX_FONTTYPE_ANTIALIASING_EDGE_4X4)
		);

  
}