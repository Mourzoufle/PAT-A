#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int value;
	vector<Node *> childs;
};

bool compare(const vector<int> &a, const vector<int> &b) {
	for (int i = 0; (i < a.size()) && (i < b.size()); i++)
		if (a[i] != b[i])
			return a[i] > b[i];
	return a.size() > b.size();
}

void find(Node *root, int total, vector<int> prefix, vector<vector<int> > &paths) {
	total -= root->value;
	if (total < 0)
		return;
	prefix.push_back(root->value);
	if (root->childs.empty() && (total == 0))
		paths.push_back(prefix);
	else
		for (int i = 0; i < root->childs.size(); i++)
			find(root->childs[i], total, prefix, paths);
}

int main() {
	int num_node, num_nonleaf, total;
	cin >> num_node >> num_nonleaf >> total;
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++)
		cin >> nodes[i].value;
	for (int i = 0; i < num_nonleaf; i++) {
		int node, num_child;
		cin >> node >> num_child;
		for (int j = 0; j < num_child; j++) {
			int child;
			cin >> child;
			nodes[node].childs.push_back(nodes + child);
		}
	}
	vector<int> prefix;
	vector<vector<int> > paths;
	find(nodes, total, prefix, paths);
	sort(paths.begin(), paths.end(), compare);
	for (int i = 0; i < paths.size(); i++) {
		cout << paths[i][0];
		for (int j = 1; j < paths[i].size(); j++)
			cout << " " << paths[i][j];
		cout << endl;
	}

	return 0;
}