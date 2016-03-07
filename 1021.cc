#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

/* Union-Find Sets - merge the sets that a and b belong to */
void merge(int *roots, int a, int b) {
	int root = a;
	while (roots[root] != root)									// find the root of a as the new root of two sets
		root = roots[root];
	while (roots[a] != root) {									// path compression of a and b
		int tmp = roots[a];
		roots[a] = root;
		a = tmp;
	}
	while (roots[b] != root) {
		int tmp = roots[b];
		roots[b] = root;
		b = tmp;
	}
}

/* BFS - find the deepest roots from src, and add them to the ones that are already found */
void get_roots(int **roads, int num_node, int src, set<int> &roots) {
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++)							// every node is unvisited
		visit[i] = false;
	set<int> cur_roots;											// deepest roots found at this time
	queue<int> queue;											// use BFS
	queue.push(src);
	while (!queue.empty()) {
		cur_roots.clear();										// nodes with larger length exist, clear the current result
		int cur_size = queue.size();
		for (int i = 0; i < cur_size; i++) {
			int node = queue.front();
			visit[node] = true;
			cur_roots.insert(node);
			for (int j = 0; j < num_node - 1; j++) {			// nodes connected to the current node and unvisited are counted as deeper nodes
				if ((roads[j][0] == node) && !visit[roads[j][1]])
					queue.push(roads[j][1]);
				else if ((roads[j][1] == node) && !visit[roads[j][0]])
					queue.push(roads[j][0]);
			}
			queue.pop();
		}
	}
	roots.insert(cur_roots.begin(), cur_roots.end());
	delete[] visit;
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	int *roots = new int[num_node];								// the root node of each node
	for (int i = 0; i < num_node; i++)
		roots[i] = i;											// all nodes are separated sets
	int **roads = new int *[num_node - 1];						
	for (int i = 0; i < num_node - 1; i++) {
		roads[i] = new int[2];
		scanf("%d %d", &roads[i][0], &roads[i][1]);
		merge(roots, --roads[i][0], --roads[i][1]);
	}

	int num_component = 0;
	for (int i = 0; i < num_node; i++)
		if (roots[i] == i)										// number of roots indicates number of components
			num_component++;
	if (num_component > 1) {									// not a connected graph
		printf("Error: %d components", num_component);
		return 0;
	}

	set<int> deepest_roots;
	get_roots(roads, num_node, 0, deepest_roots);				// NOTE: the deepest roots needed to be completely found after searching twice
	get_roots(roads, num_node, *(deepest_roots.begin()), deepest_roots);
	for (set<int>::iterator iter = deepest_roots.begin(); iter != deepest_roots.end(); iter++)
		printf("%d\n", (*iter) + 1);

	return 0;
}