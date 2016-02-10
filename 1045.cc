#include <iostream>

using namespace std;

int main() {
	int num_color, num_favor, size_stripe;
	cin >> num_color >> num_favor;
	int *order = new int[num_color + 1];
	for (int i = 1; i <= num_color; i++)
		order[i] = -1;
	for (int i = 0; i < num_favor; i++) {
		int color;
		cin >> color;
		order[color] = i;
	}
	cin >> size_stripe;
	int *stripe = new int[size_stripe];
	for (int i = 0; i < size_stripe; i++)
		cin >> stripe[i];

	int *lengths = new int[size_stripe];
	int max_length = 0;
	for (int i = 0; i < size_stripe; i++) {
		lengths[i] = 0;
		if (order[stripe[i]] < 0)
			continue;
		for (int j = 0; j < i; j++)
			if ((lengths[j] > lengths[i]) && (order[stripe[j]] <= order[stripe[i]]))
				lengths[i] = lengths[j];
		if (++lengths[i] > max_length)
			max_length = lengths[i];
	}
	cout << max_length;

	return 0;
}