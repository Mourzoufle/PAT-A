#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_HOBBY = 1000;

struct Cluster {
	int root;
	int num_member;
	bool hobbies[MAX_HOBBY];

	Cluster(): num_member(1) {
		for (int i = 0; i < MAX_HOBBY; i++)
			hobbies[i] = false;
	}
};

void merge(Cluster *clusters, int a, int b) {
	int root_a = a, root_b = b;
	while (clusters[root_a].root != root_a)
		root_a = clusters[root_a].root;
	while (clusters[root_b].root != root_b)
		root_b = clusters[root_b].root;
	if (root_a != root_b)
		clusters[root_a].num_member += clusters[root_b].num_member;
	while (clusters[a].root != root_a) {
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
			bool share = false;
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

	vector<int> nums_member;
	for (int i = 0; i < num_person; i++)
		if (clusters[i].root == i)
			nums_member.push_back(clusters[i].num_member);
	sort(nums_member.begin(), nums_member.end());
	printf("%d\n%d", nums_member.size(), nums_member.back());
	for (int i = nums_member.size() - 2; i >= 0; i--)
		printf(" %d", nums_member[i]);

	return 0;
}
