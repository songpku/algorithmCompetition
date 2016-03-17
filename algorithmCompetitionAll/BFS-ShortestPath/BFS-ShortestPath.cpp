// BFS-ShortestPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;
int a[MAXN][MAXM], t0[MAXN*MAXM], t1[MAXN*MAXM], t2[MAXN*MAXM], t3[MAXN*MAXM];
int n, m;

int BFS(int r, int c){
	if (r < 0 || c < 0 || r >= n || c >= m || a[r][c] == 1)
		return -1;
	int id = r*m + c;
	a[r][c] = 1;
	t0[id] = BFS(r - 1, c);
	t1[id] = BFS(r, c - 1);
	t2[id] = BFS(r + 1, c);
	t3[id] = BFS(r , c + 1);
	return id;

}
int _tmain(int argc, _TCHAR* argv[])
{
	freopen("../data/bfs_sp.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	BFS(0, 0);

	return 0;
}

