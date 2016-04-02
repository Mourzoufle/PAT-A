#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NODE = 100000;

struct Node {
	int value;
	int next;

	Node(): next(-1) {};
};

int main() {
	Node *nodes = new Node[MAX_NODE];
	int head, num_node, length;																				// head of the list; number of nodes; length of the sublist to be reversed
	scanf("%d %d %d", &head, &num_node, &length);
	for (int i = 0; i < num_node; i++) {
		int cur_node;																						// address of the current node
		scanf("%d", &cur_node);
		scanf("%d %d", &nodes[cur_node].value, &nodes[cur_node].next);
	}
	vector<Node *> nodes_valid;																				// the nodes that belong to the list beginning with head
	while (head >= 0) {
		nodes_valid.push_back(nodes + head);																// the address of the head
		head = nodes[head].next;
	}
	for (int i = 0; i + length <= nodes_valid.size(); i += length)
		reverse(&nodes_valid[i], &nodes_valid[i + length]);
	printf("%05d %d ", nodes_valid.front() - nodes, nodes_valid.front()->value);
	for (int i = 1; i < nodes_valid.size(); i++)
		printf("%05d\n%05d %d ", nodes_valid[i] - nodes, nodes_valid[i] - nodes, nodes_valid[i]->value);	// the address of each node needs to be printed twice; the address is restored by computing the difference between the node and the address of the array
	printf("-1");

	return 0;
}