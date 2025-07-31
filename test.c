#include <emmintrin.h>
#include <stdio.h>
int main(){
	__m128i a_vec = _mm_set_epi16(80, 70, 60, 50, 40, 30, 20, 10);
	__m128i b_vec = _mm_set_epi16(8, 7, 6, 5, 4, 3, 2, 1);
	// 2. Perform the packed 16-bit integer addition
	__m128i result_vec = _mm_add_epi16(a_vec, b_vec);

	// 3. Print the results to verify
	printf("Original a_vec (16-bit elements):\n");
	// To access the elements, we can cast the __m128i to an array of int16_t.
	// This is safe for reading, but be cautious with writing.
	int16_t *a_elements = (int16_t *)&a_vec;
	for (int i = 0; i < 8; ++i) {
		printf("%d ", a_elements[i]);
	}
	printf("\n\n");

	printf("Original b_vec (16-bit elements):\n");
	int16_t *b_elements = (int16_t *)&b_vec;
	for (int i = 0; i < 8; ++i) {
		printf("%d ", b_elements[i]);
	}
	printf("\n\n");

	printf("Result of _mm_add_epi16 (16-bit elements):\n");
	int16_t *result_elements = (int16_t *)&result_vec;
	for (int i = 0; i < 8; ++i) {
		printf("%d ", result_elements[i]);
	}
	printf("\n\n");

	return 0;
}

