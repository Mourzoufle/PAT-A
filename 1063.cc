#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int num_set;
	scanf("%d", &num_set);
	set<int> *sets = new set<int>[num_set];
	for (int i = 0; i < num_set; i++) {
		int num_key;
		scanf("%d", &num_key);
		for (int j = 0; j < num_key; j++) {
			int key;
			scanf("%d", &key);
			sets[i].insert(key);
		}
	}

	int num_query;
	scanf("%d", &num_query);
	for (int i = 0; i < num_query; i++) {
		int indices[2];			// the indices of sets in query
		scanf("%d %d", &indices[0], &indices[1]);
		indices[0]--;
		indices[1]--;
		set<int> intersection;	// the intersection of the two sets
		set_intersection(sets[indices[0]].begin(), sets[indices[0]].end(), sets[indices[1]].begin(), sets[indices[1]].end(), inserter(intersection, intersection.begin()));
		printf("%.1lf%%\n", 100.0 * intersection.size() / (sets[indices[0]].size() + sets[indices[1]].size() - intersection.size()));
	}

	return 0;
}