#pragma once

#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(int a, int b){//��������
	return a > b;
}


void ranking(int Score)
{
	//����
	int a[200], i, n;
	fstream in, out;
	memset(a, 0, sizeof(a));

	in.open("grachceͼƬ\\Rank.txt", ios::in);
	if (!in){
		cout << "Can not open Rank.txt!" << endl;
		exit(1);
	}

	out.open("grachceͼƬ\\Result.txt", ios::out);
	if (!out){
		cout << "Can not open Result.txt!" << endl;
		exit(2);
	}
	a[0] = Score;
	i = 1;//��Rank.txt�����ݶ���a[1]�����Ժ�a[0]���˱��εĵ÷�
	while (in >> a[i]) // ѭ��������i���Ѷ��������ĸ���
		i++;
	n = i;//һ����n��Ԫ��
	sort(a, a + n,cmp);

	for (i = 0; i < n; i++)//������õ�n�������浽out.txt��
		out << a[i] << " ";

	in.close();
	out.close();

	//���Ʋ���,��out.txt�����ݸ��Ƶ�in.txt��
	char ch;
	fstream  infile("grachceͼƬ\\Result.txt", ios::in);
	if (!infile){//Ϊ�˰�ȫ
		cout << "Can not open input file: Result.txt" << endl;
		exit(1);
	}
	fstream  outfile("grachceͼƬ\\Rank.txt", ios::out);
	if (!outfile){//Ϊ�˰�ȫ
		cout << "Can not open output file: Rank.txt" << endl;
		exit(2);
	}
	while (infile.get(ch))
		outfile << ch;

	infile.close();
	outfile.close();
}