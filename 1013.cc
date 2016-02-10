#include <iostream>

using namespace std;

void merge(int *sets, int src, int dst) {
	while (sets[src] != src)
		src = sets[src];
	while (sets[dst] != dst) {
		int tmp = sets[dst];
		sets[dst] = src;
		dst = tmp;
	}
	sets[dst] = src;
}

int main() {
	int num_city, num_road, num_check;
	cin >> num_city >> num_road >> num_check;
	int **roads = new int *[num_road];
	for (int i = 0; i < num_road; i++) {
		roads[i] = new int[2];
		cin >> roads[i][0] >> roads[i][1];
	}
	int *sets = new int[num_city];
	for (int r = 0; r < num_check; r++) {
		int target;
		cin >> target;
		for (int i = 0; i < num_city; i++)
			sets[i] = i;
		for (int i = 0; i < num_road; i++)
			if ((roads[i][0] != target) && (roads[i][1] != target))
				merge(sets, roads[i][0] - 1, roads[i][1] - 1);
		int num_repair = -2;
		for (int i = 0; i < num_city; i++)
			if (sets[i] == i)
				num_repair++;
		if (num_repair < 0)
			num_repair = 0;
		cout << num_repair << endl;
	}

	return 0;
}