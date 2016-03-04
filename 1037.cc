#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int nums_num[2];
	int *nums[2];
	for (int i = 0; i < 2; i++) {
		scanf("%d", &nums_num[i]);
		nums[i] = new int[nums_num[i]];
		for (int j = 0; j < nums_num[i]; j++)
			scanf("%d", &nums[i][j]);
		sort(nums[i], nums[i] + nums_num[i]);
	}

	int sum = 0;
	for (int i = 0; (i < nums_num[0]) && (i < nums_num[1]); i++) {
		if ((nums[0][i] >= 0) || (nums[1][i] >= 0))
			break;
		sum += nums[0][i] * nums[1][i];
	}
	for (int i = 1; (i <= nums_num[0]) && (i <= nums_num[1]); i++) {
		if ((nums[0][nums_num[0] - i] <= 0) || (nums[1][nums_num[1] - i] <= 0))
			break;
		sum += nums[0][nums_num[0] - i] * nums[1][nums_num[1] - i];
	}
	printf("%d", sum);

	return 0;
}