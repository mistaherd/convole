#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <convole.h>

void overlap_and_save(int *xn,int hn[],int num_of_overlap,int chunk_size ,int context_window);
int main(){
	//set the value we want our vhunk we perofrm overlapand save on
	int chunk_size=0xF;

	int context_window=100;
	assert(chunk_size<context_window &&"Chunk size has to be smaller than the context window\n"); 
	/// make an array that is the size of the context window
	int *xn=(int *)malloc(context_window*sizeof(int));
	assert(xn !=NULL&& "Memory allocation failed when allocateing memory for xn\n");
	// set the seed for the random number gen
	int seed=20;
	srand(seed);

	int hn[3]={1,2,3};
	//intize xn with random numbers
	for(int i=0;i<context_window;i++){
		xn[i]=rand()%100;
	}
	overlap_and_save(xn,hn,3,chunk_size,context_window);

	free(xn);
	return 0;
}

int *zeropad(int *Input_array,int pad_width,int chunk_size){
	int temp_size=(pad_width*2+chunk_size);

	int *temp=(int *)calloc(temp_size,sizeof(int));
	
	
	assert(temp !=NULL&& "Memory allocation failed when allocateing memory for zeropad\n");
	for(int i=3;i<temp_size;i++){
		temp[i]=Input_array[i-3];
	
	}

	temp[105]=0;
	return temp;
}
/*
int *concatenate(int *arr1,int *arr2 ,int len_ofarry1,int len_ofarry2){
	// Resultant array to store merged array
	int *res = (int*)malloc(sizeof(int) * len_ofarry2 * len_ofarry2);
	assert(res !=NULL&& "Memory allocation failed when allocateing memory for conatenation\n");
	// Copy elements of the first array
	memcpy(res, arr1, len_ofarry1 * sizeof(int));
	// Copy elements of the second array
	memcpy(res + len_ofarry1, arr2, len_ofarry2 * sizeof(int));

	return res;
}
*/
int* indexing(int *input,int from,int to,int size){
	int *buffer=(int *)calloc(size,sizeof(int));
	for (int i=from;i<to;i++){
		buffer[i]=intput[i];
	}
	return buffer;

    }
void overlap_and_save(int *xn,int hn[],int num_of_overlap,int chunk_size,int context_window){
	int *padded_xn=zeropad(xn,num_of_overlap,context_window);
	int number_of_el=context_window+num_of_overlap*2;
	int *buffer=(int *)calloc(context_window,sizeof(int));
	int from=0
	int output_len=3+chunk_size-1
	for(int i=0;i<number_of_el;i++){
		if(i%chunk_size==0){ 
			from=i;
			int *inner_buff=indexing(padded_xn,from,i+chunksize,chunk_size);
			convole(xn,chunk_size,hn,3,inner_buff,output_len);
			
		}
		
	}

	//int*output=concatenate();

	free(buffer);
	free(output);
	free(padded_xn);
}

