// eg-05-09-Database.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<set>
#include<map>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
int lable[10020][12] = { 0 };
void split(vector<string> &strOut, string &str, char sp){
	int start = 0, end;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == sp){
			string temp(str.begin() + start, str.begin() + i);
			start = i + 1;
			strOut.push_back(temp);
		}
	}
	string temp(str.begin() + start, str.end());
	strOut.push_back(temp);
}
vector<vector<string> > datas;
set<string> colSet;
map<string, int> colMap;
vector<string> lines;
set<int> lineLive;
map<int, int> lineCol;
int main()
{
	//freopen("..\\data\\05-09.txt", "r", stdin);
	int r, c;
	string line;
	
	while (cin>>r>>c){
		getchar();
		for (int i = 0; i < r; ){
			getline(cin,line);
			//if (line.length() > 0){
				lines.clear();
				split(lines, line, ',');
				i++;
				datas.push_back(lines);
			//}
		}
		
		
		for (int j = 0; j < c; j++){
			colSet.clear();
			colMap.clear();
			for (int i = 0; i < r; i++){
				if (colSet.count(datas[i][j]) == 0){
					colSet.insert(datas[i][j]);
					colMap[datas[i][j]] = i;
					lable[i][j] = i;
				}
				else{
					lable[i][j] = colMap[datas[i][j]];
				}

			}
		}
		
		bool bPNF = true;
		for (int i = 1; i < r; i++){
			lineLive.clear();
			lineCol.clear();
			for (int j = 0; j < c; j++){
				if (lable[i][j] != i){
					int isTemp = 0;
					if (lineLive.count(lable[i][j]) == 0){
						for (int k = lable[i][j] + 1; k < i; k++){
							if (lable[k][j] == lable[i][j] && lineLive.find(k)!=lineLive.end()){
								isTemp = k;
								break;
							}
						}
						if (!isTemp){
							lineLive.insert(lable[i][j]);
							lineCol[lable[i][j]] = j;
						}
						else{
							cout << "NO" << endl;
							cout << isTemp + 1 << " " << i + 1 << endl;
							cout << lineCol[isTemp] + 1 << " " << j + 1 << endl;
							bPNF = false;
							break;
						}
					}
					else{
						cout << "NO" << endl;
						cout << lable[i][j] + 1 << " " << i + 1 << endl;
						cout << lineCol[lable[i][j]] + 1 << " " << j + 1 << endl;
						bPNF = false;
						break;
					}
				}
			}
		}
		if (bPNF)
			cout << "YES" << endl;

	}

	return 0;
}

