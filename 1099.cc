#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	int key;
	int left;
	int right;
};

int main() {
	int num_node;
	cin >> num_node;
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++)
		cin >> nodes[i].left >> nodes[i].right;
	int *keys = new int[num_node];
	for (int i = 0; i < num_node; i++)
		cin >> keys[i];
	sort(keys, keys + num_node);

	stack<int> stack;
	int cur = 0;
	for (int i = 0; i < num_node; i++) {
		while (cur >= 0) {
			stack.push(cur);
			cur = nodes[cur].left;
		}
		cur = stack.top();
		stack.pop();
		nodes[cur].key = keys[i];
		cur = nodes[cur].right;
	}

	queue<int> queue;
	queue.push(0);
	while (!queue.empty()) {
		int idx = queue.front();
		queue.pop();
		if (nodes[idx].left >= 0)
			queue.push(nodes[idx].left);
		if (nodes[idx].right >= 0)
			queue.push(nodes[idx].right);
		cout << nodes[idx].key;
		if (!queue.empty())
			cout << " ";
	}

	return 0;
}