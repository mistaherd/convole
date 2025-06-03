#include <assert.h>
#include <stdlib.h>
#include "Indexing.h"
int* indexing(int *input,int from,int to){
	int size=to-from;
	int *buffer=(int *)calloc(size, sizeof(int));
	assert(buffer!=NULL &&"memory allocation failed when indexing\n");
	for (int i=0;i<size;i++){
			buffer[i]=input[from+i];
		}
	return buffer;
}
