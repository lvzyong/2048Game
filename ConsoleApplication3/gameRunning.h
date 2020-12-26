#pragma once
#include <graphics.h>
#include <conio.h>
#include"extrenVariable.h"

class GameDate
{
public:
	GameDate();
	~GameDate();
	void clevernumber();
	void Shownumber();
	void initGame();
	void renewScore();

private:
	IMAGE BackgroundImg;
	IMAGE bigGameBI;
	IMAGE scoureBI;
	IMAGE num2, num4, num8, num16, num32, num64, num128, num256, num512, num1024, num2048, num4096;
	char springScore[7];
};

GameDate::GameDate()
{
	// �����ָ�ֵ
	loadimage(&num2, "grachceͼƬ\\QQͼƬ20190518161544.jpg", 40, 37);
	loadimage(&num4, "grachceͼƬ\\QQͼƬ20190518161553.jpg", 40, 37);
	loadimage(&num8, "grachceͼƬ\\QQͼƬ20190518161558.jpg", 40, 37);
	loadimage(&num16, "grachceͼƬ\\QQͼƬ20190518161603.jpg", 40, 37);
	loadimage(&num32, "grachceͼƬ\\QQͼƬ20190518161608.jpg", 40, 37);
	loadimage(&num64, "grachceͼƬ\\QQͼƬ20190518161613.jpg", 40, 37);
	loadimage(&num128, "grachceͼƬ\\QQͼƬ20190518161617.jpg", 40, 37);
	loadimage(&num256, "grachceͼƬ\\QQͼƬ20190518170000.jpg", 40, 37);
	loadimage(&num512, "grachceͼƬ\\QQͼƬ20190518161727.jpg", 40, 37);
	loadimage(&num1024, "grachceͼƬ\\QQͼƬ20190518161637.jpg", 40, 37);
	loadimage(&num2048, "grachceͼƬ\\QQͼƬ20190518161643.jpg", 40, 37);
	loadimage(&num4096, "grachceͼƬ\\QQͼƬ20190518161647.jpg", 40, 37);

	//��Ϸ����
	loadimage(&BackgroundImg, "grachceͼƬ\\1558166377238.jpg", 300, 300);

	//��Ϸ����
	loadimage(&bigGameBI, "grachceͼƬ\\bigGameBackground.jpg", 400, 500);

	//������
	loadimage(&scoureBI, "grachceͼƬ\\123.jpg", 135, 40);
}

GameDate::~GameDate()
{
}



void GameDate::clevernumber()//���ԭ�������
{
	putimage(50, 100, &BackgroundImg);
}

void GameDate::Shownumber()
{
	clevernumber();//���ԭ�������

	//������
	for (int i = 0; i < ROW; i++)
	for (int j = 0; j < COL; j++)
	switch (game[i][j])
	{
		case 2:
			putimage(65 + 46 * j, 110 + 40 * i, &num2);
			break;
		case 4:
			putimage(65 + 46 * j, 110 + 40 * i, &num4);
			break;
		case 8:
			putimage(65 + 46 * j, 110 + 40 * i, &num8);
			break;
		case 16:
			putimage(65 + 46 * j, 110 + 40 * i, &num16);
			break;
		case 32:
			putimage(65 + 46 * j, 110 + 40 * i, &num32);
			break;
		case 64:
			putimage(65 + 46 * j, 110 + 40 * i, &num64);
			break;
		case 128:
			putimage(65 + 46 * j, 110 + 40 * i, &num128);
			break;
		case 256:
			putimage(65 + 46 * j, 110 + 40 * i, &num256);
			break;
		case 512:
			putimage(65 + 46 * j, 110 + 40 * i, &num512);
			break;
		case 1024:
			putimage(65 + 46 * j, 110 + 40 * i, &num1024);
			break;
		case 2048:
			putimage(65 + 46 * j, 110 + 40 * i, &num2048);
			break;
		case 4096:
			putimage(65 + 46 * j, 110 + 40 * i, &num4096);
			break;
	}
}


//��ʼ������������
void GameDate::initGame()
{
	// ��ͼ������ʼ��
	initgraph(400, 500);
	setbkcolor(LIGHTGRAY);

	// ��ȡͼƬ����ͼ����
	putimage(0, 0, &bigGameBI);
	putimage(50, 100, &BackgroundImg);
	putimage(20, 20, &scoureBI);

	//�������
	settextcolor(BLACK);
	settextstyle(27, 0, _T("����"));
}

//���·���
void  GameDate::renewScore()
{
	_stprintf(springScore, _T("%d"), score);      //�����ָ�ʽ�����Ϊ�ַ���
	outtextxy(70, 25, springScore);//�������
}