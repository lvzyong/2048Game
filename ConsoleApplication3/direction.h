#pragma once
#include<iostream>
#include <windows.h>
#include <ctime>　/*功 能: 把日期和时间转换为字符串*/
#include <fstream>
#include"gameRunning.h"
#include"extrenVariable.h"
using namespace std;


//上下左右
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//游戏所处的状态
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
	//三分之二的概率生成2，三分之一的概率生成4。
	int whitch = rand() % 3;//0 1 2
	do
	{
		x = rand() % ROW;//x=0 1 2 3
		y = rand() % COL;//y=0 1 2 3
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//说明格子已经满了
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
			//最上面一行不动
			for (int row = 1; row < ROW; ++row)
			{
				for (int crow = row; crow >= 1; --crow)//每一行都动
				{
					for (int col = 0; col < COL; ++col)
					{
						//上一个格子为空
						if (game[crow - 1][col] == 0)
						{
							game[crow - 1][col] = game[crow][col];
							game[crow][col] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[crow - 1][col] == game[crow][col])//合并
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
			//最下面一行不动
			for (int row = ROW - 2; row >= 0; --row)
			{
				for (int crow = row; crow < ROW - 1; ++crow)
				{
					for (int col = 0; col < COL; ++col)
					{
						//上一个格子为空
						if (game[crow + 1][col] == 0)
						{
							game[crow + 1][col] = game[crow][col];
							game[crow][col] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[crow + 1][col] == game[crow][col]) //合并
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
			//最左边一列不动
			for (int col = 1; col < COL; ++col)
			{
				for (int ccol = col; ccol >= 1; --ccol)
				{
					for (int row = 0; row < ROW; ++row)
					{
						//上一个格子为空
						if (game[row][ccol - 1] == 0)
						{
							game[row][ccol - 1] = game[row][ccol];
							game[row][ccol] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[row][ccol - 1] == game[row][ccol]) //合并
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
			//最右边一列不动
			for (int col = COL - 2; col >= 0; --col)
			{
				for (int ccol = col; ccol <= COL - 2; ++ccol)
				{
					for (int row = 0; row < ROW; ++row)
					{
						//上一个格子为空
						if (game[row][ccol + 1] == 0)
						{
							game[row][ccol + 1] = game[row][ccol];
							game[row][ccol] = 0;
							curGameD.Shownumber();
							isMove = true;
							Sleep(10);
						}
						else if (game[row][ccol + 1] == game[row][ccol])  //合并
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



	//处理输入输出，返回上下左右
	int Input()
	{
		//读取上下左右四个方向键以及退出键
		int upArrow = 0;
		int downArrow = 0;
		int leftArrow = 0;
		int rightArrow = 0;
		int direction = 0;
		int Exit = 0;
		while (true)
		{
			/*而GetAsyncKeyState 读取的是物理键状态，也是就是不管你怎么鼠标键盘映射，它只读取实际的按键状态。*/
			upArrow = GetAsyncKeyState(VK_UP);/* VK_UP中系统定义的值*/
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
