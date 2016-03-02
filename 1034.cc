#include <cstdio>
#include <vector>

using namespace std;

const int MAX_GANG = 26 * 26 * 26;

struct Gang {
	int upper;
	int self_weight;
	int num_member;
	int total_weight;

	Gang(): self_weight(0), num_member(1), total_weight(0) {}
};

int str_to_num(char *str) { return (str[0] - 'A') * 676 + (str[1] - 'A') * 26 + str[2] - 'A'; }

void merge(Gang *gangs, int a, int b, int weight) {
	gangs[a].self_weight += weight;
	gangs[b].self_weight += weight;
	int root_a = a, root_b = b;
	while (gangs[root_a].upper != root_a)
		root_a = gangs[root_a].upper;
	while (gangs[root_b].upper != root_b)
		root_b = gangs[root_b].upper;
	int root = root_a;
	if (gangs[root_b].self_weight > gangs[root].self_weight)
		root = root_b;
	if (gangs[a].self_weight > gangs[root].self_weight)
		root = a;
	if (gangs[b].self_weight > gangs[root].self_weight)
		root = b;
	while (gangs[a].upper != a) {
		int tmp = gangs[a].upper;
		gangs[a].upper = root;
		a = tmp;
	}
	gangs[root_a].upper = root;
	while (gangs[b].upper != b) {
		int tmp = gangs[b].upper;
		gangs[b].upper = root;
		b = tmp;
	}
	gangs[root_b].upper = root;
	if ((root_a == root_b) && (root != root_a)) {
		gangs[root].num_member = gangs[root_a].num_member;
		gangs[root].total_weight = gangs[root_a].total_weight;
	}
	else if (root_a != root_b) {
		gangs[root].num_member = gangs[root_a].num_member + gangs[root_b].num_member;
		gangs[root].total_weight = gangs[root_a].total_weight + gangs[root_b].total_weight;
	}
	gangs[root].total_weight += weight;
}

int main() {
	Gang *gangs = new Gang[MAX_GANG];
	for (int i = 0; i < MAX_GANG; i++)
		gangs[i].upper = i;
	int num_record, threshold;
	scanf("%d %d", &num_record, &threshold);
	for (int i = 0; i < num_record; i++) {
		char a[4], b[4];
		int weight;
		scanf("%s %s %d", a, b, &weight);
		merge(gangs, str_to_num(a), str_to_num(b), weight);
	}

	vector<int> valid_gangs;
	for (int i = 0; i < MAX_GANG; i++)
		if ((gangs[i].upper == i) && (gangs[i].total_weight > threshold) && (gangs[i].num_member > 2))
			valid_gangs.push_back(i);
	printf("%d\n", valid_gangs.size());
	for (int i = 0; i < valid_gangs.size(); i++)
		printf("%c%c%c %d\n", valid_gangs[i] / 676 + 'A', (valid_gangs[i] % 676) / 26 + 'A', valid_gangs[i] % 26 + 'A', gangs[valid_gangs[i]].num_member);

	return 0;
}