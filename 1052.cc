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

/* compare fuction for sorting nodes - according to the value of each node */
bool cmp(const Node* a, const Node* b) { return a->value < b->value; }

int main() {
	Node *nodes = new Node[MAX_NODE];
	int num_node, head;
	scanf("%d %d", &num_node, &head);
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
	sort(nodes_valid.begin(), nodes_valid.end(), cmp);
	printf("%d ", nodes_valid.size());
	for (int i = 0; i < nodes_valid.size(); i++)
		printf("%05d\n%05d %d ", nodes_valid[i] - nodes, nodes_valid[i] - nodes, nodes_valid[i]->value);	// the address of each node needs to be printed twice; the address is restored by computing the difference between the node and the address of the array
	printf("-1");
	
	return 0;
}