// algorithmCompetitionAll.cpp : 定义控制台应用程序的入口点。
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
	int maxLen = 0, len;
	while (scanf("%d", &iSize) == 1){
		maxLen = 0;
		for (int i = 0; i < iSize; i++){
			scanf("%s", strName);
			len = strlen(strName);
			maxLen = max(maxLen, len);
			fileList[i] = strName;
		}

}