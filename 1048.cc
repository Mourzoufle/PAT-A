#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int num_coin, amount;
	scanf("%d %d", &num_coin, &amount);
	int *coins = new int[num_coin];
	for (int i = 0; i < num_coin; i++)
		scanf("%d", &coins[i]);
	sort(coins, coins + num_coin);		// sort the coins according to their face values

	int head = 0, tail = num_coin - 1;	// start searching from coins with the smallest and the largest face values
	while (head < tail) {				// when head >= tail, all the possible solutions are checked
		int cur_amount = coins[head] + coins[tail];
		if (cur_amount == amount) {		// found the solution with head having smallest value
			printf("%d %d", coins[head], coins[tail]);
			return 0;
		}
		else if (cur_amount > amount)	// current amount is too large, make tail smaller
			tail--;
		else							// or make the head larger
			head++;
	}
	printf("No Solution");
	return 0;
}