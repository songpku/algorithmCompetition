#include<stdio.h>
int main(){
	int times=0,sum=0;
	int c;
	while((c=getchar())!= EOF){
		if(c == 'X'){
			times=0;
		}else if(c == 'O'){
			++times;
			sum+=times;
		
		}
		printf("%d %c",times,c);
	}
	printf("sum is %d\n",sum);
}
