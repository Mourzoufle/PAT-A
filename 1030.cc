#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

int* dijstra(int **roads, int num_node, int dst) {
	int *distances = new int[num_node];
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++) {
		distances[i] = roads[i][dst];
		visit[i] = false;
	}
	visit[dst] = true;
	for (int i = 1; i < num_node; i++) {
		int idx = -1;
		for (int j = 0; j < num_node; j++) {
			if (visit[j])
				continue;
			if ((idx < 0) || (distances[j] < distances[idx]))
				idx = j;
		}
		if (distances[idx] == INT_MAX)
			break;
		visit[idx] = true;
		for (int j = 0; j < num_node; j++)
			if (distances[idx] < distances[j] - roads[j][idx])
				distances[j] = distances[idx] + roads[j][idx];
	}
	delete[] visit;

	return distances;
}

void find_path(int **roads, int *distances, int num_node, int src, vector<vector<int>*> &paths, vector<int> *path) {
	if (path == NULL)
		path = new vector<int>;
	path->push_back(src);
	if (distances[src] == 0) {
		paths.push_back(path);
		return;
	}
	for (int i = 0; i < num_node; i++) {
		if ((i != src) && (roads[src][i] == distances[src] - distances[i])) {
			vector<int> *cur_path = new vector<int>(*path);
			find_path(roads, distances, num_node, i, paths, cur_path);
		}
	}
	delete path;
}

int main() {
	int num_node, num_road, src, dst;
	scanf("%d %d %d %d", &num_node, &num_road, &src, &dst);
	int **roads = new int*[num_node];
	int **costs = new int*[num_node];
	for (int i = 0; i < num_node; i++) {
		roads[i] = new int[num_node];
		costs[i] = new int[num_node];
		for (int j = 0; j < num_node; j++)
			roads[i][j] = INT_MAX;
		roads[i][i] = 0;
	}
	for (int i = 0; i < num_road; i++) {
		int head, tail, distance, cost;
		scanf("%d %d %d %d", &head, &tail, &distance, &cost);
		roads[head][tail] = distance;
		roads[tail][head] = distance;
		costs[head][tail] = cost;
		costs[tail][head] = cost;
	}

	int *distances = dijstra(roads, num_node, dst);
	vector<vector<int> *> paths;
	find_path(roads, distances, num_node, src, paths, NULL);
	int idx, cost = INT_MAX;
	for (int i = 0; i < paths.size(); i++) {
		int cur_cost = 0;
		for (int j = 1; j < paths[i]->size(); j++)
			cur_cost += costs[(*(paths[i]))[j - 1]][(*(paths[i]))[j]];
		if (cur_cost < cost) {
			cost = cur_cost;
			idx = i;
		}
	}

	for (int i = 0; i < paths[idx]->size(); i++)
		printf("%d ", (*(paths[idx]))[i]);
	printf("%d %d", distances[src], cost);

	return 0;
}