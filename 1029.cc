#include <cstdio>

using namespace std;

int main(){
	int num[2];
	long *nums[2];
	for (int i = 0; i < 2; i++) {
		scanf("%d", &num[i]);
		nums[i] = new long[num[i]];
		for (int j = 0; j < num[i]; j++)
			scanf("%ld", &nums[i][j]);
	}
	int idx[2] = {0, 0}, mid = (num[0] + num[1] - 1) >> 1;
	for (int i = 0; i < mid; i++) {
		if ((idx[1] == num[1]) || ((idx[0] < num[0]) && (nums[0][idx[0]] < nums[1][idx[1]])))
			idx[0]++;
		else
			idx[1]++;
	}
	if ((idx[1] == num[1]) || ((idx[0] < num[0]) && (nums[0][idx[0]] < nums[1][idx[1]])))
		printf("%ld", nums[0][idx[0]]);
	else
		printf("%ld", nums[1][idx[1]]);

	return 0;
}