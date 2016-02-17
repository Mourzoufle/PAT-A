#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int *Dijstra(int **routes, int num_node, int dst) {
	int *costs = new int[num_node];
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++) {
		costs[i] = routes[i][dst];
		visit[i] = false;
	}
	visit[dst] = true;
	for (int i = 1; i < num_node; i++) {
		int idx = -1;
		for (int j = 0; j < num_node; j++)
			if (!visit[j] && ((idx < 0) || (costs[idx] > costs[j])))
				idx = j;
		if (costs[idx] == INT_MAX)
			break;
		visit[idx] = true;
		for (int j = 0; j < num_node; j++)
			if (costs[idx] < costs[j] - routes[j][idx])
				costs[j] = costs[idx] + routes[j][idx];
	}
	delete[] visit;

	return costs;
}

void find_path(int **routes, int *costs, int num_node, int src, vector<vector<int> *> &paths, vector<int> *path) {
	if (path == NULL)
		path = new vector<int>;
	path->push_back(src);
	if (costs[src] == 0) {
		paths.push_back(path);
		return;
	}
	for (int i = 0; i < num_node; i++) {
		if ((i != src) && (costs[i] == costs[src] - routes[src][i])) {
			vector<int> *cur = new vector<int>(*path);
			find_path(routes, costs, num_node, i, paths, cur);
		}
	}
}

int main() {
	int num_node, num_route;
	string src;
	cin >> num_node >> num_route >> src;
	int *values = new int[num_node];
	int **routes = new int*[num_node];
	for (int i = 0; i < num_node; i++) {
		routes[i] = new int[num_node];
		for (int j = 0; j < num_node; j++)
			routes[i][j] = INT_MAX;
		routes[i][i] = 0;
	}
	string *idx_to_str = new string[num_node];
	idx_to_str[0] = src;
	map<string, int> str_to_idx;
	str_to_idx.insert(pair<string, int>(src, 0));
	values[0] = 0;
	for (int i = 1; i < num_node; i++) {
		string node;
		cin >> node;
		idx_to_str[i] = node;
		str_to_idx.insert(pair<string, int>(node, i));
		cin >> values[i];
	}
	for (int i = 0; i < num_route; i++) {
		string a, b;
		int cost;
		cin >> a >> b >> cost;
		routes[str_to_idx[a]][str_to_idx[b]] = cost;
		routes[str_to_idx[b]][str_to_idx[a]] = cost;
	}

	int *costs = Dijstra(routes, num_node, str_to_idx["ROM"]);
	vector<vector<int> *> paths;
	find_path(routes, costs, num_node, 0, paths, NULL);
	int idx, sum = -1;
	for (int i = 0; i < paths.size(); i++) {
		int cur_sum = 0;
		for (int j = 0; j < paths[i]->size(); j++)
			cur_sum += values[(*(paths[i]))[j]];
		if ((cur_sum > sum) || ((cur_sum == sum) && (paths[i]->size() < paths[idx]->size()))) {
			idx = i;
			sum = cur_sum;
		}
	}
	cout << paths.size() << " " << costs[0] << " " << sum << " " << sum / (paths[idx]->size() - 1) << endl << src;
	for (int j = 1; j < paths[idx]->size(); j++)
		cout << "->" << idx_to_str[(*(paths[idx]))[j]];

	return 0;
}