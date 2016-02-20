#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int *ori = new int[num];
	int *cur = new int[num];
	for (int i = 0; i < num; i++)
		cin >> ori[i];
	for (int i = 0; i < num; i++)
		cin >> cur[i];

	if (cur[0] < cur[1]) {
		cout << "Insertion Sort" << endl;
		int idx = 1;
		while (++idx < num)
			if (cur[idx] < cur[idx - 1])
				break;
		for (int i = 0; i < idx; i++) {
			if (i > 0)
				cout << " ";
			if (cur[i] < cur[idx])
				cout << cur[i];
			else {
				cout << cur[idx];
				while (i < idx)
					cout << " " << cur[i++];
			}
		}
		for (int i = idx + 1; i < num; i++)
			cout << " " << cur[i];
	}
	else {
		cout << "Heap Sort" << endl;
		int max_idx = num;
		while (cur[0] < cur[--max_idx]);
		cur[0] ^= cur[max_idx];
		cur[max_idx] ^= cur[0];
		cur[0] ^= cur[max_idx];
		max_idx--;
		int cur_idx = 0;
		while ((cur_idx << 1) + 1 <= max_idx) {
			int idx = (cur_idx << 1) + 1;
			if ((idx < max_idx) && (cur[idx] < cur[idx + 1]))
				idx++;
			cur[cur_idx] ^= cur[idx];
			cur[idx] ^= cur[cur_idx];
			cur[cur_idx] ^= cur[idx];
			cur_idx = idx;
		}
		cout << cur[0];
		for (int i = 1; i < num; i++)
			cout << " " << cur[i];
	}

	return 0;
}