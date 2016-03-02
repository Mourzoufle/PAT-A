#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int num_path = 0;

/* Dijstra - find the shortest distances of every node to the destination */
int* dijstra(int **roads, int num_node, int dst) {
	int *distances = new int[num_node];
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++) {
		distances[i] = roads[i][dst];										// initial distance of each node - the direct connection to the destination
		visit[i] = false;													// every node is unvisited
	}
	visit[dst] = true;														// ...except for the destination

	for (int i = 1; i < num_node; i++) {									// the destination is already visited
		int cur_node = -1;													// current node that is unvisited & has the shortest distance
		for (int j = 0; j < num_node; j++)
			if (!visit[j] && ((cur_node < 0) || (distances[j] < distances[cur_node])))
				cur_node = j;
		if (distances[cur_node] == INT_MAX)									// all unvisited nodes are not connected to the destination - exit
			break;
		visit[cur_node] = true;
		for (int j = 0; j < num_node; j++)
			if (roads[j][cur_node] < distances[j] - distances[cur_node])	// this node has a shorter distance via the current node
				distances[j] = roads[j][cur_node] + distances[cur_node];
	}

	delete[] visit;
	return distances;
}

/* DFS - find the shortest paths */
void get_paths(int **roads, int *distances, int num_node, int src, vector<vector<int>*> &paths, vector<int> *path) {
	if (path == NULL)
		path = new vector<int>;
	path->push_back(src);
	if (distances[src] == 0) {												// got the destination already
		paths.push_back(path);
		return;
	}
	for (int i = 0; i < num_node; i++) {
		if (i == src)														// get rid of dead loop
			continue;
		if (roads[src][i] == distances[src] - distances[i]) {				// find the next node along the path
			vector<int> *cur_path = new vector<int>(*path);
			get_paths(roads, distances, num_node, i, paths, cur_path);
		}
	}
	delete path;
}

int main() {
	int num_city, num_road, src, dst;
	scanf("%d %d %d %d", &num_city, &num_road, &src, &dst);
	int **roads = new int *[num_city];
	for (int i = 0; i < num_city; i++) {
		roads[i] = new int[num_city];
		for (int j = 0; j < num_city; j++)
			roads[i][j] = INT_MAX;											// initial - all nodes are seperated
		roads[i][i] = 0;													// all nodes are self-connected
	}
	int *teams = new int[num_city];
	for (int i = 0; i < num_city; i++)
		scanf("%d", &teams[i]);
	for (int i = 0; i < num_road; i++) {
		int a, b, length;
		scanf("%d %d %d", &a, &b, &length);
		roads[a][b] = length;
		roads[b][a] = length;
	}

	int *distances = dijstra(roads, num_city, dst);
	vector<vector<int>*> paths;
	get_paths(roads, distances, num_city, src, paths, NULL);
	int max_team = 0;
	for (int i = 0; i < paths.size(); i++) {								// compute the number of teams gathered by each path
		int cur_team = 0;
		for (int j = 0; j < paths[i]->size(); j++)
			cur_team += teams[(*paths[i])[j]];
		if (cur_team > max_team)
			max_team = cur_team;
	}
	printf("%d %d", paths.size(), max_team);

	return 0;
}
