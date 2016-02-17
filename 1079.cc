#include <cstdio>
#include <list>

using namespace std;

struct Node {
	list<int> children;
	double amount;
};

double DFS(Node *nodes, Node *root, double price, double mul) {
	if (root->children.empty())
		return root->amount * price;
	double sum = 0;
	for (list<int>::iterator iter = root->children.begin(); iter != root->children.end(); iter++)
		sum += DFS(nodes, nodes + *iter, price * mul, mul);
	return sum;
}

int main() {
	int num_node;
	double price, percent;
	scanf("%d %lf %lf", &num_node, &price, &percent);
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++) {
		int num_child;
		scanf("%d", &num_child);
		if (num_child > 0) {
			for (int j = 0; j < num_child; j++) {
				int child;
				scanf("%d", &child);
				nodes[i].children.push_back(child);
			}
		}
		else
			scanf("%lf", &nodes[i].amount);
	}
	printf("%.1f", DFS(nodes, nodes, price, 1 + percent / 100));

	return 0;
}