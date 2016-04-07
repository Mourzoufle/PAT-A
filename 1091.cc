#include <cstdio>
#include <vector>

using namespace std;

struct Position {		// position of a pixel in the image
	int x;
	int y;
	int z;

	Position(int x, int y, int z): x(x), y(y), z(z) {};
};

/* BFS - get the volume of cores connected to the given one */
int get_vol(int ***image, int z, int x, int y, int size_z, int size_x, int size_y) {
	vector<Position *> positions;
	positions.push_back(new Position(x, y, z));
	image[z][x][y] = 0;	// this pixel will no longer be counted
	for (int i = 0; i < positions.size(); i++) {
		int x = positions[i]->x, y = positions[i]->y, z = positions[i]->z;
		if ((x > 0) && (image[z][x - 1][y] > 0)) {
			positions.push_back(new Position(x - 1, y, z));
			image[z][x - 1][y] = 0;
		}
		if ((x < size_x - 1) && (image[z][x + 1][y] > 0)) {
			positions.push_back(new Position(x + 1, y, z));
			image[z][x + 1][y] = 0;
		}
		if ((y > 0) && (image[z][x][y - 1] > 0)) {
			positions.push_back(new Position(x, y - 1, z));
			image[z][x][y - 1] = 0;
		}
		if ((y < size_y - 1) && (image[z][x][y + 1] > 0)) {
			positions.push_back(new Position(x, y + 1, z));
			image[z][x][y + 1] = 0;
		}
		if ((z > 0) && (image[z - 1][x][y] > 0)) {
			positions.push_back(new Position(x, y, z - 1));
			image[z - 1][x][y] = 0;
		}
		if ((z < size_z - 1) && (image[z + 1][x][y] > 0)) {
			positions.push_back(new Position(x, y, z + 1));
			image[z + 1][x][y] = 0;
		}
		delete positions[i];
	}

	return positions.size();
}

int main() {
	int size_x, size_y, size_z, threshold;
	scanf("%d %d %d %d", &size_x, &size_y, &size_z, &threshold);
	int ***image = new int**[size_z];
	for (int i = 0; i < size_z; i++) {
		image[i] = new int *[size_x];
		for (int j = 0; j < size_x; j++) {
			image[i][j] = new int[size_y];
			for (int k = 0; k < size_y; k++)
				scanf("%d", &image[i][j][k]);
		}
	}

	int total_vol = 0;	// total volume
	for (int i = 0; i < size_z; i++) {
		for (int j = 0; j < size_x; j++) {
			for (int k = 0; k < size_y; k++) {
				if (image[i][j][k] == 0)
					continue;
				int vol = get_vol(image, i, j, k, size_z, size_x, size_y);
				if (vol >= threshold)
					total_vol += vol;
			}
		}
	}
	printf("%d", total_vol);

	return 0;
}