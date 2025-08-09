#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <xmmintrin.h>
typedef float f32;
typedef double f64;
void fft(int *x,int N):
int main(){
	int input_size=0xFFFF;
	f32 *input=(f32 *)malloc(input_size*sizeof(f32);
	int seed=7;
	srand(seed);
	for(int n=0;n<input_size;n++){
		input[n]=rand()%100;
	}
	// FFT logic here
	f32 *y;
	for (int i=0;i<input_size; i++){
		__m128 ouput_vec= _mm_setzero_ps();
		for(int k=0;k<input_size;i+=4){
			_mm_set_ps(input[k+3],input[k+2],input[k+1],input[k]);
			// compute tau
			complex f32 angle[4];
			for (int t=0;t<4;t++){
				angle[t]=-2*M_PI*(k+t)*i/N;

			}
		}
		//this will load input[i] ,input[i+1],input[i+2],input[i+3
	}
	free(input);
	return 0;
}
void fft(int *x,int N){
	complex f32 y[N];
	//complex double cal=-2*I*M_PI/N;
	
	for(int n=0;n<N;n++){
		for(int k=0;k<N;k++){
			y[n]+=x[k]*cexp(-2*I*M_PI*k*n/N);
		}
	}



}

