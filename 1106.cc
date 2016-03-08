#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int num_node;
	double price, inc;
	scanf("%d %lf %lf", &num_node, &price, &inc);
	inc = 1 + inc / 100;
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

	queue<int> queue;
	queue.push(0);
	while (true) {
		int cur_size = queue.size();
		int num_leaf = 0;
		for (int i = 0; i < cur_size; i++) {
			int node = queue.front();
			if (nodes[node].empty())
				num_leaf++;
			for (int j = 0; j < nodes[node].size(); j++)
				queue.push(nodes[node][j]);
			queue.pop();
		}
		if (num_leaf > 0) {
			printf("%.4lf %d", price, num_leaf);
			break;
		}
		else
			price *= inc; 
	}

	return 0;
}
