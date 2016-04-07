#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int num_node;
	double base_price, ratio;						// base price; percentage rate of price increment for each distributor or retailer
	scanf("%d %lf %lf", &num_node, &base_price, &ratio);
	vector<int> *nodes = new vector<int>[num_node];	// children of each node
	queue<int> queue;								// BFS - level order traversal of the whole supply chain
	for (int i = 0; i < num_node; i++) {
		int parent;
		scanf("%d", &parent);
		if (parent < 0)								// the root
			queue.push(i);
		else
			nodes[parent].push_back(i);
	}

	double price = base_price;						// the highest price; 
	int num_sell;									// number of retailers that sell at the highest price
	while (!queue.empty()) {
		num_sell = queue.size();
		for (int i = 0; i < num_sell; i++) {
			int node = queue.front();
			for (int j = 0; j < nodes[node].size(); j++)
				queue.push(nodes[node][j]);
			queue.pop();
		}
		if (!queue.empty())
			price *= 1 + ratio / 100;
	}
	printf("%.2lf %d", price, num_sell);

	return 0;
}