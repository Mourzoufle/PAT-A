#include <cstdio>

const char TYPES[8] = "SHCDJ";								// types of cards
const int NUM_CARD = 54;									// number of cards

int main() {
	int **cards = new int *[2];								// the current order of the cards and the next order after shuffling
	for (int i = 0; i < 2; i++)
		cards[i] = new int[NUM_CARD];
	int num_repeat;											// number of repeating times
	scanf("%d", &num_repeat);
	int *order = new int[NUM_CARD];							// the given order of shuffling
	for (int i = 0; i < NUM_CARD; i++) {
		cards[0][i] = i;									// the initial order
		scanf("%d", &order[i]);
		order[i]--;
	}

	for (int i = 0; i < num_repeat; i++)
		for (int j = 0; j < NUM_CARD; j++)
			cards[1 - i % 2][order[j]] = cards[i % 2][j];	// for odd-numbered shuffling, the new order of cards are stored in cards[1], otherwise in cards[0]
	for (int i = 0; i < NUM_CARD; i++) {
		if (i > 0)
			printf(" ");
		printf("%c%d", TYPES[cards[num_repeat % 2][i] / 13], cards[num_repeat % 2][i] % 13 + 1);
	}

	return 0;
}