#include <cstdio>
#include <cstring>
#include <stack>
#include <set>

using namespace std;

multiset<int>::iterator last(multiset<int> &set) {
	multiset<int>::iterator pos = set.end();
	return --pos;
}

void reset(multiset<int> &left, multiset<int> &right) {
	if (left.size() < right.size()) {
		left.insert(*right.begin());
		right.erase(right.begin());
	}
	else if (left.size() > right.size() + 1) {
		right.insert(*last(left));
		left.erase(last(left));
	}
}

int main() {
	int num_op;
	scanf("%d", &num_op);
	stack<int> stack;
	multiset<int> left, right;
	for (int i = 0; i < num_op; i++) {
		char cmd[16];
		scanf("%s", cmd);
		if (strcmp(cmd, "Push") == 0) {
			int key;
			scanf("%d", &key);
			stack.push(key);
			if (!left.empty() && (key > *last(left)))
				right.insert(key);
			else
				left.insert(key);
			reset(left, right);
		}
		else if (strcmp(cmd, "Pop") == 0) {
			if (stack.empty())
				printf("Invalid\n");
			else {
				int key = stack.top();
				stack.pop();
				printf("%d\n", key);
				if (key > *last(left))
					right.erase(right.find(key));
				else
					left.erase(left.find(key));
				reset(left, right);
			}
		}
		else {
			if (left.empty())
				printf("Invalid\n");
			else
				printf("%d\n", *last(left));
		}
	}

	return 0;
}