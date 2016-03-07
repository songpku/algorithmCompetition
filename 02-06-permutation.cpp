#include<stdio.h>
int main(){
	for(int i=192;i<333;i++){
		int a[9]={0},b[9]={0};
		int B,C;
		B=i*2;
		C=i*3;
		a[0]=i/100;
		a[1]=i%10;
		a[1]=a[1]/10;
		a[2]=i%100;
		a[3]=B/100;
		a[4]=B%10;
		a[4]=a[4]/10;
		a[5]=B%100;
		a[6]=C/100;
		a[7]=C%10;
		a[7]=a[7]/10;
		a[8]=C%100;
		for(int j=0;j<9;j++){
			b[a[j]]+=1;
		//	printf("%d ",a[j]);
		}
		//	printf("\n");
		int k=0;
		for(;k<9;k++){
			if(b[k]!=1)
				break;
		}
		if(k==9)
			printf("%d %d %d\n",i,B,C);
	}
}
