#pragma once


class C_FreeMenu{
public:
		enum Direction{hori=0,ver=1};//�����O�A�����P


	C_FreeMenu(int,int,int);//�R���X�g���N�^�i�c�A���A�����O�������@�P�������j
	
	void Initialize();//����������
	void Finalize();//�I������

	void calHori();
	//�Z�b�^�[
	void setTableInitXY(int,int);//�A�C�e���̏����ʒu�Z�b�g�����@���ڂ̃��j���[��
	void setTableXY(int,int);//�e�[�u���̈ʒu�ݒ�
	void setArrayTableXY();//�z��쐬

	//�Q�b�^�[
	int getNowTabX(), getNowTabY();
	int getNowCurX(),getNowCurY();
	int getTableX(int ROW,int COLUMN);
	int getTableY(int ROW, int COLUMN);




	//�C�����C���֐�
	inline int getNum(){return num;}
	inline int getRow(){return row;}
	inline int getColumn(){return column;}
	inline int getNRow(){return nRow;}
	inline int getNColumn(){return nColumn;}

	
	
	int num;//���݂̍��ڔԍ�
	
protected:
    int dir;//���j���[�̕����@������hori�@���� ver
	int row;//�s
	int column;//��

	int nRow,nColumn;//���̍s�@��
	int numOfTables;//���ڐ�

	int **tableX,**tableY;//���ڂ̍��W
	int **tableInitX, **tableInitY;//���ڂ̏������W
	int **gh;//�O���t�B�b�N�n���h��
	
		int nowTabX,nowTabY;//���̃e�[�u�����W


};