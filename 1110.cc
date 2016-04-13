#include <cstdio>
#include <cstdlib>
#include <queue>

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
			nodes[i].left = atoi(left);
			nodes[atoi(left)].is_root = false;
		}
		if (right[0] != '-') {
			nodes[i].right = atoi(right);
			nodes[atoi(right)].is_root = false;
		}
	}
	int root = -1;
	while (!nodes[++root].is_root);

	queue<int> queue;				// level order traversal
	queue.push(root);
	while (!queue.empty()) {
		int node = queue.front();
		if (node < 0) {				// find an empty position in the tree
			if (num_node > 0) {		// ...and there is still node unread - not a CBT
				printf("NO %d", root);
				break;
			}
		}
		else {
			if (--num_node == 0) {	// all nodes are read without encountering an empty position - CBT
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