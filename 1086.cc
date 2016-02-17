#include <iostream>
#include <stack>

using namespace std;

struct Node {
	int value;
	Node *left;
	Node *right;

	Node(int value): value(value), left(NULL), right(NULL) {};
};

void postorder(Node *root, bool is_root) {
	if (root->left != NULL)
		postorder(root->left, false);
	if (root->right != NULL)
		postorder(root->right, false);
	cout << root->value;
	if (!is_root)
		cout << " ";
}

int main() {
	int num_node;
	cin >> num_node;
	stack<Node *> stack;
	string cmd;
	int value;
	cin >> cmd >> value;
	Node *root = new Node(value);
	Node *cur = root;
	stack.push(root);
	for (int i = 1; i < (num_node << 1); i++) {
		cin >> cmd;
		if (cmd == "Pop") {
			cur = stack.top();
			stack.pop();
		}
		else {
			cin >> value;
			Node *node = new Node(value);
			if (cur->left == NULL)
				cur->left = node;
			else
				cur->right = node;
			stack.push(node);
			cur = node;
		}
	}
	postorder(root, true);

	return 0;
}