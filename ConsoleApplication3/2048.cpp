#include <graphics.h>
#include <conio.h>
#include"direction.h"
#include"print.h"
#include"judge.h"
#include"ronk.h"

IMAGE img2;

print Print;
direction Direction;
judge Judge;
int tag;

IMAGE BackgroundHome;

//打开主页面
void home()
{
	initgraph(847, 430);
	setbkcolor(WHITE);
	settextcolor(BLACK);

	putimage(0, 0, &BackgroundHome);
	settextstyle(80, 0, _T("粗体"));
	outtextxy(280, 50, "搞定2048");
	settextstyle(30, 0, _T("宋体"));
	outtextxy(200, 200, "1--说明书");
	outtextxy(200, 230, "2--按键操作");
	outtextxy(200, 260, "3--经典模式");
	outtextxy(200, 290, "4--极速模式");
	outtextxy(500, 200, "5--王者模式");
	outtextxy(500, 230, "6--记时模式");
	outtextxy(500, 260, "7--进阶秘籍");
	outtextxy(500, 290, "8--排行榜");
	outtextxy(200, 320, "0--退出游戏");//第一个参数是列，第二个参数是行
}


void Result(bool a)
{
	setbkcolor(BROWN);
	settextstyle(50, 0, _T("粗体"));
	if (a == true)
		outtextxy(100, 300, "恭喜哇！胜利！");
	else
		outtextxy(100, 300, "再接再励哇！");
}

// 主函数
int main()
{
	loadimage(&BackgroundHome, "grachce图片\\20140423162055_YmGsr.jpeg", 847, 430); //加载homeBackground
	home();//主界面
	while (cin >> tag)
	{
		if (tag == 1){
			Print.instruction();
		}
		else if (tag == 2)
			Print.thekey();

		else if (tag == 3)//经典模式
		{
			//设置一个随机数种子
			srand((unsigned int)time(0));
			CreateNumber();
			CreateNumber();
			closegraph();
			curGameD.initGame();
			curGameD.Shownumber();
			int direction = 0;
			int gameState = -1;
			while (true)
			{
				direction = Direction.Input();
				gameState = Judge.Judge();
				if (direction == 88){  //按了Esc键就退出while,相当与回到了主页面
					break;
				}//if
				if (direction && gameState == GAME_CONTINUE)
				{
					Direction.Process(direction);
					curGameD.renewScore();
				}
				else if (gameState == GAME_WIN)
				{
					curGameD.Shownumber();
					Result(1);//输出结果
					Sleep(999);
					ranking(score);//得分传给了rank
					break;
				}
				else if (gameState == GAME_OVER)
				{
					curGameD.Shownumber();
					Result(0);
					Sleep(999);
					break;
				}//else if
			}//input while
		}//extren else if

		else if (tag == 4)//快速模式
		{
			//设置一个随机数种子
			srand((unsigned int)time(0));
			CreateNumber();
			CreateNumber();
			closegraph();//关闭home界面

			curGameD.initGame();
			curGameD.Shownumber();

			int direction = 0;
			int gameState = -1;
			while (true)
			{
				direction = Direction.Input();
				gameState = Judge.Judgespeed();
				if (direction == 88){
					break;
				}//if
				if (direction && gameState == GAME_CONTINUE)
				{
					Direction.Process(direction);
					curGameD.renewScore();
				}
				else if (gameState == GAME_WIN)
				{
					curGameD.Shownumber();
					Result(1);
					Sleep(999);
					//getch();
					ranking(score);
					break;
				}
				else if (gameState == GAME_OVER)
				{
					curGameD.Shownumber();
					Result(0);
					Sleep(999);
					break;
				}
			}
		}

		else if (tag == 5)//王者模式
		{
			//设置一个随机数种子
			srand((unsigned int)time(0));
			CreateNumber();
			CreateNumber();
			closegraph();
			curGameD.initGame();
			curGameD.Shownumber();

			int direction = 0;
			int gameState = -1;
			while (true)
			{
				direction = Direction.Input();
				gameState = Judge.Judgelong();
				if (direction == 88){
					break;
				}//if
				if (direction && gameState == GAME_CONTINUE)
				{
					Direction.Process(direction);
					curGameD.renewScore();
				}//if
				else if (gameState == GAME_WIN)
				{
					curGameD.Shownumber();
					Result(1);
					Sleep(999);
					ranking(score);
					break;
				}
				else if (gameState == GAME_OVER)
				{
					curGameD.Shownumber();
					Result(0);
					Sleep(999);
					break;
				}
			}
		}

		else if (tag == 6)//计时模式
		{
			clock_t start, finish;
			int totaltime;
			start = clock();
			srand((unsigned int)time(0));

			CreateNumber();
			CreateNumber();
			closegraph();
			curGameD.initGame();
			curGameD.Shownumber();
			int direction = 0;
			int gameState = -1;
			while (true)
			{
				direction = Direction.Input();
				gameState = Judge.Judgespeed();
				if (direction == 88){
					break;
				}//if
				if (direction && gameState == GAME_CONTINUE)
				{
					Direction.Process(direction);
					curGameD.renewScore();
				}
				else if (gameState == GAME_WIN)
				{
					curGameD.Shownumber();
					Result(1);
					ranking(score);
					break;
				}
				else if (gameState == GAME_OVER)
				{
					curGameD.Shownumber();
					Result(0);
					break;
				}
			}

			finish = clock();
			totaltime = (int)(finish - start) / CLOCKS_PER_SEC;
			settextstyle(30, 0, _T("粗体"));
			outtextxy(200, 400, "完成时间:");

			char *stringTotalTime;
			_stprintf(stringTotalTime, _T("%d"), totaltime);      //把数字格式化输出为字符串
			outtextxy(250, 430, stringTotalTime);
			outtextxy(275, 430, "s");
			Sleep(4000);
		}

		else if (tag == 7){
			Print.forwardhigh();
		}

		else if (tag == 8){
			showRonk();
		}

		else if (tag == 0)
			exit(0);

		for (int i = 0; i < ROW; i++)//把游戏初始化为零
		for (int j = 0; j < COL; j++)
			game[i][j] = 0;
		score = 0;

		home();//回到主界面
	}//whlie
	return 0;
}
