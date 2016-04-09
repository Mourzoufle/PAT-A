#include <cstdio>
#include <cstring>

int main() {
	char *strs[2];							// strings of beads that is provided and required
	for (int i = 0; i < 2; i++) {
		strs[i] = new char[1024];
		scanf("%s", strs[i]);
	}

	int *counts[2];							// numbers of the beads in each color in the provided and required strings
	for (int i = 0; i < 2; i++) {
		counts[i] = new int[256];
		for (int j = 0; j < 256; j++)
			counts[i][j] = 0;
		for (int j = 0; strs[i][j] != '\0'; j++)
			counts[i][strs[i][j]]++;
	}
	int num_miss = 0;						// number of missing beads
	for (int i = 0; i < 256; i++)
		if (counts[0][i] < counts[1][i])	// number of beads in this color is not enough
			num_miss += counts[1][i] - counts[0][i];
	if (num_miss == 0)						// no missing beads
		printf("Yes %d", strlen(strs[0]) - strlen(strs[1]));
	else
		printf("No %d", num_miss);

	return 0;
}