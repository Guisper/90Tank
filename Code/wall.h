#pragma once
#include<graphics.h>
#include"bb.h"
#include"tankbase.h"
/******************************ǽ��*********************************/
class wall {
private:

	int sx, sy;
	IMAGE* wallImg;									//�洢ǽͼ


public:
	bool* life;										//�ж�wall�Ƿ����
	wall();											//��ʼ��
	bool showWall(int w[11], int h[11]);				//��ȡ��ͼ�����ļ���������ͼ
	void caseHit(BB *b);							//����Ƿ��ӵ����



};
/*******************************************************************/