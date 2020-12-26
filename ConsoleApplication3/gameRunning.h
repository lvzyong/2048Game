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
	// 给数字赋值
	loadimage(&num2, "grachce图片\\QQ图片20190518161544.jpg", 40, 37);
	loadimage(&num4, "grachce图片\\QQ图片20190518161553.jpg", 40, 37);
	loadimage(&num8, "grachce图片\\QQ图片20190518161558.jpg", 40, 37);
	loadimage(&num16, "grachce图片\\QQ图片20190518161603.jpg", 40, 37);
	loadimage(&num32, "grachce图片\\QQ图片20190518161608.jpg", 40, 37);
	loadimage(&num64, "grachce图片\\QQ图片20190518161613.jpg", 40, 37);
	loadimage(&num128, "grachce图片\\QQ图片20190518161617.jpg", 40, 37);
	loadimage(&num256, "grachce图片\\QQ图片20190518170000.jpg", 40, 37);
	loadimage(&num512, "grachce图片\\QQ图片20190518161727.jpg", 40, 37);
	loadimage(&num1024, "grachce图片\\QQ图片20190518161637.jpg", 40, 37);
	loadimage(&num2048, "grachce图片\\QQ图片20190518161643.jpg", 40, 37);
	loadimage(&num4096, "grachce图片\\QQ图片20190518161647.jpg", 40, 37);

	//游戏板子
	loadimage(&BackgroundImg, "grachce图片\\1558166377238.jpg", 300, 300);

	//游戏背景
	loadimage(&bigGameBI, "grachce图片\\bigGameBackground.jpg", 400, 500);

	//分数板
	loadimage(&scoureBI, "grachce图片\\123.jpg", 135, 40);
}

GameDate::~GameDate()
{
}



void GameDate::clevernumber()//清除原表的数字
{
	putimage(50, 100, &BackgroundImg);
}

void GameDate::Shownumber()
{
	clevernumber();//清除原表的数字

	//打数字
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


//初始化背景和数字
void GameDate::initGame()
{
	// 绘图环境初始化
	initgraph(400, 500);
	setbkcolor(LIGHTGRAY);

	// 读取图片至绘图窗口
	putimage(0, 0, &bigGameBI);
	putimage(50, 100, &BackgroundImg);
	putimage(20, 20, &scoureBI);

	//设计字体
	settextcolor(BLACK);
	settextstyle(27, 0, _T("粗体"));
}

//更新分数
void  GameDate::renewScore()
{
	_stprintf(springScore, _T("%d"), score);      //把数字格式化输出为字符串
	outtextxy(70, 25, springScore);//输出分数
}