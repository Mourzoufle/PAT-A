#include <cstdio>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

const int MAX_CITY = 26 * 26 * 26;

/* map each string of name to an integer */
int str_to_num(const char *str) { return (str[0] - 'A') * 676 + (str[1] - 'A') * 26 + str[2] - 'A'; }

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
	int num_city, num_route;
	char src[4];
	scanf("%d %d %s", &num_city, &num_route, src);
	int *happinesses = new int[num_city];										// happiness of each city
	int **routes = new int*[num_city];
	for (int i = 0; i < num_city; i++) {
		routes[i] = new int[num_city];
		for (int j = 0; j < num_city; j++)
			routes[i][j] = INT_MAX;												// initial - all nodes are separated
		routes[i][i] = 0;														// all nodes are self-connected
	}
	char **cities = new char *[num_city];
	for (int i = 0; i < num_city; i++)
		cities[i] = new char[4];
	strcpy(cities[0], src);
	int *indices = new int[MAX_CITY];											// index of each city on the map
	indices[str_to_num(src)] = 0;
	for (int i = 1; i < num_city; i++) {
		scanf("%s %d", cities[i], &happinesses[i]);
		indices[str_to_num(cities[i])] = i;
	}
	for (int i = 0; i < num_route; i++) {
		char a[4], b[4];
		int cost;
		scanf("%s %s %d", a, b, &cost);
		int idx_a = indices[str_to_num(a)], idx_b = indices[str_to_num(b)];
		routes[idx_a][idx_b] = cost;
		routes[idx_b][idx_a] = cost;
	}

	int *costs = dijstra(routes, num_city, indices[str_to_num("ROM")]);
	vector<vector<int>*> paths;
	get_paths(routes, costs, num_city, 0, paths, NULL);
	int max_happiness = INT_MIN, idx_path;
	for (int i = 0; i < paths.size(); i++) {
		int cur_happiness = 0;
		for (int j = 1; j < paths[i]->size(); j++)
			cur_happiness += happinesses[(*paths[i])[j]];
		if ((cur_happiness > max_happiness) || ((cur_happiness == max_happiness) && (paths[i]->size() < paths[idx_path]->size()))) {
			idx_path = i;
			max_happiness = cur_happiness;
		}
	}
	printf("%d %d %d %d\n%s", paths.size(), costs[0], max_happiness, max_happiness / (paths[idx_path]->size() - 1), cities[0]);
	for (int i = 1; i < paths[idx_path]->size(); i++)
		printf("->%s", cities[(*paths[idx_path])[i]]);

	return 0;
}