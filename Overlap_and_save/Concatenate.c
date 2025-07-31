#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int *concatenate(int **arr1,int number_of_arrays,int size_of_array_inside){
	// Resultant array to store merged array
	int res_size=number_of_arrays*size_of_array_inside;
	int *res = (int*)malloc(res_size*sizeof(int));

	assert(res !=NULL&& "Memory allocation failed when allocateing memory for conatenation\n");
	int k=0;
	// Copy elements of the second array
	for(int i=0;i<number_of_arrays;i++){
		for(int j=0;j<size_of_array_inside;j++){
			res[k]=arr1[i][j];
			k++;
			
		}
	}
	for(int i=0;i<9;i++){

		printf("res[%d]=%d\n",i,res[i]);
	}
	return res;
}
int main(){
	int shape=3;
	int **x=(int **)malloc(shape*sizeof(int));
	assert(x !=NULL&& "Memory allocation failed when allocateing memory for x\n");
	for(int i=0;i<shape;i++){
		x[i]=(int *)malloc(shape*sizeof(int));
		assert(x[i] !=NULL&& "Memory allocation failed when allocateing memory for x[i]\n");
	}
	int counter=1;
	for(int i=0;i<shape;i++){
		for(int j=0;j<shape;j++){
			x[i][j]=counter++;
			printf("x[%d][%d]=%d\n",i,j,x[i][j]);
		}
	}

	int*y=concatenate(x,3,3);
	
	

	return 0;
}
