#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int num_num, para;								// number of the numbers; the paramater
	scanf("%d %d", &num_num, &para);
	int *nums = new int[num_num];
	for (int i = 0; i < num_num; i++)
		scanf("%d", &nums[i]);
	sort(nums, nums + num_num);

	int length = 1;									// the max length of perfect sequence
	for (int i = 0; i + length < num_num; i++) {	// halt when no larger length can be found
		while (i + length < num_num) {
			if (1.0 * nums[i + length] / nums[i] > para)
				break;
			length++;
		}
	}
	printf("%d", length);

	return 0;
}