#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;

	Node(int key, Node *left, Node *right): key(key), left(left), right(right) {};
};

/* get the index of the given number in an array */
int get_idx(int *nums, int num) {
	int idx = -1;
	while (nums[++idx] != num);

	return idx;
}

/* get the root of the tree given postorder and inorder sequence */
Node* get_root(int *postorder, int *inorder, int num_node, int head, int tail) {
	if (tail < head)						// no number included, an empty tree
		return NULL;
	int idx_root, max_idx = -1;				// the index of the root in inorder sequence; the max index in postorder sequence of numbers in inorder sequence from head to tail
	for (int i = head; i <= tail; i++) {
		int cur_idx = get_idx(postorder, inorder[i]);
		if (cur_idx > max_idx) {			// the root of this (sub)tree should have the max index in postorder sequence
			max_idx = cur_idx;
			idx_root = i;
		}
	}

	return new Node(inorder[idx_root], get_root(postorder, inorder, num_node, head, idx_root - 1), get_root(postorder, inorder, num_node, idx_root + 1, tail));
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	int *postorder = new int[num_node];
	int *inorder = new int[num_node];
	for (int i = 0; i < num_node; i++)
		scanf("%d", &postorder[i]);
	for (int i = 0; i < num_node; i++)
		scanf("%d", &inorder[i]);

	queue<Node*> queue;						// level order traversal
	queue.push(get_root(postorder, inorder, num_node, 0, num_node - 1));
	while (!queue.empty()) {
		Node *node = queue.front();
		printf("%d", node->key);
		if (node->left != NULL)
			queue.push(node->left);
		if (node->right != NULL)
			queue.push(node->right);
		queue.pop();
		if (!queue.empty())
			printf(" ");
	}

	return 0;
}