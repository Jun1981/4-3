#include "Fonts.h"
#include "../DxLib/DxLib.h"
void Fonts::loadFont(LPSTR Path){
	if (AddFontResourceEx(Path, FR_PRIVATE, NULL) > 0) {
	} else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL,"�t�H���g�Ǎ����s","",MB_OK);
	}
}

void Fonts::deleteFont(){
	if(RemoveFontResourceEx(path, FR_PRIVATE, NULL)) {
	} else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}