#include <cstdio>
#include <stack>

using namespace std;

const int MAX_NODE = 100000;

int main() {
	int *nexts = new int[MAX_NODE];															// next node of each node
	int heads[2];																			// head node of each word
	int num_node;
	scanf("%d %d %d", &heads[0], &heads[1], &num_node);
	for (int i = 0; i < num_node; i++) {
		int cur_node, next_node;
		char c;																				// the letter contained in the node is useless
		scanf("%d %c %d", &cur_node, &c, &next_node);
		nexts[cur_node] = next_node;
	}

	stack<int> words[2];																	// each word is represented by letters in a stack
	for (int i = 0; i < 2; i++) {
		int cur_node = heads[i];
		while (cur_node >= 0) {
			words[i].push(cur_node);
			cur_node = nexts[cur_node];
		}
	}
	int idx_suffix = -1;
	while (!words[0].empty() && !words[1].empty() && (words[0].top() == words[1].top())) {	// find the first common node from the back to the top of the stacks
		idx_suffix = words[0].top();
		words[0].pop();
		words[1].pop();
	}
	if (idx_suffix < 0)																		// no common suffix
		printf("-1");
	else
		printf("%05d", idx_suffix);

	return 0;
}