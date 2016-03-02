#include <cstdio>

int main() {
	int num_num;													// number of the numbers
	scanf("%d", &num_num);
	int *nums = new int[num_num];
	for (int i = 0; i < num_num; i++)
		scanf("%d", &nums[i]);

	int max_head, max_tail, max_sum = -1, cur_head = 0, cur_sum;	// sequence with max sum & sequence with current number
	for (int i = 0; i < num_num; i++) {
		if (cur_head == i)											// current sequence is empty - the sum is the current number
			cur_sum = nums[i];
		else
			cur_sum += nums[i];										// or add the current number
		if (cur_sum < 0)											// current sequence is useless - clear it
			cur_head = i + 1;
		else if (cur_sum > max_sum) {								// got a new max sequence
			max_head = cur_head;
			max_tail = i;
			max_sum = cur_sum;
		}
	}
	if (max_sum < 0) {												// handle this situation according to the rule
		max_head = 0;
		max_tail = num_num - 1;
		max_sum = 0;
	}
	printf("%d %d %d", max_sum, nums[max_head], nums[max_tail]);

	return 0;
}