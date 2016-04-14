#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;

	Node(int key): key(key), left(NULL), right(NULL) {}
};

int main() {
	int num_node, key;
	scanf("%d %d", &num_node, &key);
	Node *root = new Node(key);
	for (int i = 1; i < num_node; i++) {
		scanf("%d", &key);
		Node *cur_node = root;
		while (true) {
			if (key <= cur_node->key) {
				if (cur_node->left == NULL) {
					cur_node->left = new Node(key);
					break;
				}
				else
					cur_node = cur_node->left;
			}
			else {
				if (cur_node->right == NULL) {
					cur_node->right = new Node(key);
					break;
				}
				else
					cur_node = cur_node->right;
			}
		}
	}

	queue<Node *> queue;	// level order traversal
	queue.push(root);
	int sizes[2] = {0, 0};	// size of the last level; the second last level
	while (!queue.empty()) {
		sizes[1] = sizes[0];
		sizes[0] = queue.size();
		for (int i = 0; i < sizes[0]; i++) {
			Node *cur_node = queue.front();
			if (cur_node->left != NULL)
				queue.push(cur_node->left);
			if (cur_node->right != NULL)
				queue.push(cur_node->right);
			queue.pop();
		}
	}
	printf("%d + %d = %d", sizes[0], sizes[1], sizes[0] + sizes[1]);

	return 0;
}