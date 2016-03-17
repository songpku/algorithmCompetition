// eg-11-2-slimSpan-SpanningTree-kruskal-UnionFindSet.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
const int MAXN = 100+10;
const int MAXM = 10000; //0<=m<=n(n-2)/2
const int INF = 1000000000;
int n, m;
int u[MAXN+10];
int v[MAXN+10];
int w[MAXM+10];  //E[i] = (u,v) ;whight[i] = w[i];
int r[MAXM+10];
int p[MAXN + 11];
int compare(const void *a, const void  *b){
	return w[*(int*)a] - w[*(int*)b];
}
int find_root(int x){
	return (p[x] == x) ? x : p[x] = find_root(p[x]);
}

int solve(){
	int iret = INF;
	for (int i = 0; i < m; i++)
		r[i] = i;
	qsort(r, m,sizeof(int),compare);
	for (int l = 0; l < m; l++){
		int eNum = n;
	/*	int maxW = -1;
		int minW = -1;*/
		for (int i = 0; i <= n; i++)
			p[i] = i;
		for (int i = l; i < m; i++){
			int id = r[i];
			int rootU = find_root(u[id]);
			int rootV = find_root(v[id]);
			if (rootU != rootV){
				//eNum++;
				/*maxW < w[id] ? maxW = w[id] : true;
				if (minW == -1)
					minW = w[id]; 
				else
					minW > w[id] ? minW = w[id] : true;*/
				p[rootU] = rootV;
				if (--eNum == 1){
					iret = std::min(iret, w[r[i]] - w[r[l]]);
				}
			}
		}
		//if (eNum == n - 1){
		//	if (iret == -1){
		//		iret = maxW - minW;
		//		//printf("(%d~%d)", minW, maxW);
		//	}
		//	else{
		//		iret > maxW - minW ? iret = maxW - minW : true;
		//		/*if (iret > maxW - minW){
		//			printf("(%d~%d)", minW, maxW);
		//		}*/
		//	}
		//}
	}
	if (iret == INF)
		iret = -1;
	return iret;
}
int main()
{
	freopen("../data/11-02.txt","r",stdin);
	while (scanf("%d%d", &n, &m) == 2 && n > 0){
		memset(u, 0, sizeof(u));
		memset(v, 0, sizeof(v));
		memset(w, 0, sizeof(w));
		for (int i = 0; i < m; i++){
			if (scanf("%d%d%d", &u[i], &v[i], &w[i]) < 3)
				printf("input error\n");
		}
		printf("%d\n",solve());
	
	}
	return 0;
}

