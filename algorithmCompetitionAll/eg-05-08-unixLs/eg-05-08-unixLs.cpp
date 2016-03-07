// eg-05-08-unixLs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 60;
struct FILEInfo{
	string name;
	int length;
	FILEInfo(string _name = "", int _length = 0) :name(_name), length(_length){}
};
int main()
{
	freopen("..\\data\\05-08.txt", "r", stdin);
	int iSize;
	char strName[MAXN + 1];
	vector<FILEInfo> fileList;
	while (scanf("%d", &iSize) == 1){
		for (int i = 0; i < iSize; i++){
			scanf("%s", strName);
			FILEInfo fileName
		}
	}

	return 0;
}

