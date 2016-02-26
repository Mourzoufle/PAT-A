#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;

	Node(int key, Node *left, Node *right): key(key), left(left), right(right) {};
};

Node* traversal(int *posts, int *ins, int num_node, int head, int tail) {
	int idx = -1;
	if (tail < head)
		return NULL;
	for (int i = num_node - 1; i >= 0; i--) {
		for (int j = head; j <= tail; j++) {
			if (posts[i] == ins[j]) {
				idx = j;
				break;
			}
		}
		if (idx >= 0)
			break;
	}
	return new Node(ins[idx], traversal(posts, ins, num_node, head, idx - 1), traversal(posts, ins, num_node, idx + 1, tail));
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	int *posts = new int[num_node];
	int *ins = new int[num_node];
	for (int i = 0; i < num_node; i++)
		scanf("%d", &posts[i]);
	for (int i = 0; i < num_node; i++)
		scanf("%d", &ins[i]);

	Node *root = traversal(posts, ins, num_node, 0, num_node - 1);
	queue<Node*> queue;
	queue.push(root);
	printf("%d", root->key);
	while (!queue.empty()) {
		if (queue.front()->left != NULL) {
			printf(" %d", queue.front()->left->key);
			queue.push(queue.front()->left);
		}
		if (queue.front()->right != NULL) {
			printf(" %d", queue.front()->right->key);
			queue.push(queue.front()->right);
		}
		queue.pop();
	}

	return 0;
}