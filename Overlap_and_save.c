#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "convole.h"
#include "zeropad.h"
#include "Indexing.h"
int * overlap_and_save(int *xn,int hn[],int hn_len,int chunk_size ,int context_window,int Num_of_overlap);
int *concatenate(int **arr1, int number_of_arrays, int size_of_array_inside);


int main(){
	//set the value we want our vhunk we perofrm overlapand save on
	int chunk_size=0xF;
	int number_of_overlap=3;
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

	int *y=overlap_and_save(xn,hn,hn_len,chunk_size,context_window,number_of_overlap);
	assert(y!=NULL&&"Overlap and save failed");
	printf("\n\r Output of overlap and save:\n");
	for(int i=0;i<context_window;i++){
		if (i==0){
			printf("[%d,",y[i]);
		}
		else if(i==context_window-1){
			printf("%d]\n\n",y[i]);
		}
		else{
			printf("%d,",y[i]);
		}

	
	
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
	int k=0;
	for(int i=0;i<number_of_arrays;i++){
		for(int j=0;j<size_of_array_inside;j++){
			res[k]=arr1[i][j];
			k++;
		}
	}
	return res;
}

  
int *overlap_and_save(int *xn,int hn[],int hn_len,int chunk_size,int context_window,int Num_of_overlap){
	// padded input to incate the start and stop of the data recivied
	int *padded_xn=zeropad(xn,Num_of_overlap,context_window);
	
	int padded_len=context_window+2*Num_of_overlap;
	printf("padded array:\n");	
	for(int i=0;i<padded_len;i++){
		if (i==0){
			printf("[%d,",padded_xn[i]);
		}
		else if(i==padded_len-1){
			printf("%d]\n\n",padded_xn[i]);
		}
		else{
			printf("%d,",padded_xn[i]);
		}
	}
	
	// round up the the legnth of the pad divied by chunks size to control how many iterations the foor loop will go
	int buffer_size=round(padded_len/chunk_size);
	// allocate memory for an array of arrays
	int **buffer=(int **)malloc(buffer_size*sizeof(int*));
	assert(buffer!=NULL&&"Memory alocation failed for buffer");

	int convole_output_len=3+chunk_size-1;
	for(int i=0;i<buffer_size;i++){
 
		int from=i*chunk_size;
		int to=from+chunk_size;
		//print these vaules to for a sanity check at what is happeing 
		//printf("from =%d,to=%d,i=%d\n",from,to,i);
		int *Input_to_be_convoled=indexing(padded_xn,from,to);
		assert(Input_to_be_convoled!=NULL&&"failed to allocate memory in indexing");
		
		printf("\n Index array:\n");
		for(int j=0;j<chunk_size;j++){
			printf("%d,",Input_to_be_convoled[j]);
		}
		


		int *convole_output=(int *)malloc(convole_output_len * sizeof(int));
		assert(convole_output!=NULL&&"Memory allocation failed for convole output");
		
		convole(Input_to_be_convoled,chunk_size,hn,hn_len,convole_output,convole_output_len);
		
		buffer[i]=(int *)malloc(convole_output_len*sizeof(int));
		assert(buffer[i]!=NULL&&"failed to allcate array in side buffer");
		memcpy(buffer[i],convole_output,convole_output_len * sizeof(int));


		
		free(convole_output);
		free(Input_to_be_convoled);
		
		
	}
	int *concaenated_array=concatenate(buffer,buffer_size,convole_output_len);
	assert(concaenated_array!=NULL&&"failed to make concated_array");
	printf("\nConcaenated array:\n");
	for(int i=0;i<buffer_size*convole_output_len;i++){
		if (i==0){
			printf("[%d,",concaenated_array[i]);
		}
		else if(i==buffer_size*convole_output_len-1){
			printf("%d]\n\n",concaenated_array[i]);
		}
		else{
			printf("%d,",concaenated_array[i]);
		}

	}

	int *output=indexing(concaenated_array,Num_of_overlap,context_window-Num_of_overlap);

	for(int i=0;i<buffer_size;i++){
		free(buffer[i]);
	}
	free(buffer);
	free(concaenated_array);
	free(padded_xn);
	return output;
}
