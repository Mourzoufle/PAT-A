#include <cstdio>

int main() {
	int num_color, num_favor, num_piece;
	scanf("%d %d", &num_color, &num_favor);
	int *order = new int[num_color];													// order of favorite colors - for colors not in the favorite list, it is -1
	for (int i = 0; i <= num_color; i++)
		order[i] = -1;
	for (int i = 0; i < num_favor; i++) {
		int color;
		scanf("%d", &color);
		order[--color] = i;
	}
	scanf("%d", &num_piece);
	int *pieces = new int[num_piece];
	for (int i = 0; i < num_piece; i++)
		scanf("%d", &pieces[i]);

	int *lengths = new int[num_piece];													// the maximum length of favorite stripe that can be obtained via cutting at each piece
	int max_length = 0;
	for (int i = 0; i < num_piece; i++) {
		lengths[i] = 0;
		if (order[--pieces[i]] < 0)														// this piece is not in a favorite color - no need to calculate the maxmum length
			continue;
		for (int j = 0; j < i; j++)
			if ((order[pieces[j]] <= order[pieces[i]]) && (lengths[j] > lengths[i]))	// same as calculating the length of the longest nondecreasing subsequence
				lengths[i] = lengths[j];
		if (++lengths[i] > max_length)
			max_length = lengths[i];
	}
	printf("%d", max_length);

	return 0;
}