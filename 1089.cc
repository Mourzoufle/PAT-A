#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num;
	cin >> num;
	int *ori = new int[num];
	for (int i = 0; i < num; i++)
		cin >> ori[i];
	int *sorted = new int[num];
	for (int i = 0; i < num; i++)
		cin >> sorted[i];
	int idx;
	for (idx = 1; idx < num; idx++)
		if (sorted[idx] < sorted[idx - 1])
			break;
	bool is_insert = true;
	for (int i = idx; i < num; i++) {
		if (ori[i] != sorted[i]) {
			is_insert = false;
			break;
		}
	}

	if (is_insert) {
		cout << "Insertion Sort" << endl;
		for (int i = 0; i < idx; i++) {
			if (i > 0)
				cout << " ";
			if (sorted[i] < sorted[idx])
				cout << sorted[i];
			else {
				cout << sorted[idx];
				while (i < idx)
					cout << " " << sorted[i++];
			}
		}
		for (int i = idx + 1; i < num; i++)
			cout << " " << sorted[i];
	}
	else {
		cout << "Merge Sort" << endl;
		int length;
		for (length = 4; (length >> 1) < num; length <<= 1) {
			bool complete = true;
			for (idx = 0; idx + length < num; idx += length) {
				for (int i = idx + 1; i < idx + length; i++) {
					if (sorted[i] < sorted[i - 1]) {
						complete = false;
						break;
					}
				}
				if (!complete)
					break;
			}
			for (int i = idx + 1; i < num; i++) {
				if (sorted[i] < sorted[i - 1]) {
					complete = false;
					break;
				}
			}
			if (!complete)
				break;
		}
		for (idx = 0; idx + length < num; idx += length)
			sort(sorted + idx, sorted + idx + length);
		sort(sorted + idx, sorted + num);
		cout << sorted[0];
		for (int i = 1; i < num; i++)
			cout << " " << sorted[i];
	}

	return 0;
}