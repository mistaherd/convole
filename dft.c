#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <math.h>
void dft(int *x,int N){
	complex double *y=(complex double *)calloc(N,sizeof(complex double));
	assert(y!=NULL&&"DFT buffer  failed!");
	printf("\ncompelx array with zeros\n");
	for(int n=0;n<N;n++){
		printf("\t %.4f+%.4fj",creal(y[n]),cimag(y[n]));
	}
	for(int n=0;n<N;n++){
		for(int k=0;k<N;k++){
			y[n]+=x[k]*cexp(-2*I*M_PI*k*n/N);
		}
	}
	printf("\nDFT result\n");
	for(int n=0;n<N;n++){
		printf("%.4f+%.4fj\t",creal(y[n]),cimag(y[n]));
	}
	free(y);
}

int main(){
	int context_window=100;
	int seed =32;
	int *x=(int *)malloc(context_window*sizeof(int));
	srand(seed);
	for(int i=0;i<context_window;i++){
		x[i]=rand()%100;
	}
	printf("\n X\n");
	for(int i=0;i<context_window;i++){
		printf("%d\t",x[i]);
	}

	dft(x,context_window);
	
	return 0;
}
