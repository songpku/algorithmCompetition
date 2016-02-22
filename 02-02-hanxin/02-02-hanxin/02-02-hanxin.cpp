// 02-02-hanxin.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
int main(){
	//freopen("02-02.txt", "r", stdin);
	int a, b, c;
	std::cout << scanf_s("%d", &a);
	while (scanf_s("%d%d%d", &a, &b, &c) == 1){
		printf("%d %d %d\n", a, b, c);
	}
}
