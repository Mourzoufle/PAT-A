#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int num_node, num_line;
	cin >> num_node >> num_line;
	vector<int> *nodes = new vector<int>[num_node];
	for (int i = 0; i < num_line; i++) {
		int node, num_child;
		cin >> node >> num_child;
		node--;
		for (int j = 0; j < num_child; j++) {
			int child;
			cin >> child;
			nodes[node].push_back(--child);
		}
	}

	int max_size = 1, max_level = 1, level = 0;
	queue<int> queue;
	queue.push(0);
	while (!queue.empty()) {
		int size = queue.size();
		level++;
		if (size > max_size) {
			max_size = size;
			max_level = level;
		}
		for (int i = 0; i < size; i++) {
			int cur = queue.front();
			queue.pop();
			for (int j = 0; j < nodes[cur].size(); j++)
				queue.push(nodes[cur][j]);
		}
	}
	cout << max_size << " " << max_level;

	return 0;
}