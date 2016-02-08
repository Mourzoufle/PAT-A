#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int num_node, num_nonleaf;
	cin >> num_node >> num_nonleaf;

	vector<int> *nodes = new vector<int>[num_node + 1];
	for (int i = 0; i < num_nonleaf; i++) {
		int id, num_child;
		cin >> id >> num_child;
		for (int j = 0; j < num_child; j++) {
			int c_id;
			cin >> c_id;
			nodes[id].push_back(c_id);
		}
	}
	queue<int> level;
	level.push(1);
	while (true) {
		int size_level = level.size();
		int num_leaf = 0;
		for (int i = 0; i < size_level; i++) {
			int id = level.front();
			level.pop();
			if (nodes[id].size() == 0)
				num_leaf++;
			else
				for (int j = 0; j < nodes[id].size(); j++)
					level.push(nodes[id][j]);
		}
		cout << num_leaf;
		if (level.size() > 0)
			cout << " ";
		else
			break;
	}

	return 0;
}