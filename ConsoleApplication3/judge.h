#pragma once
#include<iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include"direction.h"
using namespace std;

class judge
{
public:
	int Judge()
	{
		//赢得游戏
		for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		if (game[i][j] == 2048)
		{
			return GAME_WIN;
			break;
		}

		//横向检查
		for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL - 1; ++j)
		if (!game[i][j] || (game[i][j] == game[i][j + 1]))
		{
			return GAME_CONTINUE;
			break;
		}

		//纵向检查
		for (int j = 0; j < COL; ++j)

		for (int i = 0; i < ROW - 1; ++i)

		if (!game[i][j] || (game[i][j] == game[i + 1][j]))
		{
			return GAME_CONTINUE;
			break;
		}



		//不符合上述两种状况，游戏结束
		return GAME_OVER;

	}

	int Judgespeed()
	{
		//赢得游戏
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL; ++j)

		if (game[i][j] == 64)
		{
			return GAME_WIN;
			break;
		}



		//横向检查
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL - 1; ++j)

		if (!game[i][j] || (game[i][j] == game[i][j + 1]))
		{
			return GAME_CONTINUE;
			break;
		}


		//纵向检查
		for (int j = 0; j < COL; ++j)

		for (int i = 0; i < ROW - 1; ++i)

		if (!game[i][j] || (game[i][j] == game[i + 1][j]))
		{
			return GAME_CONTINUE;
			break;
		}


		//不符合上述两种状况，游戏结束
		return GAME_OVER;
	}


	int Judgelong()
	{
		//赢得游戏
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL; ++j)

		if (game[i][j] == 4096)
		{
			return GAME_WIN;
			break;
		}



		//横向检查
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL - 1; ++j)

		if (!game[i][j] || (game[i][j] == game[i][j + 1]))
		{
			return GAME_CONTINUE;
			break;
		}


		//纵向检查
		for (int j = 0; j < COL; ++j)

		for (int i = 0; i < ROW - 1; ++i)

		if (!game[i][j] || (game[i][j] == game[i + 1][j]))
		{
			return GAME_CONTINUE;
			break;
		}

		//不符合上述两种状况，游戏结束
		return GAME_OVER;

	}
};