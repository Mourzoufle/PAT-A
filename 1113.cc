#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int num_num;
	scanf("%d", &num_num);
	int *nums = new int[num_num];
	for (int i = 0; i < num_num; i++)
		scanf("%d", &nums[i]);
	sort(nums, nums + num_num);

	int diff = 0;
	for (int i = 0; i < num_num / 2; i++)
		diff -= nums[i];
	for (int i = num_num / 2; i < num_num; i++)
		diff += nums[i];
	printf("%d %d", num_num % 2, diff);

	return 0;
}