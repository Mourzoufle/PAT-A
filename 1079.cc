#include <cstdio>
#include <vector>

using namespace std;

struct Node {
	vector<int> children;
	double amount;
};

/* DFS - get the total amount of the sales */
double get_amount(Node *nodes, int root, double base_price, double mul) {
	if (nodes[root].children.empty())	// this node is a retailer
		return nodes[root].amount * base_price;
	double sum = 0;
	for (int i = 0; i < nodes[root].children.size(); i++)
		sum += get_amount(nodes, nodes[root].children[i], base_price * mul, mul);
	return sum;
}

int main() {
	int num_node;
	double base_price, ratio;			// base price; percentage rate of price increment for each distributor or retailer
	scanf("%d %lf %lf", &num_node, &base_price, &ratio);
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++) {
		int num_child;
		scanf("%d", &num_child);
		if (num_child > 0) {			// this node is a supplier or distributor
			for (int j = 0; j < num_child; j++) {
				int child;
				scanf("%d", &child);
				nodes[i].children.push_back(child);
			}
		}
		else							// this node is a retailer
			scanf("%lf", &nodes[i].amount);
	}
	printf("%.1lf", get_amount(nodes, 0, base_price, 1 + ratio / 100));

	return 0;
}