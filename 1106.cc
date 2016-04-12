#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int num_node;
	double base_price, ratio;	// base price; percentage rate of price increment for each distributor or retailer
	scanf("%d %lf %lf", &num_node, &base_price, &ratio);
	vector<int> *nodes = new vector<int>[num_node];
	for (int i = 0; i < num_node; i++) {
		int num_child;
		scanf("%d", &num_child);
		for (int j = 0; j < num_child; j++) {
			int child;
			scanf("%d", &child);
			nodes[i].push_back(child);
		}
	}

	queue<int> queue;			// level order traversal - find the first level that contains retailers
	queue.push(0);
	int num_leaf = 0;
	while (num_leaf == 0) {		// have not found any leaf nodes
		int cur_size = queue.size();
		for (int i = 0; i < cur_size; i++) {
			int node = queue.front();
			if (nodes[node].empty())
				num_leaf++;
			for (int j = 0; j < nodes[node].size(); j++)
				queue.push(nodes[node][j]);
			queue.pop();
		}
		if (num_leaf == 0)
			base_price *= 1 + ratio / 100;
	}
	printf("%.4lf %d", base_price, num_leaf);

	return 0;
}