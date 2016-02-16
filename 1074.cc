#include <cstdio>
#include <vector>

using namespace std;

struct Node {
	int data;
	int next;
};

int main() {
	Node *nodes = new Node[100000];
	int head, num_node, length;
	scanf("%d %d %d", &head, &num_node, &length);
	for (int i = 0; i < num_node; i++) {
		int addr, data, next;
		scanf("%d %d %d", &addr, &data, &next);
		nodes[addr].data = data;
		nodes[addr].next = next;
	}
	vector<int> vector;	
	for (int i = head; i >= 0; i = nodes[i].next)
		vector.push_back(i);
	for (int i = 0; i + length <= vector.size(); i += length) {
		for (int j = 0; j < (length >> 1); j++) {
			int idx_a = i + j, idx_b = i + length - j - 1;
			vector[idx_a] ^= vector[idx_b];
			vector[idx_b] ^= vector[idx_a];
			vector[idx_a] ^= vector[idx_b];
		}
	}

	printf("%05d %d ", vector[0], nodes[vector[0]].data);
	for (int i = 1; i < vector.size(); i++)
		printf("%05d\n%05d %d ", vector[i], vector[i], nodes[vector[i]].data);
	printf("-1");

	return 0;
}