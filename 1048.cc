#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num_coin, amount;
	cin >> num_coin >> amount;
	int *coins = new int[num_coin];
	for (int i = 0; i < num_coin; i++)
		cin >> coins[i];
	sort(coins, coins + num_coin);
	int head = 0, tail = num_coin - 1;
	while (head < tail) {
		int sum = coins[head] + coins[tail];
		if (sum == amount) {
			cout << coins[head] << " " << coins[tail];
			return 0;
		}
		else if (sum > amount)
			tail--;
		else
			head++;
	}
	cout << "No Solution";

	return 0;
}