#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int num_key;
	cin >> num_key;
	int *keys = new int[num_key];
	for (int i = 0; i < num_key; i++)
		cin >> keys[i];
	sort(keys, keys + num_key);

	int *tree = new int[num_key];
	stack<int> poses;
	int pos = 1;
	for (int i = 0; i < num_key; i++) {
		while (pos <= num_key) {
			poses.push(pos);
			pos <<= 1;
		}
		pos = poses.top();
		poses.pop();
		tree[pos - 1] = keys[i];
		pos = (pos << 1) + 1;
	}
	
	cout << tree[0];
	for (int i = 1; i < num_key; i++)
		cout << " " << tree[i];

	return 0;
}