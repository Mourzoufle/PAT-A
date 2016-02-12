#include <iostream>
#include <stack>

using namespace std;

bool check(int capcity, int *items, int num_item) {
	stack<int> tops;
	int max = 0;
	for (int i = 0; i < num_item; i++) {
		if (items[i] - i > capcity)
			return false;
		if (items[i] > max) {
			for (int j = max + 1; j < items[i]; j++)
				tops.push(j);
			max = items[i];
		}
		else {
			if (items[i] < tops.top())
				return false;
			tops.pop();
		}
	}

	return true;
}

int main() {
	int capcity, num_item, num_seq;
	cin >> capcity >> num_item >> num_seq;
	int *items = new int[num_item];
	for (int r = 0; r < num_seq; r++) {
		for (int i = 0; i < num_item; i++)
			cin >> items[i];
		if (check(capcity, items, num_item))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}