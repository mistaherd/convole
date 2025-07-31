#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
void fft(int *x,int N):
int main(){
	int context_window=100;
	int seed=32;
	int required_mem=context_window*2
	int *memory_buffer=(int *)malloc(required_mem*sizeof(int));
	int x[context_window];
	srand(seed);
	for(int i=0;i<context_window;i++){
		x[i]=rand()%100;
	}
	fft(x,context_window);
	free(memory_buffer);
	return 0;
}
void fft(int *x,int N){
	complex double y[N];
	complex double cal=-2*I*M_PI/N;
/**************************************************
for(int n=0;n<N;n++){
	for(int k=0;k<N;k++){
		y[n]+=x[k]*cexp(-2*I*M_PI*k*n/N);
		}
	}

so we can want the following regist
_y which is the output
_x which is the input
_exp_comp


ie N=20

(-2I*pi/N)*k*n

****************************************************/

}

