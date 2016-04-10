#include <cstdio>
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
	scanf("%d", &num_node);
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++)
		scanf("%d %d", &nodes[i].left, &nodes[i].right);
	int *keys = new int[num_node];
	for (int i = 0; i < num_node; i++)
		scanf("%d", &keys[i]);
	sort(keys, keys + num_node);

	stack<int> stack;	// inorder traversal
	int cur_node = 0;	// current node to be visited
	for (int i = 0; i < num_node; i++) {
		while (cur_node >= 0) {
			stack.push(cur_node);
			cur_node = nodes[cur_node].left;
		}
		cur_node = stack.top();
		nodes[cur_node].key = keys[i];
		cur_node = nodes[cur_node].right;
		stack.pop();
	}

	queue<int> queue;	// level order traversal
	queue.push(0);
	for (int i = 0; i < num_node - 1; i++) {
		int node = queue.front();
		printf("%d ", nodes[node].key);
		if (nodes[node].left >= 0)
			queue.push(nodes[node].left);
		if (nodes[node].right >= 0)
			queue.push(nodes[node].right);
		queue.pop();
	}
	printf("%d", nodes[queue.front()].key);

	return 0;
}