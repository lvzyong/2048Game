#pragma once

#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(int a, int b){//降序排序
	return a > b;
}


void ranking(int Score)
{
	//排序
	int a[200], i, n;
	fstream in, out;
	memset(a, 0, sizeof(a));

	in.open("grachce图片\\Rank.txt", ios::in);
	if (!in){
		cout << "Can not open Rank.txt!" << endl;
		exit(1);
	}

	out.open("grachce图片\\Result.txt", ios::out);
	if (!out){
		cout << "Can not open Result.txt!" << endl;
		exit(2);
	}
	a[0] = Score;
	i = 1;//把Rank.txt的数据读入a[1]及其以后，a[0]储了本次的得分
	while (in >> a[i]) // 循环结束后，i是已读入整数的个数
		i++;
	n = i;//一共有n个元素
	sort(a, a + n,cmp);

	for (i = 0; i < n; i++)//把排序好的n个数，存到out.txt中
		out << a[i] << " ";

	in.close();
	out.close();

	//复制操作,将out.txt的内容复制到in.txt中
	char ch;
	fstream  infile("grachce图片\\Result.txt", ios::in);
	if (!infile){//为了安全
		cout << "Can not open input file: Result.txt" << endl;
		exit(1);
	}
	fstream  outfile("grachce图片\\Rank.txt", ios::out);
	if (!outfile){//为了安全
		cout << "Can not open output file: Rank.txt" << endl;
		exit(2);
	}
	while (infile.get(ch))
		outfile << ch;

	infile.close();
	outfile.close();
}