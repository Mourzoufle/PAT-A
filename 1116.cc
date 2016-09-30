#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

/* check if the number is prime */
bool is_prime(int num) {
	if (num < 4)			// 2, 3 - true, 0 and 1 are handled externally
		return true;
	if (num % 2 == 0)		// even numbers beside of 2 - false
		return false;
	int limit = sqrt(num);	// only need to check factors not greater than sqrt(num)
	for (int i = 3; i <= limit; i += 2)
		if (num % i == 0)
			return false;
	return true;
}

int main() {
	int num_record, num_query;
	map<int, int> ranks;
	scanf("%d", &num_record);
	for (int i = 1; i <= num_record; i++) {
		int id;
		scanf("%d", &id);
		ranks[id] = i;
	}

	scanf("%d", &num_query);
	for (int i = 0; i < num_query; i++) {
		int id;
		scanf("%d", &id);
		printf("%04d: ", id);
		if (ranks.find(id) != ranks.end()) {
			int rank = ranks[id];
			if (rank == 0)
				printf("Checked\n");
			else if (rank == 1)
				printf("Mystery Award\n");
			else if (is_prime(rank))
				printf("Minion\n");
			else
				printf("Chocolate\n");
			ranks[id] = 0;
		}
		else
			printf("Are you kidding?\n");
	}

	return 0;
}