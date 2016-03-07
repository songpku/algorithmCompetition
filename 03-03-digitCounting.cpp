#include<stdio.h>
int main(){
	int a[10]={0};
	int tmp;
	for(int i=1; i<=10000; i++){
		tmp=i;
		while(tmp/10 !=0){
			a[tmp%10]++;
			tmp=tmp/10;
		}
		a[tmp]++;
	}
}
