// eg-05-08-unixls-ac.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

int const MAXN = 60;
string fileList[100];
void showAName(string name, int num){
	printf("%s", name.c_str());
	for (int i = 0; i < num - name.size(); i++){
		printf(" ");
	}
}
int main(){
	//freopen("..\\data\\05-08.txt", "r", stdin);
	int iSize;
	char strName[MAXN + 1];
	int maxLen = 0, len, nameNum = 0;
	while (scanf("%d", &iSize) == 1){
		maxLen = 0;
		nameNum = 0;
		for (int i = 0; i < iSize; i++){
			scanf("%s", strName);
			len = strlen(strName);
			maxLen = max(maxLen, len);
			fileList[i] = strName;
			nameNum++;
		}
		sort(fileList, fileList + nameNum);
		for (int i = 0; i < MAXN; i++)
			printf("-");
		printf("\n");
		int cols = (MAXN - maxLen) / (maxLen + 2) + 1;
		int rows = (nameNum - 1) / cols + 1;
		int index = 0;
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				index = i + j * rows;
				if (index < nameNum)
					showAName(fileList[index], j < cols - 1 ? maxLen + 2 : maxLen);

			}
			printf("\n");
		}
	}
	
}