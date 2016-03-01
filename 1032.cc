#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int *nexts = new int[100000];
	int heads[2];
	int num_node;
	scanf("%d %d %d", &heads[0], &heads[1], &num_node);
	for (int i = 0; i < num_node; i++) {
		int cur, next;
		char c;
		scanf("%d %c %d", &cur, &c, &next);
		nexts[cur] = next;
	}

	stack<int> stacks[2];
	for (int i = 0; i < 2; i++) {
		int cur = heads[i];
		while (cur >= 0) {
			stacks[i].push(cur);
			cur = nexts[cur];
		}
	}
	int idx = -1;
	while (!stacks[0].empty() && !stacks[1].empty() && (stacks[0].top() == stacks[1].top())) {
		idx = stacks[0].top();
		stacks[0].pop();
		stacks[1].pop();
	}
	if (idx < 0)
		printf("-1");
	else
		printf("%05d", idx);

	return 0;
}