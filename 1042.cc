#include <iostream>
#include <cstdio>

using namespace std;

const char TYPES[] = {'S', 'H', 'C', 'D'}; 

int main() {
	int **cards = new int *[2];
	cards[0] = new int[54];
	cards[1] = new int[54];
	for (int i = 0; i < 54; i++)
		cards[0][i] = i;
	int iter;
	int *order = new int[54];
	cin >> iter;
	for (int i = 0; i < 54; i++)
		cin >> order[i];
	for (int r = 0; r < iter; r++)
		for (int i = 0; i < 54; i++)
			cards[1 - r % 2][order[i] - 1] = cards[r % 2][i];
	for (int i = 0; i < 54; i++) {
		if (i > 0)
			printf(" ");
		int card = cards[iter % 2][i];
		if (card > 51)
			printf("J%d", card - 51);
		else
			printf("%c%d", TYPES[card / 13], card % 13 + 1);
	}

	return 0;
}