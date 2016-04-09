#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int MAX_NODE = 100000;

struct Node {
	int value;
	int next;

	Node(): next(-1) {};
};

int main() {
	Node *nodes = new Node[MAX_NODE];
	int num_node, head;
	scanf("%d %d", &head, &num_node);
	for (int i = 0; i < num_node; i++) {
		int cur_node;								// address of the current node
		scanf("%d", &cur_node);
		scanf("%d %d", &nodes[cur_node].value, &nodes[cur_node].next);
	}

	vector<Node *> nodes_valid[2];					// the nodes that belong to the list beginning with head and are reserved or remained
	set<int> values;
	while (head >= 0) {
		int value = nodes[head].value;
		if (value < 0)
			value = -value;
		if (values.find(value) == values.end()) {	// value has not been found before - this node is reserved
			nodes_valid[0].push_back(nodes + head);
			values.insert(value);
		}
		else										// or this node is removed
			nodes_valid[1].push_back(nodes + head);
		head = nodes[head].next;
	}
	for (int i = 0; i < 2; i++) {
		if (!nodes_valid[i].empty()) {
			printf("%05d %d ", nodes_valid[i].front() - nodes, nodes_valid[i].front()->value);
			for (int j = 1; j < nodes_valid[i].size(); j++)
				printf("%05d\n%05d %d ", nodes_valid[i][j] - nodes, nodes_valid[i][j] - nodes, nodes_valid[i][j]->value);
			printf("-1\n");
		}
	}

	return 0;
}