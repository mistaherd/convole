#include <stdio.h>

int main(){
	int encoder_in=0b1010;
	int shift_reg=0b000;
	int len_of_in=sizeof(encoder_in);
	int lsb;
	int a;
	int b;
	
	for(int i=0;i<len_of_in+3;i++){
		lsb=encoder_in&1;
		if (lsb==1){
			shift_reg|=0b100;
		}
		a=(0b100&shift_reg)^(0b001&shift_reg);
		b=(0b100&shift_reg)^(0b010&shift_reg)^(0b001&shift_reg);
		printf("A: %d,B: %d\n",!!a,!!b);
		//printf("encoder in: %d\nShift register: %d\n",encoder_in,shift_reg);
		
		// output A	
		shift_reg=shift_reg>>1;
		encoder_in=encoder_in>>1;
	}
	return 0;

}
