#include<stdio.h>
//#define LOCAL
int main(){
	for(int i=100; i<=999; i++){
		int a=i/100;
		int b=i%100;
		b=b/10;
		int c=i%10;
		#ifdef LOCAL
		//printf("abc=%d,a=%d,b=%d,c=%d\n",i,a,b,c);
		#endif
		if(i == a*a*a + b*b*b + c*c*c)
			printf("%d\n",i);
	}
	#ifdef LOCAL
	int iwait; 
	scanf("%d",&iwait); 
	#endif
}
