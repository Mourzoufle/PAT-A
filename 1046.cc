#include <cstdio>

int main() {
	int num_exit, num_query;						// number of exits of the highway; number of quries
	scanf("%d", &num_exit);
	int *distances = new int[num_exit];				// distance between the first exit and each of the other exits
	for (int i = 0; i < num_exit; i++) {
		scanf("%d", &distances[i]);
		if (i > 0)
			distances[i] += distances[i - 1];		// the last item is the length of the highway
	}
	scanf("%d", &num_query);
	for (int i = 0; i < num_query; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int distance = (a > 1 ? distances[a - 2] : 0) - (b > 1 ? distances[b - 2] : 0);
		if (distance < 0)
			distance = -distance;
		if (distance * 2 > distances[num_exit - 1])	// since the highway is a circle, the distance should be no larger than half of its length
			distance = distances[num_exit - 1] - distance;
		printf("%d\n", distance);
	}

	return 0;
}