#pragma once
#include<graphics.h>
#include"wall.h"
#include"bb.h"
#include<ctime>
class tank {

private:
	IMAGE *tankinit;
	int x;										//̹������
	int y;
	int sx;										//̹����ͼƬʵ������
	int sy;
	int w;
	int h;
	int speed;									//̹���ٶ�
	int dir;									//����
	int tempt;									//���ʱ��
	bool flagw, flaga, flags, flagd;			//�����ǣ�����2֡ͼƬ����
	bool life;
	int loss;


public:

	int id;
	tank();
	void Setloss(int i) {
		loss = i;
	}
	int Getloss() { return loss; }
	void setXY(int x, int y) { this->x = x; this->y = y; }
	void setSpeed(int speed);					//����̹���ƶ��ٶ�
	int getDir() { return dir; }
	void setDir(int i) { dir = i; }
	int getX() { return x; }					//��ȡx
	int getY() { return y; }					//��ȡy
	void setSxy(int x, int y) { sx = x; sy = y; }
	bool getLife() { return life; }
	void setLife(bool l) {
		life = l;
	}

	int move(BB* b, int CountT, bool t);			//̹���ƶ�,���ں���
	int move(BB* b, int CountT, bool t, int * music);
	void setMove(bool t, int d, int CountT, BB*b);						//�ֶ��趨�ƶ�����
	void setMove(bool t, int CountT, BB* b);
	//void bb(BB* b);							//̹�˿���
	void caseHit(BB* b, int k, int* music);

	void show() {								//��ʾ̹��
		if (life) {
			putimage(x, y, w, h, tankinit, sx, sy);

		}
		else {
			if (id) {
				loss++;
				life = true;
				x = 150;
				y = 448;
				w = 26;
				h = 32;
				sx = 276;
				sy = 35;
				putimage(x, y, w, h, tankinit, sx, sy);
			}
		}

	}

};

class AI :public tank {
public:
	static int beataisum;
	AI() {
		setXY(2, 2);
		setSxy(38, 308);
		setLife(1);
	}
	void move(BB* b, int CountT, bool t, unsigned int n) {
		id = 0;

		setMove(t, n, CountT, b);
	}
	void move(BB* b, int CountT, bool t) {
		id = 0;

		setMove(t, CountT, b);
	}

};

