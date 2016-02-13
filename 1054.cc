#include <iostream>
#include <map>

using namespace std;

int main() {
	int col, row;
	cin >> col >> row;
	int mid = (col * row + 1) >> 1;
	map<int, int> hist;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int pixel;
			cin >> pixel;
			if (hist.find(pixel) == hist.end())
				hist[pixel] = 0;
			if (++hist[pixel] >= mid) {
				cout << pixel;
				return 0;
			}
		}
	}

	return 0;
}