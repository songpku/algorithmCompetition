#include<stdio.h>
int main(){
	freopen("data/02-04.txt","r",stdin);
	int n,m,i,index=1;
	double result,temp;
	while(scanf("%d%d",&n,&m)==2 && n!=0 && m!=0){
		for(result=0,i=n;i<=m;i++){
			temp = 1/((double)i*i);
			result+=temp;
		}
		printf("Case %d: %.5f\n",index++,result);
	}
} 
