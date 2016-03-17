// eg-06-14-AbbottsRevenge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//（r,c）点朝向dir方向
struct NODE{
	int r;
	int c;
	int dir;
	NODE(){}
	NODE(int _r, int _c, int _dir) : r(_r),c(_c),dir(_dir){}
};

const int MAXR = 9+2;
const int MAXC = 9+2;
const int MAXDIR = 4;
const int MAXTURN = 3;

NODE p[MAXR][MAXC][MAXDIR]; //保存(r,c)点的父节点
int d[MAXR][MAXC][MAXDIR]; //保存起始点到点(r,c)的最短路径
bool has_edge[MAXR][MAXC][MAXDIR][MAXTURN] = {false}; //点(r,c)朝向dir是否可以转向turn

const char *dirs = "NESW";
const char *turns = "FLR";

int dir_id(char c){ return strchr(dirs, c) - dirs; }
int turn_id(char c){ return strchr(turns, c) - turns; }

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0, -1 };

NODE nstart;
NODE nend;

const char showdir[] = { 'f' ,'l','r'};

NODE walk(const NODE& u, int turn){
	int dir = u.dir;
	if (turn == 1){ 
		dir = (dir + 3) % MAXDIR; 
	}
	else if (turn == 2){
		dir = (dir + 1) % MAXDIR;
	}
	return NODE(u.r + dr[dir], u.c + dc[dir], dir);
}
void read(){
	memset(has_edge, false, sizeof(d));
	int r0, c0, r1, c1;
	char dir;
	string turns;
	cin >> r0 >> c0 >> dir >> r1 >> c1;
	nstart.r = r0; nstart.c = c0; nstart.dir = dir_id(dir);
	nend.r = r1; nend.c = c1; nend.dir = -1;
	while (scanf("%d%d", &r0, &c0) == 2){
		while (cin>>turns && turns != "*"){
			int idir = dir_id(turns[0]);
			for (int i = 1; i < turns.length(); i++){
				has_edge[r0][c0][idir][turn_id(turns[i])] = true;
			}
		}
	}
}
void solve(){
	memset(d, -1, sizeof(d));
	
	queue<NODE> q;
	NODE u = NODE(nstart.r + dr[nstart.dir], nstart.c + dc[nstart.dir], nstart.dir); //从第一个点开始走
	q.push(u);
	//d[nstart.r][nstart.c][nstart.dir] = 0;
	d[u.r][u.c][u.dir] = 0;
	//p[u.r][u.c][u.dir] = nstart;
	//has_edge[nstart.r][nstart.c][nstart.dir][nstart.dir] = true;
	while (!q.empty()){
		NODE u = q.front(); q.pop();
		if (u.r == nend.r && u.c == nend.c){
			nend.dir = u.dir;
			return;
		}
		for (int i = 0; i < MAXTURN; i++){
			NODE v = walk(u,i);
			if (has_edge[u.r][u.c][u.dir][i] && d[v.r][v.c][v.dir] < 0){
				d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
				p[v.r][v.c][v.dir] = u;
				//printf("(%d,%d)", v.r, v.c);
				q.push(v);
			}
		}
	
	}
	printf("  No Solution Possible\n");
}

void printAns(){
	if (nend.dir < 0)
		return;
	vector<NODE> nodes;
	NODE u = nend;
	while (true){
		nodes.push_back(u);
		if (d[u.r][u.c][u.dir] == 0)
			break;
		u = p[u.r][u.c][u.dir];
	}
	nodes.push_back(nstart);
	int cnt = 0;
	for (int i = nodes.size() - 1; i >= 0; i--){
		if (cnt % 10 == 0)printf(" ");
		printf(" (%d,%d)", nodes[i].r, nodes[i].c);
		if (++cnt % 10 == 0)printf("\n"); 
	}
	if (nodes.size() % 10 != 0)
		printf("\n");

}
int main()
{
	freopen("../data/06-14.txt","r",stdin);
	string strMaze = "";
	getline(cin,strMaze);
	while (strMaze != "END"){
		read();
		cout<<strMaze<<endl;
		solve();
		printAns();

		getline(cin, strMaze);
	}
	return 0;
}

