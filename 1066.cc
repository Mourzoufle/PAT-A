#include <cstdio>

struct Node {
	int key;
	int height;
	Node *left;
	Node *right;

	Node(int key): key(key), left(NULL), right(NULL) {};
};

/* get the height of the current node */
int get_height(Node *node) {
	if (node == NULL)
		return 0;
	else
		return node->height;
}

/* set the height of the current node, the height is max(get_height(left), get_height(right)) + 1 */
void set_height(Node *node) { node->height = get_height(node->left) > get_height(node->right) ? get_height(node->left) + 1 : get_height(node->right) + 1; }

/* rotate function for the case that the new key is inserted into the left subtree of the left child and causes unbalance */
Node* rotate_LL(Node *root) {
	Node *left = root->left;
	root->left = left->right;
	left->right = root;
	set_height(root);	// DO NOT FORGET - the height of root is changed and should be updated immediately

	return left;
}

/* rotate function for the case that the new key is inserted into the right subtree of the right child and causes unbalance */
Node* rotate_RR(Node *root) {
	Node *right = root->right;
	root->right = right->left;
	right->left = root;
	set_height(root);	// DO NOT FORGET - the height of root is changed and should be updated immediately

	return right;
}

/* rotate function for the case that the new key is inserted into the right subtree of the left child and causes unbalance */
Node* rotate_LR(Node *root) {
	root->left = rotate_RR(root->left);
	return rotate_LL(root);
}

/* rotate function for the case that the new key is inserted into the left subtree of the right child and causes unbalance */
Node* rotate_RL(Node *root) {
	root->right = rotate_LL(root->right);
	return rotate_RR(root);
}

/* insert a key */
Node* insert(Node *root, int key) {
	if (root == NULL)
		root = new Node(key);
	else if (key < root->key) {
		root->left = insert(root->left, key);
		if (get_height(root->left) - get_height(root->right) > 1) {
			if (key < root->left->key)
				return rotate_LL(root);
			else
				return rotate_LR(root);
		}
	}
	else {
		root->right = insert(root->right, key);
		if (get_height(root->right) - get_height(root->left) > 1) {
			if (key > root->right->key)
				return rotate_RR(root);
			else
				return rotate_RL(root);
		}
	}
	set_height(root);	// update the height of the root
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