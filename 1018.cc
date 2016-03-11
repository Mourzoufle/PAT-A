#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

/* Dijstra - find the shortest distances of every node to the destination */
int* dijstra(int **roads, int num_node, int dst) {
	int *distances = new int[num_node];
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++) {
		distances[i] = roads[i][dst];											// initial distance of each node - the direct connection to the destination
		visit[i] = false;														// every node is unvisited
	}
	visit[dst] = true;															// ...except for the destination

	for (int i = 1; i < num_node; i++) {										// the destination is already visited
		int cur_node = -1;														// current node that is unvisited & has the shortest distance
		for (int j = 0; j < num_node; j++)
			if (!visit[j] && ((cur_node < 0) || (distances[j] < distances[cur_node])))
				cur_node = j;
		if (distances[cur_node] == INT_MAX)										// all unvisited nodes are not connected to the destination - exit
			break;
		visit[cur_node] = true;
		for (int j = 0; j < num_node; j++)
			if (roads[j][cur_node] < distances[j] - distances[cur_node])		// this node has a shorter distance via the current node
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
	if (distances[src] == 0) {													// got the destination already
		paths.push_back(path);
		return;
	}
	for (int i = 0; i < num_node; i++) {
		if ((i != src) && (roads[src][i] == distances[src] - distances[i])) {	// find the next node along the path
			vector<int> *cur_path = new vector<int>(*path);
			get_paths(roads, distances, num_node, i, paths, cur_path);
		}
	}
	delete path;
}

int main() {
	int capacity, num_station, dst, num_road;
	scanf("%d %d %d %d", &capacity, &num_station, &dst, &num_road);
	int **roads = new int *[++num_station];
	for (int i = 0; i < num_station; i++) {
		roads[i] = new int[num_station];
		for (int j = 0; j < num_station; j++)
			roads[i][j] = INT_MAX;												// initial - all nodes are separated
		roads[i][i] = 0;														// all nodes are self-connected
	}
	int *bikes = new int[num_station];
	capacity /= 2;																// the ideal number of bikes - half of the capacity
	for (int i = 1; i < num_station; i++) {
		scanf("%d", &bikes[i]);
		bikes[i] -= capacity;													// convert numbers of bikes to differs
	}
	for (int i = 0; i < num_road; i++) {
		int a, b, length;
		scanf("%d %d %d", &a, &b, &length);
		roads[a][b] = length;
		roads[b][a] = length;
	}

	int *distances = dijstra(roads, num_station, dst);
	vector<vector<int> *> paths;
	get_paths(roads, distances, num_station, 0, paths, NULL);
	int min_send = INT_MAX, min_recv = INT_MAX, idx_path;						// least bikes to be sent; (if it is not unique) least bikes to be returned; the selected index of path
	for (int i = 0; i < paths.size(); i++) {
		int cur_send = 0, cur_recv = 0;
		for (int j = 1; j < paths[i]->size(); j++) {
			cur_recv += bikes[(*paths[i])[j]];
			if (cur_recv < 0) {													// this station needs bikes from PBMC
				cur_send -= cur_recv;
				cur_recv = 0;													// ...and no bikes needed to be returned
			}
		}
		if ((cur_send < min_send) || ((cur_send == min_send) && (cur_recv < min_recv))) {
			min_send = cur_send;
			min_recv = cur_recv;
			idx_path = i;
		}
	}
	printf("%d 0", min_send);
	for (int i = 1; i < paths[idx_path]->size(); i++)
		printf("->%d", (*paths[idx_path])[i]);
	printf(" %d", min_recv);

	return 0;
}