#include <cstdio>
#include <stack>

using namespace std;

/* check if the given pop sequence is valid w.r.t. the stack with the given capacity */
bool is_valid(int *nums, int num_num, int capcity) {
	stack<int> stack;
	int last_pop = 0;							// the last number that is poped
	for (int i = 0; i < num_num; i++) {
		if (nums[i] - i > capcity)				// the number of numbers that haven't been poped is more than the capacity - invalid
			return false;
		if (nums[i] > last_pop) {				// current poped number is larger than the last poped one - numbers between them are pushed in the stack
			for (int j = last_pop + 1; j < nums[i]; j++)
				stack.push(j);
			last_pop = nums[i];
		}
		else {									// or the current poped number should be the top number in the stack
			if (nums[i] != stack.top())
				return false;
			stack.pop();
		}
	}
	return true;
}

int main() {
	int capcity, num_num, num_seq;				// the capacity of the stack; number of numbers in pop sequences; number of sequences
	scanf("%d %d %d", &capcity, &num_num, &num_seq);
	for (int i = 0; i < num_seq; i++) {
		int *nums = new int[num_num];
		for (int j = 0; j < num_num; j++)
			scanf("%d", &nums[j]);
		if (is_valid(nums, num_num, capcity))	// check if the pop sequence is valid
			printf("YES\n");
		else
			printf("NO\n");
		delete[] nums;
	}

	return 0;
}