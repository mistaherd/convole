#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main(){
	int **a=(int **)malloc(8*sizeof(int));
	assert(a!=NULL &&"Memory allocation failed when allocateing memory for a\n");

	for(int i=0;i<8;i++){
		a[i]=(int *)malloc(8*sizeof(int));
		assert(a[i]!=NULL&&"Memory allocation failed when allocateing memory for inner buffer\n");
		printf("\nArray %d: ", i);
		for(int j=0;j<8;j++){
			a[i][j]=i+(j*2)%7;
			printf("%d ", a[i][j]);
		}
		

	}
	
	
	/// set free your allocations
	for(int i=0;i<8;i++){
		free(a[i]);
	}
	free(a);
	return 0;
}
