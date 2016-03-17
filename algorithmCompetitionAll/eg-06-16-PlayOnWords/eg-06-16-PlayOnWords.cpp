// eg-06-16-PlayOnWords.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<iostream>
#include<stack>
using namespace std;

const int ALPHANUM = 26;
const int MAXCHARNUM = 1000;
int iCaseNum, iWordsNum;
int G[ALPHANUM][ALPHANUM];
int G4DFS[ALPHANUM][ALPHANUM];
//int vis[ALPHANUM];
int cnt[ALPHANUM];
int cntt = 0;
int n = 0;
stack<int> sout;
void DFS(int u){
	if (cnt[u] == 0)
		cntt++;
	cnt[u] = 1;
	for (int v = 0; v < ALPHANUM; v++){
		if (G[u][v] || G[v][u]){
			if (cnt[v] < 1){
				//cnt[v]++;
				DFS(v);
			}
		}
	}
	
}

bool isConnected(){

	memset(G4DFS, 0, sizeof(G4DFS));
	for (int i = 0; i < ALPHANUM; i++){
		memset(cnt, 0, sizeof(cnt));
		cntt = 0;
		DFS(i);
		if (cntt == n)
			return true;
	}
	return false;
}
void euler(int u){
	for (int v = 0; v < n; v++)
		if (G[u][v] && G4DFS[u][v]){
			G4DFS[u][v] = 1;
			euler(v);
			sout.push(v);
		}
}


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("../data/06-16.txt", "r", stdin);
	scanf("%d", &iCaseNum);
	char word[MAXCHARNUM + 1];
	for (int i = 0; i < iCaseNum; i++){
		memset(G, 0, sizeof(G));
		memset(G4DFS, 0, sizeof(G4DFS));
		memset(cnt, 0, sizeof(cnt));
		n = 0;
		scanf("%d", &iWordsNum);
		for (int j = 0; j < iWordsNum; j++){
			scanf("%s",word);
			G[word[0] - 'a'][word[strlen(word) - 1]-'a'] ++;
			G4DFS[word[0] - 'a'][word[strlen(word) - 1] - 'a'] = 1;

			
			if (cnt[word[strlen(word) - 1] - 'a'] == 0){
				//n++;
				cnt[word[strlen(word) - 1] - 'a'] == 1;
			}
			if (cnt[word[0] - 'a'] == 0){
				//n++;
				cnt[word[0] - 'a'] == 1;
			}
			
		}
		for (int i = 0; i < ALPHANUM; i++){
			if (cnt[i] == 1)
				n++;
		}
		bool bOrder = false;
		if (isConnected()){
			for (int i = 0; i < n; i++){
				while (!sout.empty()) {
					sout.pop();
				}
				euler(i);
				if (sout.size() == n){
					bOrder = true;
					cout << "Ordering is possible.\n";
					break;
				}
			}
		}
		if (!bOrder){
			cout << "The door cannot be opened.\n";
		}
	}
	return 0;
}

