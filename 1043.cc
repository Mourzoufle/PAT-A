#include <iostream>
#include <stack>

using namespace std;

bool travel(bool is_mirror, int *preorder, int head, int tail, stack<int> &order) {
	order.push(preorder[head]);
	int right = head;
	while (++right <= tail)
		if (!(is_mirror^(preorder[head] > preorder[right])))
			break;
	for (int i = right; i <= tail; i++)
		if (is_mirror^(preorder[head] > preorder[i]))
			return false;
	if (right <= tail)
		if (!travel(is_mirror, preorder, right, tail, order))
			return false;
	if (head <= right - 2)
		if (!travel(is_mirror, preorder, head + 1, right - 1, order))
			return false;

	return true;
}

int main() {
	int num_node;
	cin >> num_node;
	int *preorder = new int[num_node];
	for (int i = 0; i < num_node; i++)
		cin >> preorder[i];
	stack<int> postorder;
	if (!travel(preorder[0] <= preorder[1], preorder, 0, num_node - 1, postorder))
		cout << "NO";
	else {
		cout << "YES" << endl << postorder.top();
		postorder.pop();
		while (postorder.size() > 0) {
			cout << " " << postorder.top();
			postorder.pop();
		}
	}

	return 0;
}