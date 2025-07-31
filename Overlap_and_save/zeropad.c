#include <stdlib.h>
#include <assert.h>
#include "zeropad.h"
int *zeropad(int *Input_array,int pad_width,int chunk_size){
	int temp_size=pad_width*2+chunk_size;

	int *temp=(int *)calloc(temp_size,sizeof(int));
	assert(temp !=NULL&& "Memory allocation failed when allocateing memory for zeropad\n");

	for(int i=pad_width;i<temp_size-pad_width;i++){
		temp[i]=Input_array[i-pad_width];
	
	}
	int last_el=temp_size-1;
	temp[last_el]=0;
	return temp;
}
