#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int num_num;
	scanf("%d", &num_num);
	int *nums = new int[num_num];
	for (int i = 0; i < num_num; i++)
		scanf("%d", &nums[i]);
	sort(nums, nums + num_num);

	int num_row, num_col;
	for (int i = sqrt(num_num - 1) + 1; i <= num_num; i++) {
		if (num_num % i == 0) {
			num_row = i;
			num_col = num_num / num_row;
			break;
		}
	}
	int **matrix = new int *[num_row];
	for (int i = 0; i < num_row; i++) {
		matrix[i] = new int[num_col];
		for (int j = 0; j < num_col; j++)
			matrix[i][j] = 0;
	}

	int cur_row = 0, cur_col = 0, inc_row = 0, inc_col = 1;
	matrix[0][0] = nums[num_num - 1];
	for (int i = num_num - 2; i >= 0; i--) {
		if ((inc_row > 0) && ((cur_row + inc_row >= num_row) || (matrix[cur_row + inc_row][cur_col] > 0))) {
			inc_row = 0;
			inc_col = -1;
		}
		else if ((inc_row < 0) && ((cur_row + inc_row < 0) || (matrix[cur_row + inc_row][cur_col] > 0))) {
			inc_row = 0;
			inc_col = 1;
		}
		else if ((inc_col > 0) && ((cur_col + inc_col >= num_col) || (matrix[cur_row][cur_col + inc_col] > 0))) {
			inc_row = 1;
			inc_col = 0;
		}
		else if ((inc_col < 0) && ((cur_col + inc_col < 0) || (matrix[cur_row][cur_col + inc_col] > 0))) {
			inc_row = -1;
			inc_col = 0;
		}
		cur_row += inc_row;
		cur_col += inc_col;
		matrix[cur_row][cur_col] = nums[i];
	}
	for (int i = 0; i < num_row; i++) {
		printf("%d", matrix[i][0]);
		for (int j = 1; j < num_col; j++)
			printf(" %d", matrix[i][j]);
		printf("\n");
	}

	return 0;
}