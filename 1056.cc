#include <iostream>

using namespace std;

int main() {
	int num_mouse, size_group;
	cin >> num_mouse >> size_group;
	int *weights = new int[num_mouse];
	for (int i = 0; i < num_mouse; i++)
		cin >> weights[i];

	int num_player = num_mouse;
	int *players = new int[num_player];
	for (int i = 0; i < num_player; i++)
		cin >> players[i];
	int *ranks = new int[num_mouse];
	while (num_player > 1) {
		int num_group = (num_player - 1) / size_group + 1;
		int *winners = new int[num_group];
		for (int i = 0; i < num_group; i++)
			winners[i] = -1;
		for (int i = 0; i < num_player; i++) {
			int group = i / size_group;
			if (winners[group] < 0)
				winners[group] = players[i];
			else if (weights[winners[group]] < weights[players[i]]) {
				ranks[winners[group]] = num_group + 1;
				winners[group] = players[i];
			}
			else
				ranks[players[i]] = num_group + 1;
		}
		delete[] players;
		players = winners;
		num_player = num_group;
	}
	ranks[players[0]] = 1;

	cout << ranks[0];
	for (int i = 1; i < num_mouse; i++)
		cout << " " << ranks[i];

	return 0;
}