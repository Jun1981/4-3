#include "../DxLib/DxLib.h"
#include "Debug.h"

#include "key.h"

#include "C_FreeMenu.h"

#include "Title.h"

void Debug(){
	int White=GetColor(255,255,255);//白
	DrawFormatString(100,400,White,"key_Info%d",key_Info);

	//DrawFormatString(100,400+16,White,"カーソルナンバー%d",tMenu.getNum());



}