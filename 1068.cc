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

	int **max_prices = new int *[num_coin];
	bool **select = new bool *[num_coin];
	for (int i = 0; i < num_coin; i++) {
		max_prices[i] = new int[price + 1];
		select[i] = new bool[price + 1];
	}
	for (int i = 0; i <= price; i++) {
		select[num_coin - 1][i] = i >= coins[num_coin - 1];
		max_prices[num_coin - 1][i] = select[num_coin - 1][i] ? coins[num_coin - 1] : 0;
	}
	for (int i = num_coin - 2; i >= 0; i--) {
		for (int j = 0; j <= price; j++) {
			select[i][j] = ((j >= coins[i]) && (max_prices[i + 1][j - coins[i]] + coins[i] >= max_prices[i + 1][j]));
			max_prices[i][j] = select[i][j] ? max_prices[i + 1][j - coins[i]] + coins[i] : max_prices[i + 1][j];
		}
	}
	if (max_prices[0][price] < price)
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