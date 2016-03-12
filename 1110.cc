#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int left;
	int right;
	bool is_root;

	Node(): left(-1), right(-1), is_root(true) {};
};

int str_to_int(char *str) {
	int num = 0;
	for (int i = 0; str[i] != '\0'; i++)
		num = num * 10 + str[i] - '0';

	return num;
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++) {
		char left[4], right[4];
		scanf("%s %s", left, right);
		if (left[0] != '-') {
			int node = str_to_int(left);
			nodes[i].left = node;
			nodes[node].is_root = false;
		}
		if (right[0] != '-') {
			int node = str_to_int(right);
			nodes[i].right = node;
			nodes[node].is_root = false;
		}
	}

	int root = -1;
	while (!nodes[++root].is_root);
	queue<int> queue;
	queue.push(root);
	while (!queue.empty()) {
		int node = queue.front();
		if (node < 0) {
			if (num_node > 0) {
				printf("NO %d", root);
				break;
			}
		}
		else {
			if (--num_node == 0) {
				printf("YES %d", node);
				break;
			}
			queue.push(nodes[node].left);
			queue.push(nodes[node].right);
		}
		queue.pop();
	}

	return 0;
}