#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	int left;
	int right;
};

int main() {
	int num_node;
	cin >> num_node;
	Node *nodes = new Node[num_node];
	bool *is_root = new bool[num_node];
	for (int i = 0; i < num_node; i++)
		is_root[i] = true;
	for (int i = 0; i < num_node; i++) {
		string left, right;
		cin >> left >> right;
		nodes[i].right = (left == "-" ? -1 : left[0] - '0');
		nodes[i].left = (right == "-" ? -1 : right[0] - '0');
		if (nodes[i].left >= 0)
			is_root[nodes[i].left] = false;
		if (nodes[i].right >= 0)
			is_root[nodes[i].right] = false;
	}
	int root;
	for (int i = 0; i < num_node; i++) {
		if (is_root[i]) {
			root = i;
			break;
		}
	}

	queue<int> queue;
	queue.push(root);
	while (!queue.empty()) {
		int cur = queue.front();
		queue.pop();
		if (nodes[cur].left >= 0)
			queue.push(nodes[cur].left);
		if (nodes[cur].right >= 0)
			queue.push(nodes[cur].right);
		cout << cur;
		if (!queue.empty())
			cout << " ";
		else
			cout << endl;
	}

	stack<int> stack;
	int cur = root;
	for (int i = 0; i < num_node; i++) {
		while (cur >= 0) {
			stack.push(cur);
			cur = nodes[cur].left;
		}
		cur = stack.top();
		stack.pop();
		if (i > 0)
			cout << " ";
		cout << cur;
		cur = nodes[cur].right;
	}

	return 0;
}