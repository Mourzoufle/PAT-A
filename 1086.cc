#include <cstdio>
#include <stack>

using namespace std;

struct Node {
	int key;
	Node *left;
	Node *right;

	Node(int key): key(key), left(NULL), right(NULL) {};
};

int main() {
	stack<Node *> stack;
	int num_node;
	scanf("%d", &num_node);
	char cmd[8];																							// the command
	int key;
	scanf("%s %d", cmd, &key);																				// the first command must be Push
	Node *root = new Node(key);
	stack.push(root);
	Node *cur_node = root;
	for (int i = 1; i < num_node * 2; i++) {
		scanf("%s", cmd);
		if (cmd[1] == 'o') {																				// Pop
			cur_node = stack.top();
			stack.pop();
		}
		else {																								// Push
			scanf("%d", &key);
			Node *node = new Node(key);
			if (cur_node->left == NULL)
				cur_node->left = node;
			else
				cur_node->right = node;
			stack.push(node);
			cur_node = node;
		}
	}

	stack.push(root);
	while (!stack.empty()) {
		while (true) {
			cur_node = stack.top();
			if (cur_node->right != NULL)
				stack.push(cur_node->right);
			if (cur_node->left != NULL)
				stack.push(cur_node->left);
			if (cur_node == stack.top())																	// leaf node
				break;
		}
		printf("%d", cur_node->key);
		stack.pop();
		while ((!stack.empty()) && ((stack.top()->left == cur_node) || (stack.top()->right == cur_node))) {	// children of the currently top node are already visited
			cur_node = stack.top();
			printf(" %d", cur_node->key);
			stack.pop();
		}
		if (!stack.empty())
			printf(" ");
	}

	return 0;
}