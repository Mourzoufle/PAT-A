#include <cstdio>

struct Node {
	int key;
	int height;
	Node *left;
	Node *right;

	Node(int key): key(key), left(NULL), right(NULL) {};
};

int get_height(Node *node) {
	if (node == NULL)
		return 0;
	else
		return node->height;
}

void set_height(Node *node) { node->height = get_height(node->left) > get_height(node->right) ? get_height(node->left) + 1 : get_height(node->right) + 1; }

Node* rotate_LL(Node *root) {
	Node *left = root->left;
	root->left = left->right;
	left->right = root;
	set_height(root);

	return left;
}

Node* rotate_RR(Node *root) {
	Node *right = root->right;
	root->right = right->left;
	right->left = root;
	set_height(root);

	return right;
}

Node* rotate_LR(Node *root) {
	root->left = rotate_RR(root->left);
	return rotate_LL(root);
}

Node* rotate_RL(Node *root) {
	root->right = rotate_LL(root->right);
	return rotate_RR(root);
}

Node* insert(Node *root, int key) {
	if (root == NULL)
		root = new Node(key);
	else if (key < root->key) {
		root->left = insert(root->left, key);
		if (get_height(root->left) - get_height(root->right) > 1) {
			if (key < root->left->key)
				root = rotate_LL(root);
			else
				root = rotate_LR(root);
		}
	}
	else {
		root->right = insert(root->right, key);
		if (get_height(root->right) - get_height(root->left) > 1) {
			if (key > root->right->key)
				root = rotate_RR(root);
			else
				root = rotate_RL(root);
		}
	}
	set_height(root);

	return root;
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	Node *root = NULL;
	for (int i = 0; i < num_node; i++) {
		int key;
		scanf("%d", &key);
		root = insert(root, key);
	}
	printf("%d", root->key);

	return 0;
}