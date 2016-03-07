#include<stdio.h>
char a[5][5];
void show(){
	printf("-------------------\n"); 
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(a[i][j]!='0'){
				printf("%c ",a[i][j]);
			}else{
				printf("# ");
			}
		}
		printf("\n");
	}
}
int main(){
	FILE * fin;
	fin = fopen("data/03-05.txt","r");
	int X,Y,xi,yi;
	for(int i=0;i<5;i++)
		for(int j=0;j<5 && fscanf(fin,"%c",&a[i][j]) == 1;j++){
			if(a[i][j]=='0'){
				X=j;
				Y=i;
			}
		}
	show();
	char input;
	bool errorInput=false;
	while(scanf("%c",&input)==1){
		if(input == '0')
			break;
		switch(input){
			case 'A':yi= (Y-1)>=0?Y-1:0;xi=X;break;
			case 'B':yi=(Y+1)<5?Y+1:4;xi=X;break;
			case 'L':xi=X-1>=0?X-1:0;yi=Y;break;
			case 'R':xi=(X+1)<5?X+1:4;yi=Y;break;
			default:printf("EORRER INPUT");errorInput=true;
		}
		if(errorInput){
			errorInput = false;
			continue;
		}
		a[Y][X] = a[yi][xi];
		a[yi][xi] = '0';
		X= xi;
		Y=yi;
		show();
	}
	show();
	return 0;
}
