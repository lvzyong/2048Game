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
		//Ӯ����Ϸ
		for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL; ++j)
		if (game[i][j] == 2048)
		{
			return GAME_WIN;
			break;
		}

		//������
		for (int i = 0; i < ROW; ++i)
		for (int j = 0; j < COL - 1; ++j)
		if (!game[i][j] || (game[i][j] == game[i][j + 1]))
		{
			return GAME_CONTINUE;
			break;
		}

		//������
		for (int j = 0; j < COL; ++j)

		for (int i = 0; i < ROW - 1; ++i)

		if (!game[i][j] || (game[i][j] == game[i + 1][j]))
		{
			return GAME_CONTINUE;
			break;
		}



		//��������������״������Ϸ����
		return GAME_OVER;

	}

	int Judgespeed()
	{
		//Ӯ����Ϸ
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL; ++j)

		if (game[i][j] == 64)
		{
			return GAME_WIN;
			break;
		}



		//������
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL - 1; ++j)

		if (!game[i][j] || (game[i][j] == game[i][j + 1]))
		{
			return GAME_CONTINUE;
			break;
		}


		//������
		for (int j = 0; j < COL; ++j)

		for (int i = 0; i < ROW - 1; ++i)

		if (!game[i][j] || (game[i][j] == game[i + 1][j]))
		{
			return GAME_CONTINUE;
			break;
		}


		//��������������״������Ϸ����
		return GAME_OVER;
	}


	int Judgelong()
	{
		//Ӯ����Ϸ
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL; ++j)

		if (game[i][j] == 4096)
		{
			return GAME_WIN;
			break;
		}



		//������
		for (int i = 0; i < ROW; ++i)

		for (int j = 0; j < COL - 1; ++j)

		if (!game[i][j] || (game[i][j] == game[i][j + 1]))
		{
			return GAME_CONTINUE;
			break;
		}


		//������
		for (int j = 0; j < COL; ++j)

		for (int i = 0; i < ROW - 1; ++i)

		if (!game[i][j] || (game[i][j] == game[i + 1][j]))
		{
			return GAME_CONTINUE;
			break;
		}

		//��������������״������Ϸ����
		return GAME_OVER;

	}
};