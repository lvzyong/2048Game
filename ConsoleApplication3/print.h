#pragma once
#include<iostream>
#include<cstdio>//用了sprintf
#include <windows.h>
#include <ctime>
#include <fstream>
#include"direction.h"
class print
{
	int input;
public:
	void instruction()//说明书
	{
		closegraph();
		initgraph(847, 430);
		setbkcolor(WHITE);
		IMAGE img11;
		loadimage(&img11, "grachce图片\\20140423162055_YmGsr.jpeg", 847, 430);
		settextstyle(30, 0, _T("宋体"));
		settextcolor(BLACK);
		putimage(0, 0, &img11);
		outtextxy(10, 10, "*******************************************************");
		outtextxy(10, 40, "*  每次可以选择上下左右任何一个方向去滑动，           *");
		outtextxy(10, 70, "*  每滑动一次，所有的数字方块都会往滑动的方向靠拢外， *");
		outtextxy(10, 100, "*  系统也会在空白的地方随机出现一个数字方块，         *");
		outtextxy(10, 130, "*  数字一般是2或4，相同数字的方块会相加成一个数字。   *");
		outtextxy(10, 160, "*  不断的叠加最终拼凑出2048这个数字就算成功           *");
		outtextxy(10, 190, "*******************************************************");
		outtextxy(670, 400, "按1键返回哦！");
		while (cin >> input)
		if (input == 1)
		{
			closegraph();
			break;
		}
	}

	void thekey()//按键说明
	{
		closegraph();
		initgraph(847, 430);
		setbkcolor(WHITE);
		IMAGE img11;
		loadimage(&img11, "grachce图片\\20140423162055_YmGsr.jpeg", 847, 430);
		settextstyle(30, 0, _T("宋体"));
		settextcolor(BLACK);
		putimage(0, 0, &img11);
		outtextxy(10, 10, "************************");
		outtextxy(10, 40, "*     游戏开始后：     *");
		outtextxy(10, 70, "*    ↑：向上移动      *");
		outtextxy(10, 100, "*    ↓：向下移动      *");
		outtextxy(10, 130, "*    ←：向左移动      *");
		outtextxy(10, 160, "*    →：向右移动      *");
		outtextxy(10, 190, "*在游戏界面按 Esc键退出*");
		outtextxy(10, 220, "************************");
		outtextxy(670, 400, "按1键返回哦！");
		while (cin >> input)
		if (input == 1)
		{
			closegraph();
			break;
		}
	}

	void forwardhigh()//看秘籍
	{
		closegraph();
		initgraph(847, 430);
		setbkcolor(WHITE);
		IMAGE img11;
		loadimage(&img11, "grachce图片\\20140423162055_YmGsr.jpeg", 847, 430);
		settextstyle(30, 0, _T("宋体"));
		settextcolor(BLACK);
		putimage(0, 0, &img11);
		outtextxy(10, 10, "*******************************************************");
		outtextxy(10, 40, "* 1、遇到连续合并的机会:从蓝色箭头开始的16可以一直合并*");
		outtextxy(10, 70, "*一般玩家遇到这样顺利的情况可能头脑一热就一下子合并过 *");
		outtextxy(10, 100, "*去了,但是在这里要告诉大家，这样快速合并是有风险的    *");
		outtextxy(10, 130, "*                                                     *");
		outtextxy(10, 160, "*2、合并数字:玩家可以先合并竖列的数字,          合并  *");
		outtextxy(10, 190, "*到64的时候,开始进入横排数字的合并。注意这时候64下面  *");
		outtextxy(10, 220, "*要有数字准备补充上来卡位                             *");
		outtextxy(10, 250, "*******************************************************");
		outtextxy(670, 400, "按1键返回哦！");
		while (cin >> input)
		{
			if (input == 1)
			{
				closegraph();
				break;
			}
		}
	}
};


void showRonk()//排行榜界面
{
	int input;
	closegraph();
	initgraph(658, 430);
	setbkcolor(WHITE);
	IMAGE img20;
	loadimage(&img20, "grachce图片\\PONK.JPG", 658, 430);
	putimage(0, 0, &img20);
	settextstyle(30, 0, _T("粗体"));
	settextcolor(BLACK);

	fstream data;
	int i(0), a[10];
	data.open("grachce图片\\Rank.txt");
	if (!data){//如果返回为非零
		cout << "Can not open Rank.txt!" << endl;
		exit(1);
	}
	while (data >> a[i] && i <= 8) i++;//读取Rank.txt的前8个元素
	data.close();//关闭data了，现在不需要用到文件读写了
	for (i = 0; i < 8; i++){//打印出分数
		char s[9];// 输出数值，先将数字格式化输出为字符串
		sprintf(s, "%d", a[i]);
		outtextxy(320,40*i+88 , s);
	}

	while (cin >> input)
	if (input == 1){
		closegraph();
		break;
	}
}