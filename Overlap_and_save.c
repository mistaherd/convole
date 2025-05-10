#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void overlap_and_save(int *xn,int hn[]);
int main(){
	//set the value we want our vhunk we perofrm overlapand save on
	int chunk_size=0xF;

	int context_window=100;
	/// make an array that is the size of the context window
	int *xn=(int *)malloc(context_window*sizeof(int));
	// set the seed for the random number gen
	int seed=20;
	srand(seed);
	int hn[3]={1,2,3};
	//intize xn with random numbers
	for(int i=0;i<context_window;i++){
		xn[i]=rand()%100;
	}
	overlap_and_save(xn,hn,3);

	free(xn);
	return 0;
}

int *zeropad(int *Input_array,int pad_width){
	int size_of_array=sizeof(Input_array)/sizeof(Input_array[0])+pad_width*2;
	int *temp=(int *)calloc(size_of_array,sizeof(int));
	memcpy(temp,Input_array,size_of_array*sizeof(int));
	return temp;
}

void overlap_and_save(int *xn,int hn[],int num_of_overlap){
	int *padded_xn=zeropad(xn,num_of_overlap);

	int padded_size=sizeof(padded_xn)/sizeof(padded_xn[0]);
	printf("padded size %d\n",padded_size);
	for(int i=0;i<100;i++){
		printf("padded array[%d] = %d\n",i,xn[i]);
	}
	free(padded_xn);
}

