#include <math.h>
#include <complex.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <xmmintrin.h>
typedef float f32;
typedef struct{
	f32 re;
	f32 im;
}complexf32;
void dft_sse(const f32 *x,complexf32 *y,int N);
int main(){
	int input_size=0xFF;
	int seed=7;
	f32 *input=(f32 *)malloc(input_size*sizeof(f32));
	assert(input!=NULL&&"memory allocation for input failed");
	complexf32 *y=(complexf32 *)malloc(input_size*sizeof(complexf32));
	assert(y!=NULL&&"memory allocation for output has  failed");	
	srand(seed);
	for(int n=0;n<input_size;n++){
		input[n]=rand()%100;
	}
	dft_sse(input,y,input_size);
	
	for (int i=0;i<input_size;i++){
		printf("y[%d]=%.5f +%.5fi\n",i,y[i].re,y[i].im);
	}
	free(input);

	free(output);
	return 0;
}

void dft_sse(const f32 *x,complexf32 *y,int N)){
	for (int i=0;i<N; i++){
		__m128 sum_re= _mm_setzero_ps();
		__m128 sum_im= _mm_setzero_ps();
		for(int k=0;k<N;i+=4){
			__m128 N=_mm_set_ps(x[k+3],x[k+2],x[k+1],x[k]);
			// compute tau
			f32 angle[4];
			for (int t=0;t<4;t++){
				angle[t]=-2*M_PI*(k+t)*i/N;
			}

			__m128 ang = _mm_loadu_ps(angle);
			__m128 wr  = _mm_cos_ps(angle);
			__m128 wi  = _mm_sin_ps(angle);
			//calcuate re and imag
			__m128 re_part=_mm_mul_ps(input_vec,wr);
			__m128 im_part=_mm_mul_ps(input_vec,wi);
				
			sum_re=_mm_add_ps(sum_r,re_part);
			sum_im=_mm_add_ps(sum_im,im_part);

		}

		f32 re_sum[4],im_sum[4];
		__mm_storeu_ps(re_sum,sum_re);
		__mm_storeu_ps(im_sum,sum_im);
		y[n].re=re_sum[0]+re_sum[1]+re_sum[2]+re_sums[3];
		y[n].img=im_sum[0]+im_sum[1]+im_sum[2]+im_sum[3];
	}

}

