#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int *values = new int[num];
	for (int i = 0; i < num; i++)
		cin >> values[i];
	int max_head, max_tail, max_sum = -1;
	int cur_head = 0, cur_tail = -1, cur_sum;
	for (int i = 0; i < num; i++) {
		if (cur_head > cur_tail)
			cur_sum = values[i];
		else
			cur_sum += values[i];
		if (cur_sum < 0) {
			cur_head = i + 1;
			cur_tail = i;
		}
		else {
			cur_tail++;
			if (max_sum < cur_sum) {
				max_head = cur_head;
				max_tail = cur_tail;
				max_sum = cur_sum;
			}
		}
	}
	if (max_sum < 0) {
		max_head = 0;
		max_tail = num - 1;
		max_sum = 0;
	}
	cout << max_sum << " " << values[max_head] << " " << values[max_tail];

	return 0;
}