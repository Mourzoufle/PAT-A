#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int weight;
	vector<int> children;
};

/* compare fuction for sorting paths - first check if there is a position that the weight of the two corresponding nodes are not same; then according to the lengths */
bool cmp(vector<int> *a, vector<int> *b) {
	for (int i = 0; (i < a->size()) && (i < b->size()); i++)
		if ((*a)[i] != (*b)[i])
			return (*a)[i] > (*b)[i];
	return a->size() > b->size();
}

/* DFS - find paths with the total weight equals to the given weight */
void get_paths(Node *nodes, int weight, int root, vector<int> *path, vector<vector<int> *> &paths) {
	if (path == NULL)
		path = new vector<int>;
	path->push_back(nodes[root].weight);
	weight -= nodes[root].weight;
	if ((weight == 0) && nodes[root].children.empty())	// a path found
		paths.push_back(path);								
	else {
		if (weight > 0) {								// or search for possible paths from this node
			for (int i = 0; i < nodes[root].children.size(); i++) {
				vector<int> *cur_path = new vector<int>(*path);
				get_paths(nodes, weight, nodes[root].children[i], cur_path, paths);
			}
		}													
		delete path;
	}
}

int main() {
	int num_node, num_nonleaf, weight;
	scanf("%d %d %d", &num_node, &num_nonleaf, &weight);
	Node *nodes = new Node[num_node];
	for (int i = 0; i < num_node; i++)
		scanf("%d", &nodes[i].weight);
	for (int i = 0; i < num_nonleaf; i++) {
		int node, num_child;
		scanf("%d %d", &node, &num_child);
		for (int j = 0; j < num_child; j++) {
			int child;
			scanf("%d", &child);
			nodes[node].children.push_back(child);
		}
	}

	vector<vector<int> *> paths;
	get_paths(nodes, weight, 0, NULL, paths);
	sort(paths.begin(), paths.end(), cmp);
	for (int i = 0; i < paths.size(); i++) {
		printf("%d", paths[i]->front());
		for (int j = 1; j < paths[i]->size(); j++)
			printf(" %d", (*paths[i])[j]);
		printf("\n");
	}

	return 0;
}