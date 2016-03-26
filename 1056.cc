#include <cstdio>

int main() {
	int num_mouse, size_group;
	scanf("%d %d", &num_mouse, &size_group);
	int *weights = new int[num_mouse];
	for (int i = 0; i < num_mouse; i++)
		scanf("%d", &weights[i]);
	int *order = new int[num_mouse];								// the playing order of the players
	for (int i = 0; i < num_mouse; i++)
		scanf("%d", &order[i]);

	int *ranks = new int[num_mouse];								// ranks of the mice
	int num_player = num_mouse;										// initially all the players are in comparison
	while (num_player > 1) {										// comparison continues until there is only one winner
		int num_group = (num_player - 1) / size_group + 1;
		int *winners = new int[num_group];
		for (int i = 0; i < num_group; i++)
			winners[i] = -1;
		for (int i = 0; i < num_player; i++) {
			int group = i / size_group;
			if (winners[group] < 0)
				winners[group] = order[i];
			else if (weights[winners[group]] < weights[order[i]]) {	// the winner of this group is updated
				ranks[winners[group]] = num_group + 1;				// the loser has the rank following the winners
				winners[group] = order[i];
			}
			else
				ranks[order[i]] = num_group + 1;
		}
		delete[] order;
		order = winners;											// the winners become the players in the next round
		num_player = num_group;
	}
	ranks[order[0]] = 1;
	printf("%d", ranks[0]);
	for (int i = 1; i < num_mouse; i++)
		printf(" %d", ranks[i]);

	return 0;
}