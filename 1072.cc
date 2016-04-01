#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cfloat>

/* convert string representation of houses and locations for gas station to indices in the map */
int str_to_idx(char *str, int num_house) {
	if (str[0] == 'G')														// a location for gas station
		return atoi(str + 1) + num_house - 1;
	return atoi(str) - 1;													// a house
}

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

int main() {
	int num_house, num_location, num_road, max_distance;
	scanf("%d %d %d %d", &num_house, &num_location, &num_road, &max_distance);
	int num_node = num_house + num_location;								// number of nodes on the map
	int **roads = new int*[num_node];
	for (int i = 0; i < num_node; i++) {
		roads[i] = new int[num_node];
		for (int j = 0; j < num_node; j++)
			roads[i][j] = INT_MAX;
		roads[i][i] = 0;
	}
	for (int i = 0; i < num_road; i++) {
		char a[8], b[8];													// the ends of each road
		int distance;
		scanf("%s %s %d", a, b, &distance);
		int idx_a = str_to_idx(a, num_house), idx_b = str_to_idx(b, num_house);
		roads[idx_a][idx_b] = distance;
		roads[idx_b][idx_a] = distance;
	}

	int location;
	double min = 0, avg = DBL_MAX;
	for (int i = num_house; i < num_node; i++) {
		int *distances = dijstra(roads, num_node, i);						// calculate the shortest distances of the houses to each location
		double cur_min = DBL_MAX, cur_avg = 0;
		for (int j = 0; j < num_house; j++) {
			if (distances[j] > max_distance) {								// one house is out of the max service range, do not choose this location to build gas station
				cur_min = -1;
				break;
			}
			if (distances[j] < cur_min)
				cur_min = distances[j];
			cur_avg += distances[j];
		}
		if ((cur_min > min) || ((cur_min == min) && (avg > cur_avg))) {		// found a better location
			location = i;
			min = cur_min;
			avg = cur_avg;
		}
		delete[] distances;
	}
	if (avg == DBL_MAX)														// no solution has ever found
		printf("No Solution");
	else
		printf("G%d\n%.1lf %.1lf", ++location - num_house, min, avg / num_house);

	return 0;
}