#include <iostream>
#include <vector>

using namespace std;

bool is_unique(int *preorder, int *postorder, int pre_head, int pre_tail, int post_head, int post_tail, vector<int> &inorder) {
	if (pre_head > pre_tail)
		return false;
	if (pre_head == pre_tail) {
		inorder.push_back(preorder[pre_head]);
		return true;
	}

	int tail = post_head - 1;
	while (++tail < post_tail)
		if (preorder[pre_head + 1] == postorder[tail])
			break;

	bool res = true;
	res &= is_unique(preorder, postorder, pre_head + 1, pre_head + 1 + tail - post_head, post_head, tail, inorder);
	inorder.push_back(preorder[pre_head]);
	res &= is_unique(preorder, postorder, pre_head + 2 + tail - post_head, pre_tail, tail + 1, post_tail - 1, inorder);
	return res;
}

int main() {
	int num_node;
	cin >> num_node;
	int *preorder = new int[num_node];
	int *postorder = new int[num_node];
	for (int i = 0; i < num_node; i++)
		cin >> preorder[i];
	for (int i = 0; i < num_node; i++)
		cin >> postorder[i];
	vector<int> inorder;
	if (is_unique(preorder, postorder, 0, num_node - 1, 0, num_node - 1, inorder))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << inorder.front();
	for (int i = 1; i < num_node; i++)
		cout << " " << inorder[i];
	cout << endl;

	return 0;
}