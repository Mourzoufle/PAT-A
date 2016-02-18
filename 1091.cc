#include <cstdio>
#include <stack>

using namespace std;

struct Pos {
	int x;
	int y;
	int z;

	Pos(int x, int y, int z): x(x), y(y), z(z) {}; 
};

int DFS(int ***image, int z, int x, int y, int size_z, int size_x, int size_y) {
	stack<Pos *> poses;
	int sum = 0;
	poses.push(new Pos(x, y, z));
	image[z][x][y] = 0;
	while (!poses.empty()) {
		sum++;
		Pos *pos = poses.top();
		poses.pop();
		if ((pos->z + 1 < size_z) && image[pos->z + 1][pos->x][pos->y] > 0) {
			image[pos->z + 1][pos->x][pos->y] = 0;
			poses.push(new Pos(pos->x, pos->y, pos->z + 1));
		}
		if ((pos->z > 0) && image[pos->z - 1][pos->x][pos->y] > 0) {
			image[pos->z - 1][pos->x][pos->y] = 0;
			poses.push(new Pos(pos->x, pos->y, pos->z - 1));
		}
		if ((pos->x + 1 < size_x) && image[pos->z][pos->x + 1][pos->y] > 0) {
			image[pos->z][pos->x + 1][pos->y] = 0;
			poses.push(new Pos(pos->x + 1, pos->y, pos->z));
		}
		if ((pos->x > 0) && image[pos->z][pos->x - 1][pos->y] > 0) {
			image[pos->z][pos->x - 1][pos->y] = 0;
			poses.push(new Pos(pos->x - 1, pos->y, pos->z));
		}
		if ((pos->y + 1 < size_y) && image[pos->z][pos->x][pos->y + 1] > 0) {
			image[pos->z][pos->x][pos->y + 1] = 0;
			poses.push(new Pos(pos->x, pos->y + 1, pos->z));
		}
		if ((pos->y > 0) && image[pos->z][pos->x][pos->y - 1] > 0) {
			image[pos->z][pos->x][pos->y - 1] = 0;
			poses.push(new Pos(pos->x, pos->y - 1, pos->z));
		}
		delete[] pos;
	}

	return sum;
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

	int sum = 0;
	for (int i = 0; i < size_z; i++) {
		for (int j = 0; j < size_x; j++) {
			for (int k = 0; k < size_y; k++) {
				if (image[i][j][k] == 0)
					continue;
				int cur = DFS(image, i, j, k, size_z, size_x, size_y);
				if (cur >= threshold)
					sum += cur;
			}
		}
	}
	printf("%d", sum);

	return 0;
}