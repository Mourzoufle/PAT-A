#include <cstdio>
#include <vector>

using namespace std;

/* check if the given preorder (from head to tail) is the preorder of a BST or a mirror of BST, and generate the postorder for it */
bool is_bst(bool is_mirror, int *preorder, int head, int tail, vector<int> &postorder) {
	postorder.push_back(preorder[head]);							// the root is the first node in the preorder
	int head_right = head;											// the head of the right subtree
	while (++head_right <= tail)
		if (!(is_mirror^(preorder[head] > preorder[head_right])))	// for a BST tree (is_mirror = 0), find the first node not less than the head; otherwise find the first less node
			break;
	for (int i = head_right; i <= tail; i++)						// for a BST tree, check if there is any node in the right subtree that less than head; otherwise check if all of them are less
		if (is_mirror^(preorder[head] > preorder[i]))
			return false;
	if (head_right <= tail)											// if current node has right child, check on it
		if (!is_bst(is_mirror, preorder, head_right, tail, postorder))
			return false;
	if (head <= head_right - 2)										// if current node has left child, check on it
		if (!is_bst(is_mirror, preorder, head + 1, head_right - 1, postorder))
			return false;
	return true;
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	int *preorder = new int[num_node];
	for (int i = 0; i < num_node; i++)
		scanf("%d", &preorder[i]);

	vector<int> postorder;											// the postorder of the tree
	if (!is_bst(false, preorder, 0, num_node - 1, postorder)) {		// if it is impossible to be a BST
		postorder.clear();											// ...then clear the generated postorder and check if it is a mirror of BST
		if (!is_bst(true, preorder, 0, num_node - 1, postorder))
			postorder.clear();
	}
	if (postorder.empty())											// the postorder is cleared twice, not a BST or its mirror
		printf("NO");
	else {															// or print the postorder
		printf("YES\n%d", postorder.back());
		for (int i = postorder.size() - 2; i >= 0; i--)
			printf(" %d", postorder[i]);
	}

	return 0;
}