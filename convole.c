#include "convole.h"
void convole(int *xn,int len_x,int *hn,int len_h,int y[],int len_y){
	for(int n=0;n<len_y;n++){
		y[n]=0;
		for (int k=0;k<len_h;k++){
			if(n-k>=0&& n-k<len_x){
				y[n]+=xn[n-k]*hn[k];
			}
		}
		
	}
}
