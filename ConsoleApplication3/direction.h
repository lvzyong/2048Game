#pragma once
#include<iostream>
#include <windows.h>
#include <ctime>��/*�� ��: �����ں�ʱ��ת��Ϊ�ַ���*/
#include <fstream>
#include"gameRunning.h"
#include"extrenVariable.h"
using namespace std;


//��������
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//��Ϸ������״̬
int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;

GameDate curGameD;

enum GameNum
{
	Game_2 = 2,
	Game_4 = 4,
	Game_8 = 8,
	Game_16 = 16,
	Game_32 = 32,
	Game_64 = 64,
	Game_128 = 128,
	Game_256 = 256,
	Game_512 = 512,
	Game_1024 = 1024,
	Game_2048 = 2048,
};

bool CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW * COL;
	//����֮���ĸ�������2������֮һ�ĸ�������4��
	int whitch = rand() % 3;//0 1 2
	do
	{
		x = rand() % ROW;//x=0 1 2 3
		y = rand() % COL;//y=0 1 2 3
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//˵�������Ѿ�����
	if (times >= maxTimes)
		return false;
	else
	{
		GameNum num;
		if (whitch == 0)
			num = Game_4;
		else if (whitch)
			num = Game_2;
		game[x][y] = num;
	}

	return true;
}

class direction
{
private:
	bool isMove;

public:
	void Process(int direction)
	{
		isMove = false;
		switch (direction)
		{
		case UP:
			//������һ�в���
			for (int row = 1; row < ROW; ++row)
			{
				for (int crow = row; crow >= 1; --crow)//ÿһ�ж���
				{
					for (int col = 0; col < COL; ++col)
					{
						//��һ������Ϊ��
						if (game[crow - 1][col] == 0)
						{
							game[crow - 1][col] = game[crow][col];
							game[crow][col] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[crow - 1][col] == game[crow][col])//�ϲ�
						{
							game[crow - 1][col] *= 2;
							score += game[crow - 1][col];
							game[crow][col] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}//else if
					}//inner for
				}
			} //extren for

			break;
		case DOWN:
			//������һ�в���
			for (int row = ROW - 2; row >= 0; --row)
			{
				for (int crow = row; crow < ROW - 1; ++crow)
				{
					for (int col = 0; col < COL; ++col)
					{
						//��һ������Ϊ��
						if (game[crow + 1][col] == 0)
						{
							game[crow + 1][col] = game[crow][col];
							game[crow][col] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[crow + 1][col] == game[crow][col]) //�ϲ�
						{
							game[crow + 1][col] *= 2;
							score += game[crow + 1][col];
							game[crow][col] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}//else if
					}
				}//median for
			}
			break;
		case LEFT:
			//�����һ�в���
			for (int col = 1; col < COL; ++col)
			{
				for (int ccol = col; ccol >= 1; --ccol)
				{
					for (int row = 0; row < ROW; ++row)
					{
						//��һ������Ϊ��
						if (game[row][ccol - 1] == 0)
						{
							game[row][ccol - 1] = game[row][ccol];
							game[row][ccol] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[row][ccol - 1] == game[row][ccol]) //�ϲ�
						{
							game[row][ccol - 1] *= 2;
							score += game[row][ccol - 1];
							game[row][ccol] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}//else if
					}//inner for
				}
			}
			break;
		case RIGHT:
			//���ұ�һ�в���
			for (int col = COL - 2; col >= 0; --col)
			{
				for (int ccol = col; ccol <= COL - 2; ++ccol)
				{
					for (int row = 0; row < ROW; ++row)
					{
						//��һ������Ϊ��
						if (game[row][ccol + 1] == 0)
						{
							game[row][ccol + 1] = game[row][ccol];
							game[row][ccol] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[row][ccol + 1] == game[row][ccol])  //�ϲ�
						{
							game[row][ccol + 1] *= 2;
							score += game[row][ccol + 1];
							game[row][ccol] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}//else if

					}
				}
			}
			break;
		}//switch

		if (isMove){
			CreateNumber();
		}//if
	}



	//�������������������������
	int Input()
	{
		//��ȡ���������ĸ�������Լ��˳���
		int upArrow = 0;
		int downArrow = 0;
		int leftArrow = 0;
		int rightArrow = 0;
		int direction = 0;
		int Exit = 0;
		while (true)
		{
			/*��GetAsyncKeyState ��ȡ���������״̬��Ҳ�Ǿ��ǲ�������ô������ӳ�䣬��ֻ��ȡʵ�ʵİ���״̬��*/
			upArrow = GetAsyncKeyState(VK_UP);/* VK_UP��ϵͳ�����ֵ*/
			downArrow = GetAsyncKeyState(VK_DOWN);
			leftArrow = GetAsyncKeyState(VK_LEFT);
			rightArrow = GetAsyncKeyState(VK_RIGHT);
			Exit = GetAsyncKeyState(VK_ESCAPE);

			if (upArrow)
			{
				direction = UP;
				break;
			}
			else if (downArrow)
			{
				direction = DOWN;
				break;
			}
			else if (leftArrow)
			{
				direction = LEFT;
				break;
			}
			else if (rightArrow)
			{
				direction = RIGHT;
				break;
			}
			else if (Exit){
				direction = 88;
				break;
			}

			Sleep(100);
		}

		return direction;
	}

};
