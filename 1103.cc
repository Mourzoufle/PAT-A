#include <iostream>
#include <cmath>

using namespace std;

void replace(int *best, int *cur, int num_item) {
	int sum = 0;
	for (int i = 0; i < num_item; i++)
		sum += best[i] - cur[i];
	if (sum < 0)
		for (int i = 0; i < num_item; i++)
			best[i] = cur[i];
}

int main() {
	int sum, num_item, expon;
	cin >> sum >> num_item >> expon;
	int limit = sqrt(sum + 1 - num_item);
	if (expon > 3)
		limit = sqrt(limit);
	int *expons = new int[limit + 1];
	for (int i = 0; i <= limit; i++)
		expons[i] = pow(i, expon) + 0.5;

	int *best = new int[num_item];
	int *cur = new int[num_item];
	for (int i = 0; i < num_item;i++) {
		best[i] = 0;
		cur[i] = limit;
	}
	int idx = 0, cur_sum = 0;
	while (idx >= 0) {
		if (cur[idx] == 0) {
			if (idx == 0)
				break;
			cur_sum -= expons[cur[--idx]--];
			continue;
		}
		cur_sum += expons[cur[idx]];
		if (cur_sum < sum) {
			if (idx < num_item - 1) {
				idx++;
				cur[idx] = cur[idx - 1];
			}
			else {
				cur_sum -= expons[cur[idx]] + expons[cur[idx - 1]];
				cur[--idx]--;
			}
		}
		else if ((cur_sum == sum) && (idx == num_item - 1)) {
			replace(best, cur, num_item);
			cur_sum -= expons[cur[idx]] + expons[cur[idx - 1]];
			cur[--idx]--;
		}
		else
			cur_sum -= expons[cur[idx]--];
	}

	if (best[0] == 0)
		cout << "Impossible";
	else {
		cout << sum << " = " << best[0] << "^" << expon;
		for (int i = 1; i < num_item; i++)
			cout << " + " << best[i] << "^" << expon;
	}

	return 0;
}