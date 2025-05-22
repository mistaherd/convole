#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "convole.h"
#include "zeropad.h"
int * overlap_and_save(int *xn,int hn[],int hn_len,int chunk_size ,int context_window,int Num_of_overlap);
int *concatenate(int **arr1, int number_of_arrays, int size_of_array_inside);
int *indexing(int *input, int from, int to, int size);

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

	int hn[]={1,2,3};
	int hn_len=sizeof(hn)/sizeof(hn[0]);
	//intize xn with random numbers
	for(int i=0;i<context_window;i++){
		xn[i]=rand()%100;
	}

	int *y=overlap_and_save(xn,hn,hn_len,chunk_size,context_window,3);
	assert(y!=NULL&&"Overlap and save failed");
	for(int i=0;i<context_window;i++){
		printf("y[%d]=%d\n",i,y[i]);
	
	}
	free(y);
	free(xn);
	return 0;
}


int *concatenate(int **arr1,int number_of_arrays,int size_of_array_inside){
	// Resultant array to store merged array
	int res_size=number_of_arrays*size_of_array_inside;
	int *res = (int*)malloc(sizeof(int) * res_size);

	assert(res !=NULL&& "Memory allocation failed when allocateing memory for conatenation\n");
	
	// Copy elements of the second array
	for(int i=1;i<number_of_arrays;i++){
		memcpy(res + i*size_of_array_inside, arr1[i], size_of_array_inside * sizeof(int));
	}
	return res;
}

int* indexing(int *input,int from,int to,int size){
	int *buffer=(int *)malloc(size * sizeof(int));
	assert(buffer!=NULL &&"memory allocation failed when indexing\n");

	for (int i=from;i<to;i++){
			buffer[i]=input[i];
		}
		return buffer;
}
   
int *overlap_and_save(int *xn,int hn[],int hn_len,int chunk_size,int context_window,int Num_of_overlap){
	
	int *padded_xn=zeropad(xn,Num_of_overlap,context_window);

	int padded_len=context_window+2*Num_of_overlap;
	int buffer_size=padded_len/chunk_size;
	int **buffer=(int **)malloc(buffer_size*sizeof(int*));
	assert(buffer!=NULL&&"Memory alocation failed for buffer");

	int convole_output_len=3+chunk_size-1;
	for(int i=0;i<buffer_size;i++){
 
		int from=i*chunk_size;
		int to=from+chunk_size;
		int *input_chunk=indexing(padded_xn,from,to,chunk_size);

		assert(input_chunk!=NULL&&"failed to allocate memory in indexing");

		int *convole_output=(int *)malloc(convole_output_len * sizeof(int));
		assert(convole_output!=NULL&&"Memory allocation failed for convole output");
		
		convole(input_chunk,chunk_size,hn,hn_len,convole_output,convole_output_len);
		
		buffer[i]=(int *)malloc(convole_output_len*sizeof(int));
		assert(buffer[i]!=NULL&&"failed to allcate array in side buffer");
		

		memcpy(buffer[i],convole_output,convole_output_len * sizeof(int));
		
		free(convole_output);
		free(input_chunk);

		
	}
	int *concaenated_array=concatenate(buffer,buffer_size,convole_output_len);
	assert(concaenated_array!=NULL&&"failed to make concated_array");
	
	int *output=indexing(concaenated_array,hn_len-1,hn_len-1+context_window,context_window);

	for(int i=0;i<buffer_size;i++){
		free(buffer[i]);
	}
	free(buffer);
	free(concaenated_array);
	free(padded_xn);
	return output;
}
