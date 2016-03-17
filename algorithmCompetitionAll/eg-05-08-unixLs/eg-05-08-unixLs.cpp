// eg-05-08-unixLs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string>
#include<vector>
#include <cstring>
#include<algorithm>
using namespace std;
const int MAXN = 60;
struct FILEInfo{
	string name;
	int length;
	FILEInfo(string _name = "", int _length = 0) :name(_name), length(_length){}
};
bool cmp(FILEInfo &a, FILEInfo &b){ return a.name < b.name; }
void showANoRightFilename(string name,int maxlen){
	printf("%s", name.c_str());
	for (int i = 0; i < maxlen - name.size() + 2; i++){
		printf(" ");
	}
}
string output[100][100];
int main()
{
	//freopen("..\\data\\05-08.txt", "r", stdin);
	int iSize;
	char strName[MAXN + 1];
	vector<FILEInfo> fileList;
	int maxLen=0, len;
	while (scanf("%d", &iSize) == 1){
		maxLen = 0;
		fileList.clear();
		for (int i = 0; i < iSize; i++){
			scanf("%s", strName);
			len = strlen(strName);
			maxLen = max(maxLen,len);
			FILEInfo fileName(strName, len);
			fileList.push_back(fileName);
		}
		int colNum = (MAXN - maxLen) / (maxLen + 2) + 1;
		sort(fileList.begin(), fileList.end(), cmp);
		for (int i = 0; i < MAXN; i++)
			printf("-");
		printf("\n");
		int rows = fileList.size() / colNum;
		int iMod = fileList.size() % colNum;
		int modTemp = iMod;
		int index = 0;
		for (int i = 0; i < colNum; i++,modTemp--){
			if (modTemp >0){
				for (int j = 0; j < rows + 1; j++){
					output[j][i] = fileList[index].name;
					index++;
				}
			}
			else{
				for (int j = 0; j < rows && index < fileList.size(); j++){
					output[j][i] = fileList[index].name;
					index++;
				}
			}
		}
		index = 0;
		for (int i = 0; i < rows + (iMod >0 ? 1 : 0); i++){
			int j = 0;
			for (; j < colNum - 1 && index < fileList.size(); j++){
				showANoRightFilename(output[i][j], maxLen);
			}
			if (j = colNum - 1)
				printf("%s\n", output[i][colNum - 1].c_str(), maxLen);
			else
				printf("\n");
		}
		/*if (iMod == 0){
			for (int i = 0; i < rows; i++){
				for (int j = 0; j < colNum-1; j++){
					showANoRightFilename(fileList[index].name, maxLen - fileList[index].length);
					index++;
				}
				printf("%s\n", fileList[index].name.c_str());
				index++;
			}
		}
		else{
			for (int i = 0; i < rows; i++){
				for (int j = 0; j <= iMod; j++){
					index = i*colNum+j*(rows + 1);
					showANoRightFilename(fileList[index].name, maxLen - fileList[index].length);
				}
				for (int j = iMod+1; j < colNum - 1; j++){
					index += rows;
					showANoRightFilename(fileList[index].name, maxLen - fileList[index].length);
				}
				index++;
				printf("%s\n", fileList[index].name.c_str());
			}
			for (int j = 0; j < iMod; j++){
				index = rows*colNum+j*(rows + 1);
				showANoRightFilename(fileList[index].name, maxLen - fileList[index].length);
			}
			printf("\n");
		}*/
		
	}
	

	return 0;
}

