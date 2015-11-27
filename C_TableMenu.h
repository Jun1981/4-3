//2015/10/18�쐬

#pragma once

class C_TableMenu {
	
protected:

	int num;//���݂̍��ڔԍ�
	int dir;//���j���[�̕����@������hori�@���� ver
	int row;//�s
	int column;//��
	int numOfTables;//���ڐ�


	int **tableGh;//�O���t�B�b�N�n���h��

	int **tableX,**tableY;//���ڂ̍��W
	int **tableInitX, **tableInitY;//���ڂ̏������W

	

	int dWidth,dHeight;//�`��̈�́@���@����
	int dUpLeftX,dUpLeftY;//�`��̈�̍���̍��W

	int tWidth,tHeight;//�e�e�[�u���̕��@����

	int nRow,nColumn;//���̍s�@��

	int nowTabX,nowTabY;//���̃e�[�u�����W
public:	
	int dirNext;//����
	//enum
	enum Direction{hori=0,ver=1};//�����O�A�����P
	//�R���X�g���N�^
	C_TableMenu();//����R���X�g���N�^
	
	C_TableMenu(
		/// <summary>
  /// ���b�Z�[�W���o�̓E�C���h�E�֕\������
  /// </summary>
  /// <param name="mess">�\�������������</param>

		int row,//�c�̍s
		int col,//��
		int width,//���j���[��
		int height,//���j���[�̍���
		int ulX,int ulY,//���j���[�̍�����W	
		int dir//����0������1
		);//�i�q�󃁃j���[�쐬
	C_TableMenu(int r,int c,Direction d);//���R�I���n
	~C_TableMenu();//�f�X�g���N�^



	void Initialize();//������
	void Finalize();//�I������



	//�Z�b�^�[	
	//void setArrayTableInitXY();//�A�C�e�����W�̏����ʒu
	void setArrayTableXY();

	void setTableInitXY();//�A�C�e���̏����ʒu�Z�b�g�����@���ڂ̃��j���[��
	void setTableGh(
		int ,
		int ,
		const char* gPath
		);
	//
	void setNowTabXY();//���݂̃e�[�u���ʒu
	//void setNowCurXY();//�J�[�\���p���W
	//

	//�Q�b�^�[

	int getNowTabX(), getNowTabY();
	int getNowCurX(),getNowCurY();
	int getTableX(int ROW,int COLUMN);
	int getTableY(int ROW, int COLUMN);
		

	//�v�Z�֌W
	inline void reset(){num=nRow=nColumn=0;};//���Z�b�g

	void calHori( );//�v�Z ���@���j���[(���ڐ��j�@���݂̔ԍ���Ԃ�
	void calVer( );//�v�Z �c�@���j���[(���ڐ��j�@���݂̔ԍ���Ԃ�
    void draw(int row,int col,int Brightness);//�`��
	void draw2(int row,int col,double zoom,int deg,int Brightness);//DrawRotaGraph(); ��]��Y�[���𗘗p (�{���A�p�x�j
		
	//�C�����C���֐�
	inline int getNum(){return num;}
	inline int getRow(){return row;}
	inline int getColumn(){return column;}
	inline int getNRow(){return nRow;}
	inline int getNColumn(){return nColumn;}
	inline int C_TableMenu::getTWidth(){return tWidth;}
	inline int C_TableMenu::getTHeight(){return tHeight;}


};

