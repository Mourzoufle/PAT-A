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

/* check if vector a and b are equal */
bool equal(vector<int> *a, vector<int> *b) {
	if (a->size() != b->size())
		return false;
	for (int i = 0; i < a->size(); i++)
		if ((*a)[i] != (*b)[i])
			return false;
	return true;
}

int main() {
	int num_node, num_road, src, dst;
	scanf("%d %d", &num_node, &num_road);
	int **lengths = new int *[num_node];
	int **times = new int *[num_node];
	for (int i = 0; i < num_node; i++) {
		lengths[i] = new int[num_node];
		times[i] = new int[num_node];
		for (int j = 0; j  < num_node; j++) {
			lengths[i][j] = INT_MAX;
			times[i][j] = INT_MAX;
		}
		lengths[i][i] = 0;
		times[i][i] = 0;
	}
	for (int i = 0; i < num_road; i++) {
		int a, b, is_directed, length, time;
		scanf("%d %d %d %d %d", &a, &b, &is_directed, &length, &time);
		lengths[a][b] = length;
		times[a][b] = time;
		if (is_directed == 0) {													// not an one-way road
			lengths[b][a] = length;
			times[b][a] = time;
		}
	}
	scanf("%d %d", &src, &dst);

	int *distances_length = dijstra(lengths, num_node, dst), *distances_time = dijstra(times, num_node, dst);
	vector<vector<int> *> paths_length, paths_time;
	get_paths(lengths, distances_length, num_node, src, paths_length, NULL);
	get_paths(times, distances_time, num_node, src, paths_time, NULL);
	int idx_length, idx_time, min_time = INT_MAX, min_size = INT_MAX;
	for (int i = 0; i < paths_length.size(); i++) {
		int cur_time = 0;
		for (int j = 1; j < paths_length[i]->size(); j++)
			cur_time += times[(*paths_length[i])[j - 1]][(*paths_length[i])[j]];
		if (cur_time < min_time) {
			min_time = cur_time;
			idx_length = i;
		}
	}
	for (int i = 0; i < paths_time.size(); i++) {
		if (paths_time[i]->size() < min_size) {
			min_size = paths_time[i]->size();
			idx_time = i;
		}
	}
	if (equal(paths_length[idx_length], paths_time[idx_time])) {				// only one path that is the shortest and the fastest
		printf("Distance = %d; Time = %d: %d", distances_length[src], distances_time[src], src);
		for (int j = 1; j < paths_length[idx_length]->size(); j++)
			printf(" -> %d", (*paths_length[idx_length])[j]);
	}
	else {
		printf("Distance = %d: %d", distances_length[src], src);
		for (int j = 1; j < paths_length[idx_length]->size(); j++)
			printf(" -> %d", (*paths_length[idx_length])[j]);
		printf("\nTime = %d: %d", distances_time[src], src);
		for (int j = 1; j < paths_time[idx_time]->size(); j++)
			printf(" -> %d", (*paths_time[idx_time])[j]);
	}

	return 0;
}