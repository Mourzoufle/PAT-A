#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node {
	int addr;
	int value;
	int next;
};

bool compare(const Node* a, const Node* b) { return a->value < b->value; }

int main() {
	int num_node, head;
	scanf("%d %d", &num_node, &head);
	Node *nodes = new Node[num_node];
	map<int, int> indices;
	for (int i = 0; i < num_node; i++) {
		scanf("%d %d %d", &nodes[i].addr, &nodes[i].value, &nodes[i].next);
		indices.insert(pair<int, int>(nodes[i].addr, i));
	}
	vector<Node *> list;
	while (indices.find(head) != indices.end()) {
		list.push_back(nodes + indices[head]);
		head = nodes[indices[head]].next;
	}
	sort(list.begin(), list.end(), compare);
	if (list.empty())
		printf("0 -1");
	else {
		printf("%d %05d\n", list.size(), (*list.begin())->addr);
		for (vector<Node *>::iterator iter = list.begin(); iter != list.end(); iter++) {
			printf("%05d %d ", (*iter)->addr, (*iter)->value);
			if (iter + 1 != list.end())
				printf("%05d\n", (*(iter + 1))->addr);
			else
				printf("-1\n");
		}
	}
	
	return 0;
}