#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int num_coin, price;
	scanf("%d %d", &num_coin, &price);
	int *coins = new int[num_coin];
	for (int i = 0; i < num_coin; i++)
		scanf("%d", &coins[i]);
	sort(coins, coins + num_coin);

	int *max_prices = new int [price + 1];					// Knapsack problem - Dynamic Programming with a table of final states
	for (int i = 0; i <= price; i++)
		max_prices[i] = 0;
	bool **select = new bool *[num_coin];					// flag that whether each coin is selected to pay different price
	for (int i = 0; i < num_coin; i++) {
		select[i] = new bool[price + 1];
		for (int j = 0; j <= price; j++)
			select[i][j] = false;
	}
	for (int i = coins[num_coin - 1]; i <= price; i++) {	// first assume only the coin with the largest face value is available
		max_prices[i] = coins[num_coin - 1];
		select[num_coin - 1][i] = true;
	}
	for (int i = num_coin - 2; i >= 0; i--) {				// then add the coins from the largest to the smallest - NOTE that smaller coins are preferred when the max prices are same
		for (int j = price; j >= coins[i]; j--) {
			if (max_prices[j - coins[i]] + coins[i] >= max_prices[j]) {
				max_prices[j] = max_prices[j - coins[i]] + coins[i];
				select[i][j] = true;
			}
		}
	}
	if (max_prices[price] < price)							// cannot pay the price exactly
		printf("No Solution");
	else {
		int idx = -1;
		while (price > 0) {
			while (!select[++idx][price]);
			printf("%d", coins[idx]);
			price -= coins[idx];
			if (price > 0)
				printf(" ");
		}
	}

	return 0;
}