#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <cfloat>

using namespace std;

int str_to_idx(string str, int num) {
	if (str[0] == 'G')
		str = str.substr(1);
	else
		num = 0;
	stringstream ss;
	int idx;
	ss << str;
	ss >> idx;

	return idx + num - 1;
}

int* Dijstra(int **roads, int num_node, int dst) {
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
			if ((idx < 0) || (distances[idx] > distances[j]))
				idx = j;
		}
		if (distances[idx] == INT_MAX)
			break;
		visit[idx] = true;
		for (int j = 0; j < num_node; j++)
			if (distances[j] - distances[idx] > roads[j][idx])
				distances[j] = roads[j][idx] + distances[idx];
	}
	delete[] visit;

	return distances;
}

int main() {
	int num_house, num_station, num_road, max_distance;
	cin >> num_house >> num_station >> num_road >> max_distance;
	num_station += num_house;
	int **roads = new int*[num_station];
	for (int i = 0; i < num_station; i++) {
		roads[i] = new int[num_station];
		for (int j = 0; j < num_station; j++)
			roads[i][j] = INT_MAX;
		roads[i][i] = 0;
	}
	for (int i = 0; i < num_road; i++) {
		string str_a, str_b;
		int distance;
		cin >> str_a >> str_b >> distance;
		int idx_a = str_to_idx(str_a, num_house), idx_b = str_to_idx(str_b, num_house);
		roads[idx_a][idx_b] = distance;
		roads[idx_b][idx_a] = distance;
	}
	int idx = -1;
	double min = 0, avg = DBL_MAX;
	for (int i = num_house; i < num_station; i++) {
		int *distances = Dijstra(roads, num_station, i);
		double cur_min = max_distance, cur_avg = 0;
		for (int j = 0; j < num_house; j++) {
			if (distances[j] > max_distance) {
				cur_min = -1;
				break;
			}
			if (distances[j] < cur_min)
				cur_min = distances[j];
			cur_avg += distances[j];
		}
		delete[] distances;
		if ((min < cur_min) || ((min == cur_min) && (avg > cur_avg))) {
			idx = i;
			min = cur_min;
			avg = cur_avg;
		}
	}
	if (idx < 0)
		cout << "No Solution";
	else
		printf("G%d\n%.1f %.1f", ++idx - num_house, min, avg / num_house);

	return 0;
}