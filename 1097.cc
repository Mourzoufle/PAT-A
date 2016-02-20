#include <cstdio>
#include <vector>
#include <set>

using namespace std;

struct Node {
	int addr;
	int key;
	int next;
};

int main() {
	Node *nodes = new Node[100000];
	int head, num_node;
	scanf("%d %d", &head, &num_node);
	for (int i = 0; i < num_node; i++) {
		int addr;
		scanf("%d", &addr);
		scanf("%d %d", &nodes[addr].key, &nodes[addr].next);
		nodes[addr].addr = addr;
	}
	vector<Node *> res_nodes, del_nodes;
	set<int> keys;
	for (int i = head; i >= 0; i = nodes[i].next) {
		int key = nodes[i].key;
		if (key < 0)
			key = -key;
		if (keys.find(key) == keys.end()) {
			res_nodes.push_back(nodes + i);
			keys.insert(key);
		}
		else
			del_nodes.push_back(nodes + i);
	}

	if (!res_nodes.empty()) {
		printf("%05d %d ", res_nodes[0]->addr, res_nodes[0]->key);
		for (int i = 1; i < res_nodes.size(); i++)
			printf("%05d\n%05d %d ", res_nodes[i]->addr, res_nodes[i]->addr, res_nodes[i]->key);
		printf("-1\n");
	}
	if (!del_nodes.empty()) {
		printf("%05d %d ", del_nodes[0]->addr, del_nodes[0]->key);
		for (int i = 1; i < del_nodes.size(); i++)
			printf("%05d\n%05d %d ", del_nodes[i]->addr, del_nodes[i]->addr, del_nodes[i]->key);
		printf("-1\n");
	}

	return 0;
}