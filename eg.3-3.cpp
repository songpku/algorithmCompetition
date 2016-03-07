#include<stdio.h>
#include<iostream>
int main(){
	int a[8][8]={0};
	int f=0;
	int n,index=1,r=0;
	scanf("%d",&n);
	a[0][n-1]=index++;
	int c=n-1;
	while(index <= n*n){
		while(r+1<n && a[r+1][c]==0){
			r++; a[r][c]=index++;
		}
		while(c+1<n && a[r][c+1]==0){
			c++; a[r][c]=index++;
		}
		while(r-1>=0 && a[r-1][c]==0){
			r--; a[r][c]=index++;
		}
		while(c-1>=0 && a[r][c-1]==0){
			c--; a[r][c]=index++;
		}
	}
	for(r=0;r<n;r++){
		for(c=0;c<n;c++)
			printf("%2d ",a[r][c]);
		printf("\n");
	}
	system("pause");
}
