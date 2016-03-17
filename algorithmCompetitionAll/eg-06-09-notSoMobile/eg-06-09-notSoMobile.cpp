// eg-06-09-notSoMobile.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int solve(){
	int w1, w2, d1, d2;
	cin >> w1 >> d1 >> w2 >> d2;
	if (w1==0)
		w1 = solve();
	if (w2==0)
		w2 = solve();
	if (w1 < 0 || w2 < 0)
		return -1;
	return w1*d1 == w2*d2 ? w1 + w2 : -1;


}
int main()
{
	//freopen("..\\data\\06-09.txt", "r", stdin);
	int ic;
	cin >> ic;
	while (ic--){
		int ret = solve();
		if (ret >=0)
			cout << "YES\n";
		else
			cout << "NO\n"; 
		if (ic)
			cout << "\n";
	}
	return 0;
}

