#include "../DxLib/DxLib.h"
#include "Debug.h"

#include "key.h"

#include "C_FreeMenu.h"

#include "Title.h"

void Debug(){
	int White=GetColor(255,255,255);//��
	DrawFormatString(100,400,White,"key_Info%d",key_Info);

	//DrawFormatString(100,400+16,White,"�J�[�\���i���o�[%d",tMenu.getNum());



}