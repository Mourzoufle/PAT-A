#include <cstdio>

const int MAX_NUM = 10000;

int main() {
	int *nums_bet = new int[MAX_NUM];		// numbers of bets on each number
	for (int i = 0; i < MAX_NUM; i++)
		nums_bet[i] = 0;
	int num_num;
	scanf("%d", &num_num);
	int *nums = new int[num_num];
	for (int i = 0; i < num_num; i++) {
		scanf("%d", &nums[i]);
		nums_bet[nums[i] - 1]++;
	}

	for (int i = 0; i < num_num; i++) {
		if (nums_bet[nums[i] - 1] == 1) {	// find the first unique number, print it
			printf("%d", nums[i]);
			return 0;
		}
	}
	printf("None");							// no unique number found
	return 0;
}