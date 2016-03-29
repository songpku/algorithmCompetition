// wy1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
const int MAXK = 5;
const int MAXN = 1000000000;
int s, kK, n;
vector<vector<int> > light;
vector<vector<int> > lightResult;
int light[8][10] = {
	{ 0, 1, 2, 3, 4, 5, 6, 7 ,8, 9},
	{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 1 }, //1
	{ 1, 0, 0, 0, 1, 1, 1, 0, 1, 1 },  //2
	{ 1, 1, 1, 1,1, 1, 0, 1, 1, 1 },//3
	{ 0, 0, 1, 1, 1, 1, 1, 0, 1, 1 },//4
	{ 1, 0, 1, 0, 0, 0, 1, 0, 1, 0 },//5
	{ 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },//6
	{ 1, 0, 1, 1, 0, 1, 1, 0, 1, 1 },//7
};
int a[5][10] = { 0 };
int result = 0;
void slove(int i, int x){
	if (x == 1){
		for (int k = 0; k < 10; k++){
			if ((a[kK-x][k] == 1) && ((i * 10 + k) < n)){
				//printf("%d\n", i * 10 + k);
				result++;
		}
		}
		return;
	}
	for (int k = 0; k < 10; k++){
		if (a[kK - x][k] == 1)
			slove(i*10+k, x-1);
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("../data/wy1.txt", "r", stdin);
	scanf("%d", &s);
	string str;
	for (int i = 0; i < s; i++){
		scanf("%d%d", &kK, &n);
		light.clear();
		lightResult.clear();
		getline(cin, str);
		for (int j = 0; j < kK; j++){
		
			getline(cin, str);
			vector<int> temp;
			for (int k=0; k < str.length(); k++){
				int x = str[k] - '0';
				if (x >= 1 && x <= 7){
					temp.push_back(x);
				}
			}
			if (temp.size() >0)
				light.push_back(temp);
		}
		
		memset(a, 1, sizeof(a));
		for (int j = 0; j < kK; j++){
			for (int k = 0; k < light[j].size(); k++){
				int x = light[j][k];
				for (int q = 0; q < 10; q++){
					a[j][q] &= light[x][q];
				}
			}
		
		}
		result = 0;
		slove(0, kK);
		printf("%d\n", result);
		/*for (int j = 0; j < kK; j++){
			int b[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			for (int k = 1; k < 8; k++){
				if (a[j][k] == 0){
					for (int q = 0; q < 10; q++){
						b[q] = b[q] & nolight[k-1][q];
					}
				}
			}
			vector<int> vecTmp;
			for (int k = 0; k < 10; k++){
				if (b[k] == 1){
					vecTmp.push_back(k);
				}
			}
			lightResult.push_back(vecTmp);
		}
		for (int j = 0; j < kK; j++){
			int b[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
			for (int k = 0; k < 7; k++){
				if (a[j][k] == -1){
				
				}
			}
		}
		int c[5] = {10000,1000,100,10,1};*/
		

		
	}
	return 0;
}

