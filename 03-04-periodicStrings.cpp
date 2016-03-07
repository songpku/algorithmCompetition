#include<stdio.h>
#include<string.h>
int main(){
	char a[80],b[80];
	scanf("%s",a);
	int lenA = strlen(a);
	b[0]=a[0];
	int j=1,lenB=1,k=0;
	for(int i=1;i<lenA;i++){
		printf("<%d,%c><%d,%c,%d>\n",i,a[i],k,a[k],j); 
		if(a[i]==b[k]){
			k++;
			k=k%lenB; 
		}else{
			for(int t=j;t<=i;t++){
				b[lenB+t-j]=a[t];
				
			}
			lenB += i-j+1;
			j=i+1;
		}
	}
	printf("the length is %d",lenB);
}
