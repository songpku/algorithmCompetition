// eg-06-15-OrderingTasks.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>

const int MAXN = 100;
int G[MAXN + 1][MAXN + 1] = { 0 };
int m, n;
int topo[MAXN+1];
int c[MAXN + 1] = {0};
int t;

bool dfs(int u){
	c[u] = -1;
	for (int v = 1; v <= n; v++){
		if (G[u][v]){
			if (c[v] == -1)
				return false;
			else if (!c[v] && !dfs(v))
				return false;
		}
		
	}
	c[u] = 1;
	topo[t--] = u;
	return true;

}

bool toposort(){
	t = n;
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++){
		if (!c[i])
		if (!dfs(i))
			return false;
	}
	return true;
}


int main()
{
	//freopen("../data/06-15.txt", "r", stdin);
	int u,v;
	while (scanf("%d%d", &n, &m) == 2 && (m > 0 || n > 0)){
		memset(G, 0, sizeof(G));
		for (int i = 0; i < m; i++){
			scanf("%d%d", &u, &v);
			G[u][v] = 1;
		}
		if (toposort()){
			for (int i = 1; i < n; i++){
				printf("%d ", topo[i]);
			}
			printf("%d\n", topo[n]);
		}
	}


	return 0;
}

