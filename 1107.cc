#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_HOBBY = 1000;

struct Cluster {
	int root;								// root member of the cluster
	int num_member;							// number of members
	bool hobbies[MAX_HOBBY];				// flag indicating if this member has each hobby 

	Cluster(): num_member(1) {
		for (int i = 0; i < MAX_HOBBY; i++)
			hobbies[i] = false;
	}
};

/* Union-Find Sets - merge the sets that a and b belong to */
void merge(Cluster *clusters, int a, int b) {
	int root_a = a, root_b = b;
	while (clusters[root_a].root != root_a)
		root_a = clusters[root_a].root;
	while (clusters[root_b].root != root_b)
		root_b = clusters[root_b].root;
	if (root_a != root_b)					// merge two different clusters and update the number of members
		clusters[root_a].num_member += clusters[root_b].num_member;
	while (clusters[a].root != root_a) {	// path compression of a and b
		int tmp = clusters[a].root;
		clusters[a].root = root_a;
		a = tmp;
	}
	while (clusters[b].root != root_a) {
		int tmp = clusters[b].root;
		clusters[b].root = root_a;
		b = tmp;
	}
}

int main() {
	int num_person;
	scanf("%d", &num_person);
	Cluster *clusters = new Cluster[num_person];
	for (int i = 0; i < num_person; i++) {
		clusters[i].root = i;
		int num_hobby;
		scanf("%d: ", &num_hobby);
		for (int j = 0; j < num_hobby; j++) {
			int hobby;
			scanf("%d", &hobby);
			clusters[i].hobbies[--hobby] = true;
		}
	}

	for (int i = 0; i < num_person; i++) {
		for (int j = i + 1; j < num_person; j++) {
			bool share = false;				// flag indicating if i and j share the same hobby
			for (int k = 0; k < MAX_HOBBY; k++) {
				if (clusters[i].hobbies[k] && clusters[j].hobbies[k]) {
					share = true;
					break;
				}
			}
			if (share)
				merge(clusters, i, j);
		}
	}

	vector<int> nums_member;				// number of the members in each cluster
	for (int i = 0; i < num_person; i++)
		if (clusters[i].root == i)
			nums_member.push_back(clusters[i].num_member);
	sort(nums_member.begin(), nums_member.end());
	printf("%d\n%d", nums_member.size(), nums_member.back());
	for (int i = nums_member.size() - 2; i >= 0; i--)
		printf(" %d", nums_member[i]);

	return 0;
}