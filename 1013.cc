#include <cstdio>

/* Union-Find Sets - merge the sets that a and b belong to */
void merge(int *roots, int a, int b) {
	int root = a;
	while (roots[root] != root)									// find the root of a as the new root of two sets
		root = roots[root];
	while (roots[a] != root) {									// path compression of a and b
		int tmp = roots[a];
		roots[a] = root;
		a = tmp;
	}
	while (roots[b] != root) {
		int tmp = roots[b];
		roots[b] = root;
		b = tmp;
	}
}

int main() {
	int num_city, num_road, num_check;							// number of cities, roads, and cities to be checked
	scanf("%d %d %d", &num_city, &num_road, &num_check);
	int **roads = new int *[num_road];
	for (int i = 0; i < num_road; i++) {
		roads[i] = new int[2];
		scanf("%d %d", &roads[i][0], &roads[i][1]);
	}

	int *roots = new int[num_city];								// the root city of each city
	for (int i = 0; i < num_check; i++) {
		int city;
		scanf("%d", &city);
		for (int j = 0; j < num_city; j++)						// all cities are separated sets
			roots[j] = j;
		for (int j = 0; j < num_road; j++)
			if ((roads[j][0] != city) && (roads[j][1] != city))	// drop the roads connected with the city under checking
				merge(roots, roads[j][0] - 1, roads[j][1] - 1);
		int num_set = 0;
		for (int j = 0; j < num_city; j++)						// number of roots indicates number of sets
			if (roots[j] == j)
				num_set++;
		printf("%d\n", num_set > 1 ? num_set - 2 : 0);			// if only one set (beside of the city under checking) - no road needed
	}

	return 0;
}