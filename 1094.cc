#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int num_node, num_nonleaf;
	scanf("%d %d", &num_node, &num_nonleaf);
	vector<int> *nodes = new vector<int>[num_node];	// children of each node
	for (int i = 0; i < num_nonleaf; i++) {
		int node, num_child;
		scanf("%d %d", &node, &num_child);
		for (int j = 0; j < num_child; j++) {
			int child;
			scanf("%d", &child);
			nodes[node - 1].push_back(child - 1);
		}
	}

	int max_size = 1, level = 1;					// the largest population number; level of the corresponding generation
	queue<int> queue;								// level order traversal
	queue.push(0);
	for (int i = 1; !queue.empty(); i++) {
		int cur_size = queue.size();
		if (cur_size > max_size) {					// larger generation found
			max_size = cur_size;
			level = i;
		}
		for (int i = 0; i < cur_size; i++) {
			int node = queue.front();
			for (int j = 0; j < nodes[node].size(); j++)
				queue.push(nodes[node][j]);
			queue.pop();
		}
	}
	printf("%d %d", max_size, level);

	return 0;
}