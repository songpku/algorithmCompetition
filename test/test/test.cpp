// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdio.h>
#include<iostream>
#include<string>
#define maxn 25
int n, k, m, num = 0;
int a[maxn];
void goAStep(int &start, int dire, int &step, int &stepN){
	do{
		start = (start + dire) < 0 ? n - 1 : (start + dire) % n;
		if (a[start] != 0)
			break;
	} while (true);
	step++;
	if (step == stepN){
		printf("%d ", a[start]);
		step = 0;
		num++;
		a[start] == 0;
	}
}
int main(){
	/*int AStart = -1, Adx = 1, AStepN, AStep = 0, BStart, Bdx = -1, BStepN, BStep = 0;
	scanf("%d%d%d", &n, &k, &m);
	AStepN = k;
	BStepN = m;
	BStart = n;
	for (int i = 0; i<n; i++){
		a[i] = i + 1;
	}
	while (num < n){
		goAStep(AStart, Adx, AStep, AStepN);
		goAStep(BStart, Bdx, BStep, BStepN);
	}

	/*return 0;*/
	/*std::string x;
	getline(std::cin, x);

	double a[5] = { 1};
	memset(a, -1, sizeof(double)*5);
	std::cout << (a[3] + 2);
	int b[3];
	memcpy(b, a, sizeof(int)* 3);*/

		FILE * fin;
		fin = fopen("data/03-05.txt", "r");
		char a[5][5];
		for (int i = 0; i<5; i++)
		for (int j = 0; j<5 && fscanf(fin,"%c", &a[i][j]); j++);
	
}
//int main(){
//	//for (int i = 192; i<333; i++){
//	//	int a[10] = {0}, b[10] = { 0 };
//	//	int B, C;
//	//	B = i * 2;
//	//	C = i * 3;
//	//	a[0] = i / 100;
//	//	a[1] = i % 100;
//	//	a[1] = a[1] / 10;
//	//	a[2] = i % 10;
//	//	a[3] = B / 100;
//	//	a[4] = B % 100;
//	//	a[4] = a[4] / 10;
//	//	a[5] = B % 10;
//	//	a[6] = C / 100;
//	//	a[7] = C % 10;
//	//	a[7] = a[7] / 10;
//	//	a[8] = C % 10;
//	//	for (int j = 0; j<10; j++){
//	//		if (a[j]!=-1)
//	//			b[a[j]] += 1;
//	//		//	printf("%d ",a[j]);
//	//	}
//	//	//	printf("\n");
//	//	int k = 0;
//	//	for (; k<10; k++){
//	//		if (b[k] > 1)
//	//			break;
//	//	}
//	//	if (k == 10)
//	//		printf("%d %d %d\n", i, B, C);
//	//}
//	int x = 0;
//	printf("%d",!x);
//}
