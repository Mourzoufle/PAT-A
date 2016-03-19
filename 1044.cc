#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int num_num, price, min_pay = INT_MAX;			// number of diamonds; price to pay; minimum value to pay - the initial value of minimum payment can be replaced by any solutions
	scanf("%d %d", &num_num, &price);
	int *nums = new int[num_num];					// values of each diamond
	for (int i = 0; i < num_num; i++)
		scanf("%d", &nums[i]);

	vector<int *> solutions;						// solutions - each solution is stored as the head and tail indices
	int head = 0, tail = 0, cur_pay = nums[tail];	// head and tail indices of current string of diamonds whose values are in calculating; current sum of value
	while (tail < num_num) {
		if (cur_pay < price) {						// still not enough - attemp to add the value of the next diamond
			if (++tail < num_num)
				cur_pay += nums[tail];
		}
		else {
			if (cur_pay <= min_pay) {				// new solution found
				if (cur_pay < min_pay)				// this solution is better than existing ones
					solutions.clear();
				int *indices = new int[2];
				indices[0] = head + 1;
				indices[1] = tail + 1;
				solutions.push_back(indices);
				min_pay = cur_pay;
			}
			cur_pay -= nums[head++];				// start calculation from the diamond next to the head
		}
	}
	for (int i = 0; i < solutions.size(); i++)
		printf("%d-%d\n", solutions[i][0], solutions[i][1]);

	return 0;
}