#include <iostream>
#include <climits>

using namespace std;

int num_path = 0;

int* Dijstra(int N, int **map, int dst) {
	int *distances = new int[N];
	for (int i = 0; i < N; i++)
		distances[i] = map[i][dst];
	bool *is_visited = new bool[N];
	for (int i = 0; i < N; i++)
		is_visited[i] = false;
	is_visited[dst] = true;

	while (true) {
		int cur = -1;
		for (int i = 0; i < N; i++)
			if (!is_visited[i] && ((cur < 0) || (distances[i] < distances[cur])))
				cur = i;
		if ((cur < 0) || (distances[cur] == INT_MAX))
			break;
		is_visited[cur] = true;
		for (int i = 0; i < N; i++)
			if (map[i][cur] < distances[i] - distances[cur])
				distances[i] = map[i][cur] + distances[cur];
	}

	delete[] is_visited;
	return distances;
}

int find(int N, int **map, int *distances, int *teams, int src, int dst, int num_team) {
	num_team += teams[src];
	if (src == dst) {
		num_path++;
		return num_team;
	}
	else {
		int max_team = 0;
		for (int i = 0; i < N; i++) {
			if ((i != src) && (distances[i] == distances[src] - map[src][i])) {
				int cur_team = find(N, map, distances, teams, i, dst, num_team);
				if (max_team < cur_team)
					max_team = cur_team;
			}
		}
		return max_team;
	}
}

int main() {
	int num_city, num_road, src, dst;
	cin >> num_city >> num_road >> src >> dst;
	int *teams = new int[num_city];
	for (int i = 0; i < num_city; i++)
		cin >> teams[i];
	int **roads = new int *[num_city];
	for (int i = 0; i < num_city; i++) {
		roads[i] = new int[num_city];
		for (int j = 0; j < num_city; j++)
			roads[i][j] = INT_MAX;
		roads[i][i] = 0;
	}
	for (int i = 0; i < num_road; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		roads[a][b] = len;
		roads[b][a] = len;
	}
	int *distances = Dijstra(num_city, roads, dst);
	int num_team = find(num_city, roads, distances, teams, src, dst, 0);
	cout << num_path << " " << num_team;

	return 0;
}