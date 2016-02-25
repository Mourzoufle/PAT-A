#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int *Dijstra(int **roads, int num_node, int dst) {
	int *distances = new int[num_node];
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++) {
		distances[i] = roads[i][dst];
		visit[i] = false;
	}
	visit[dst] = true;
	for (int i = 1; i < num_node; i++) {
		int cur_node = -1;
		for (int j = 0; j < num_node; j++) {
			if (visit[j])
				continue;
			if ((cur_node < 0) || (distances[j] < distances[cur_node]))
				cur_node = j;
		}
		if (distances[cur_node] == INT_MAX)
			break;
		visit[cur_node] = true;
		for (int j = 0; j < num_node; j++)
			if (distances[cur_node] < distances[j] - roads[j][cur_node])
				distances[j] = roads[j][cur_node] + distances[cur_node];
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
		if (i == src)
			continue;
		if (distances[src] - distances[i] == roads[src][i]) {
			vector<int> *cur_path = new vector<int>(*path);
			find_path(roads, distances, num_node, i, paths, cur_path);
		}
	}
}

int main() {
	int capacity, num_node, dst, num_road;
	scanf("%d %d %d %d", &capacity, &num_node, &dst, &num_road);
	int **roads = new int*[++num_node];
	for (int i = 0; i < num_node; i++) {
		roads[i] = new int[num_node];
		for (int j = 0; j < num_node; j++)
			roads[i][j] = INT_MAX;
		roads[i][i] = 0;
	}
	int *bikes = new int[num_node];
	capacity >>= 1;
	for (int i = 1; i < num_node; i++)
		scanf("%d", &bikes[i]);
	for (int i = 0; i < num_road; i++) {
		int head, tail, distance;
		scanf("%d %d %d", &head, &tail, &distance);
		roads[head][tail] = distance;
		roads[tail][head] = distance;
	}

	int *distances = Dijstra(roads, num_node, dst);
	vector<vector<int> *> paths;
	find_path(roads, distances, num_node, 0, paths, NULL);
	int send = INT_MAX, recv = INT_MAX, idx;
	for (int i = 0; i < paths.size(); i++) {
		int cur_send = 0, cur_recv = 0;
		for (int j = 1; j < paths[i]->size(); j++) {
			cur_recv += bikes[(*paths[i])[j]] - capacity;
			if (cur_recv < 0) {
				cur_send -= cur_recv;
				cur_recv = 0;
			}
		}
		if ((cur_send < send) || ((cur_send == send) && (cur_recv < recv))) {
			send = cur_send;
			recv = cur_recv;
			idx = i;
		}
	}
	printf("%d 0", send);
	for (int i = 1; i < paths[idx]->size(); i++)
		printf("->%d", (*paths[idx])[i]);
	printf(" %d", recv);

	return 0;
}