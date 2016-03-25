#include <cstdio>
#include <map>

using namespace std;

int main() {
	int row, col;
	scanf("%d %d", &row, &col);
	int threshold = (col * row + 1) / 2;		// the dominant color must occur in at least half of the total pixels
	map<int, int> counts;						// count of each color
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int color;
			scanf("%d", &color);
			if (counts.find(color) == counts.end())
				counts[color] = 0;
			if (++counts[color] >= threshold) {	// dominant color found
				printf("%d", color);
				return 0;
			}
		}
	}
	return 0;
}