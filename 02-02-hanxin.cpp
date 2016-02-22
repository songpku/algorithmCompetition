#include<stdio.h>
int main(){
	freopen("data\\02-02.txt","r",stdin);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3){
		//printf("%d %d %d\n",a,b,c);
		int i;
		for(i=10;i<=100;i++){
			if(i%3==a && i%5==b && i%7==c){
				printf("Case 1:%d\n",i);
				break;
			}
		}
		if(i>100){
			printf("Case 1: No answer\n");
		}
	}
} 
