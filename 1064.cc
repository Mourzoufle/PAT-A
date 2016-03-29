#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int num_key;
	scanf("%d", &num_key);
	int *keys = new int[num_key];
	for (int i = 0; i < num_key; i++)
		scanf("%d", &keys[i]);
	sort(keys, keys + num_key);

	int *positions = new int[num_key];	// position of each key in the tree
	stack<int> stack;					// first insert the smallest to the largest key in the tree in inorder
	int cur_node = 1;
	for (int i = 0; i < num_key; i++) {
		while (cur_node <= num_key) {
			stack.push(cur_node);
			cur_node *= 2;				// the left child of the current node
		}
		cur_node = stack.top();
		stack.pop();
		positions[cur_node - 1] = keys[i];
		cur_node = cur_node * 2 + 1;	// the right child of the current node
	}
	printf("%d", positions[0]);			// the nodes in the tree are just stored in level order
	for (int i = 1; i < num_key; i++)
		printf(" %d", positions[i]);

	return 0;
}