#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int num_num;				// number of numbers
	scanf("%d", &num_num);
	int *nums = new int[num_num];
	for (int i = 0; i < num_num; i++)
		scanf("%d", &nums[i]);

	vector<int> pivots;			// candidates of the pivot - already in increasing order
	pivots.push_back(nums[0]);
	int max_num = nums[0];		// max number that have ever encountered
	for (int i = 1; i < num_num; i++) {
		if (nums[i] < max_num)	// check if the candidates are valid
			while (!pivots.empty()) {
				if (nums[i] < pivots.back())
					pivots.pop_back();
				else
					break;
			}
		else {					// new max number found - also can be a candidate
			pivots.push_back(nums[i]);
			max_num = nums[i];
		}
	}
	printf("%d\n", pivots.size());
	if (!pivots.empty()) {
		printf("%d", pivots[0]);
		for (int i = 1; i < pivots.size(); i++)
			printf(" %d", pivots[i]);
	}
	printf("\n");

	return 0;
}