#include <cstdio>

int main(){
	int nums_num[2];																									// numbers of numbers in each array
	long *nums[2];
	for (int i = 0; i < 2; i++) {
		scanf("%d", &nums_num[i]);
		nums[i] = new long[nums_num[i]];
		for (int j = 0; j < nums_num[i]; j++)
			scanf("%ld", &nums[i][j]);
	}
	int indices[2] = {0, 0}, mid = (nums_num[0] + nums_num[1] - 1) >> 1;												// current indices of number processed in each array; index of the median (in all the numbers)
	for (int i = 0; i < mid; i++) {
		if ((indices[1] == nums_num[1]) || ((indices[0] < nums_num[0]) && (nums[0][indices[0]] < nums[1][indices[1]])))	// the smaller number is processed, index in the corresponding array + 1
			indices[0]++;
		else
			indices[1]++;
	}
	if ((indices[1] == nums_num[1]) || ((indices[0] < nums_num[0]) && (nums[0][indices[0]] < nums[1][indices[1]])))		// finally, the smaller one is the median
		printf("%ld", nums[0][indices[0]]);
	else
		printf("%ld", nums[1][indices[1]]);

	return 0;
}