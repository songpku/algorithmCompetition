#include<stdio.h>
#define maxn 25
int n,k,m,num = 0;
int a[maxn];
void goAStep(int &start,int dire,int &step,int &stepN){
	do{
		start = (start+ dire) < 0 ? n-1 :(start+ dire)%n;
		if(a[start] !=0)
			break;
	}while(true);
	step++;
//	if(step == stepN){
//		printf("%d ",a[start]);
//		step = 0;
//		num ++;
//		a[start] =0;
//	}
}
int main(){
	int AStart=-1,Adx=1,AStepN,AStep=0,BStart,Bdx=-1,BStepN,BStep=0;
	scanf("%d%d%d", &n,&k,&m);
	AStepN = k;
	BStepN = m;
	BStart = n;
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	while(num < n){
		if(AStep < AStepN)
			goAStep(AStart,Adx,AStep,AStepN);
		if(BStep < BStepN)
			goAStep(BStart,Bdx,BStep,BStepN);
		if(AStep == AStepN && BStep == BStepN){
			if(AStart != BStart){
					printf("%d %d;",a[AStart],a[BStart]);
					AStep = BStep = 0;
					num = num + 2;
					a[AStart] = a[BStart]= 0;
			}else{
				printf("%d;",a[AStart]);
				AStep = BStep = 0;
				num = num + 1;
				a[AStart] = a[BStart]= 0;
			}
		}
	}
	
	return 0;
} 
