#include <cstdio>
#include <stack>
#include <set>

using namespace std;

/* balance the size of the bottom and top half of the keys in the stack, the number of the bottom keys is equal to or 1 more than those in the top */
void balance(multiset<int> &bottom, multiset<int> &top) {
	if (bottom.size() < top.size()) {				// the top half of the stack is too large
		bottom.insert(*top.begin());				// move the smallest key of it to the bottom one
		top.erase(top.begin());
	}
	else if (bottom.size() > top.size() + 1) {		// or the bottom half is too large
		top.insert(*(--bottom.end()));				// move the largest key in it to the top one
		bottom.erase(--bottom.end());
	}
}

int main() {
	int num_op;										// number of operations
	scanf("%d", &num_op);
	stack<int> stack;
	multiset<int> bottom, top;						// the bottom and top half of the keys in the stack - the 
	for (int i = 0; i < num_op; i++) {
		char cmd[16];								// current command
		scanf("%s", cmd);
		if (cmd[1] == 'u') {						// "Push"
			int key;
			scanf("%d", &key);
			stack.push(key);
			if (!bottom.empty() && (key > *(--bottom.end())))
				top.insert(key);
			else
				bottom.insert(key);
			balance(bottom, top);
		}
		else if (cmd[1] == 'o') {					// "Pop"
			if (stack.empty())
				printf("Invalid\n");
			else {
				int key = stack.top();
				stack.pop();
				printf("%d\n", key);
				if (key > *(--bottom.end()))		// the popped key is in the top half
					top.erase(top.find(key));
				else								// or in the bottom half
					bottom.erase(bottom.find(key));
				balance(bottom, top);
			}
		}
		else {										// "PeekMedian"
			if (bottom.empty())
				printf("Invalid\n");
			else
				printf("%d\n", *(--bottom.end()));	// the largest key in the bottom is the median
		}
	}

	return 0;
}