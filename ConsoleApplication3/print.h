#pragma once
#include<iostream>
#include<cstdio>//����sprintf
#include <windows.h>
#include <ctime>
#include <fstream>
#include"direction.h"
class print
{
	int input;
public:
	void instruction()//˵����
	{
		closegraph();
		initgraph(847, 430);
		setbkcolor(WHITE);
		IMAGE img11;
		loadimage(&img11, "grachceͼƬ\\20140423162055_YmGsr.jpeg", 847, 430);
		settextstyle(30, 0, _T("����"));
		settextcolor(BLACK);
		putimage(0, 0, &img11);
		outtextxy(10, 10, "*******************************************************");
		outtextxy(10, 40, "*  ÿ�ο���ѡ�����������κ�һ������ȥ������           *");
		outtextxy(10, 70, "*  ÿ����һ�Σ����е����ַ��鶼���������ķ���£�⣬ *");
		outtextxy(10, 100, "*  ϵͳҲ���ڿհ׵ĵط��������һ�����ַ��飬         *");
		outtextxy(10, 130, "*  ����һ����2��4����ͬ���ֵķ������ӳ�һ�����֡�   *");
		outtextxy(10, 160, "*  ���ϵĵ�������ƴ�ճ�2048������־���ɹ�           *");
		outtextxy(10, 190, "*******************************************************");
		outtextxy(670, 400, "��1������Ŷ��");
		while (cin >> input)
		if (input == 1)
		{
			closegraph();
			break;
		}
	}

	void thekey()//����˵��
	{
		closegraph();
		initgraph(847, 430);
		setbkcolor(WHITE);
		IMAGE img11;
		loadimage(&img11, "grachceͼƬ\\20140423162055_YmGsr.jpeg", 847, 430);
		settextstyle(30, 0, _T("����"));
		settextcolor(BLACK);
		putimage(0, 0, &img11);
		outtextxy(10, 10, "************************");
		outtextxy(10, 40, "*     ��Ϸ��ʼ��     *");
		outtextxy(10, 70, "*    ���������ƶ�      *");
		outtextxy(10, 100, "*    ���������ƶ�      *");
		outtextxy(10, 130, "*    ���������ƶ�      *");
		outtextxy(10, 160, "*    ���������ƶ�      *");
		outtextxy(10, 190, "*����Ϸ���水 Esc���˳�*");
		outtextxy(10, 220, "************************");
		outtextxy(670, 400, "��1������Ŷ��");
		while (cin >> input)
		if (input == 1)
		{
			closegraph();
			break;
		}
	}

	void forwardhigh()//���ؼ�
	{
		closegraph();
		initgraph(847, 430);
		setbkcolor(WHITE);
		IMAGE img11;
		loadimage(&img11, "grachceͼƬ\\20140423162055_YmGsr.jpeg", 847, 430);
		settextstyle(30, 0, _T("����"));
		settextcolor(BLACK);
		putimage(0, 0, &img11);
		outtextxy(10, 10, "*******************************************************");
		outtextxy(10, 40, "* 1�����������ϲ��Ļ���:����ɫ��ͷ��ʼ��16����һֱ�ϲ�*");
		outtextxy(10, 70, "*һ�������������˳�����������ͷ��һ�Ⱦ�һ���Ӻϲ��� *");
		outtextxy(10, 100, "*ȥ��,����������Ҫ���ߴ�ң��������ٺϲ����з��յ�    *");
		outtextxy(10, 130, "*                                                     *");
		outtextxy(10, 160, "*2���ϲ�����:��ҿ����Ⱥϲ����е�����,          �ϲ�  *");
		outtextxy(10, 190, "*��64��ʱ��,��ʼ����������ֵĺϲ���ע����ʱ��64����  *");
		outtextxy(10, 220, "*Ҫ������׼������������λ                             *");
		outtextxy(10, 250, "*******************************************************");
		outtextxy(670, 400, "��1������Ŷ��");
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


void showRonk()//���а����
{
	int input;
	closegraph();
	initgraph(658, 430);
	setbkcolor(WHITE);
	IMAGE img20;
	loadimage(&img20, "grachceͼƬ\\PONK.JPG", 658, 430);
	putimage(0, 0, &img20);
	settextstyle(30, 0, _T("����"));
	settextcolor(BLACK);

	fstream data;
	int i(0), a[10];
	data.open("grachceͼƬ\\Rank.txt");
	if (!data){//�������Ϊ����
		cout << "Can not open Rank.txt!" << endl;
		exit(1);
	}
	while (data >> a[i] && i <= 8) i++;//��ȡRank.txt��ǰ8��Ԫ��
	data.close();//�ر�data�ˣ����ڲ���Ҫ�õ��ļ���д��
	for (i = 0; i < 8; i++){//��ӡ������
		char s[9];// �����ֵ���Ƚ����ָ�ʽ�����Ϊ�ַ���
		sprintf(s, "%d", a[i]);
		outtextxy(320,40*i+88 , s);
	}

	while (cin >> input)
	if (input == 1){
		closegraph();
		break;
	}
}