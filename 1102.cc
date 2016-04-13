#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	int left;
	int right;
	bool is_root;

	Node(): left(-1), right(-1), is_root(true) {};
};

int main() {
	int num_node;
	scanf("%d", &num_node);
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++) {
		char left[4], right[4];
		scanf("%s %s", &left, &right);
		if (left[0] != '-') {
			nodes[i].right = left[0] - '0';							// swap the left and right children
			nodes[left[0] - '0'].is_root = false;
		}
		if (right[0] != '-') {
			nodes[i].left = right[0] - '0';
			nodes[right[0] - '0'].is_root = false;
		}
	}

	int root;
	for (int i = 0; i < num_node; i++) {
		if (nodes[i].is_root) {
			root = i;
			break;
		}
	}

	queue<int> queue;												// level-order traversal
	queue.push(root);
	while (!queue.empty()) {
		int node = queue.front();
		if (nodes[node].left >= 0)
			queue.push(nodes[node].left);
		if (nodes[node].right >= 0)
			queue.push(nodes[node].right);
		printf("%d", node);
		queue.pop();
		if (!queue.empty())
			printf(" ");
	}
	printf("\n");

	stack<int> stack;												// in-order traversal
	int cur_node = root;
	for (int i = 0; i < num_node; i++) {
		if (i > 0)
			printf(" ");
		while (cur_node >= 0) {
			stack.push(cur_node);
			cur_node = nodes[cur_node].left;
		}
		cur_node = stack.top();
		stack.pop();
		printf("%d", cur_node);
		cur_node = nodes[cur_node].right;
	}

	return 0;
}