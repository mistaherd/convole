int* indexing(int *input,int from,int to,int size){
	int *buffer=(int *)malloc(size * sizeof(int));
	assert(buffer!=NULL &&"memory allocation failed when indexing\n");

	for (int i=from;i<to;i++){
			buffer[i]=input[i];
		}
		return buffer;
}
int main(){
	
	int a[]={2,3,5,6,2,64,1,5,7,98};
	int from =3;
	int to =6;
	int *y=
	return 0;
}

