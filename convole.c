#include <stdio.h>
#include <stdlib.h>
void convole(int xn[],int len_x,int hn[], int len_h, int y[], int len_y);
int main(){
	int hn[3]={-1,2,1};
	int xn[3]={-2,1,3};
	int len_h= sizeof(hn)/sizeof(hn[0]);
	int len_x=sizeof(xn)/sizeof(xn[0]);

	int len_y=len_x+len_h-1;

	int *y=(int *)malloc(len_y*sizeof(int));
	if (y== NULL){
		perror("Memory allocation failed");
		return 1;
	}
	convole(xn,len_x,hn,len_h,y,len_y);
	for(int i=0;i<len_y;i++){
		printf("y[%d] =%d\n",i,y[i]);
	}
	free(y);
	return 0;
}
void convole(int xn[],int len_x,int hn[],int len_h,int y[],int len_y){
	
	for(int n=0;n<len_y;n++){
		y[n]=0;
		for (int k=0;k<len_h;k++){
			if(n-k>=0&& n-k<len_x){
				y[n]+=xn[n-k]*hn[k];
			}
		}
		
	}
}
