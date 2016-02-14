#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main() {
	int num_set;
	cin >> num_set;
	set<int> *sets = new set<int>[num_set];
	for (int i = 0; i < num_set; i++) {
		int num_key;
		cin >> num_key;
		for (int j = 0; j < num_key; j++) {
			int key;
			cin >> key;
			sets[i].insert(key);
		}
	}

	int num_query;
	cin >> num_query;
	int indices[2];
	for (int i = 0; i < num_query; i++) {
		int indices[2];
		cin >> indices[0] >> indices[1];
		int num_inter = 0;
		int idx = sets[--indices[0]].size() < sets[--indices[1]].size() ? 0 : 1;
		for (set<int>::iterator iter = sets[indices[idx]].begin(); iter != sets[indices[idx]].end(); iter++)
			if (sets[indices[1 - idx]].find(*iter) != sets[indices[1 - idx]].end())
				num_inter++;
		printf("%.1f\%\n", 100.0 * num_inter / (sets[indices[idx]].size() + sets[indices[1 - idx]].size() - num_inter));
	}

	return 0;
}