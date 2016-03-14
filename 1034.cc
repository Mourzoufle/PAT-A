#include <cstdio>
#include <vector>

using namespace std;

const int MAX_GANG = 26 * 26 * 26;																		// max number of people or gangs (since each of them is represented by three capital letters)

struct Gang {
	int head;																							// the head of this gang
	int self_weight;																					// the weight of this person
	int num_member;																						// number of members in this gang
	int total_weight;																					// the total weight of this gang

	Gang(): self_weight(0), num_member(1), total_weight(0) {}											// each person is treated as a gang initially
};

/* map each string of name to an integer */
int str_to_num(char *str) { return (str[0] - 'A') * 676 + (str[1] - 'A') * 26 + str[2] - 'A'; }

/* Union-Find Sets - merge the gangs that a and b belong to and modify the weight of related people and gangs */
void merge(Gang *gangs, int a, int b, int weight) {
	gangs[a].self_weight += weight;																		// the weights of a and b themselves are increased
	gangs[b].self_weight += weight;
	int head_a = a, head_b = b;
	while (gangs[head_a].head != head_a)
		head_a = gangs[head_a].head;
	while (gangs[head_b].head != head_b)
		head_b = gangs[head_b].head;
	int head = head_a;																					// compare the weight of a, b, and the heads of gangs a and b belong to, the one with the max weight is the new head
	if (gangs[head_b].self_weight > gangs[head].self_weight)
		head = head_b;
	if (gangs[a].self_weight > gangs[head].self_weight)
		head = a;
	if (gangs[b].self_weight > gangs[head].self_weight)
		head = b;
	while (gangs[a].head != head) {																		// path compression of a and b
		int tmp = gangs[a].head;
		gangs[a].head = head;
		a = tmp;
	}
	while (gangs[b].head != head) {
		int tmp = gangs[b].head;
		gangs[b].head = head;
		b = tmp;
	}
	if ((head_a == head_b) && (head != head_a)) {														// a and b belong to the same gang previously, and a or b becomes the new head - get the number of members and the total weight from the former head
		gangs[head].num_member = gangs[head_a].num_member;
		gangs[head].total_weight = gangs[head_a].total_weight;
	}
	else if (head_a != head_b) {																		// or the two gangs are merged, reset the new head with the combined number of members and total weight
		gangs[head].num_member = gangs[head_a].num_member + gangs[head_b].num_member;
		gangs[head].total_weight = gangs[head_a].total_weight + gangs[head_b].total_weight;
	}
	gangs[head].total_weight += weight;																	// the total weight of the gang is increased
}

int main() {
	Gang *gangs = new Gang[MAX_GANG];
	for (int i = 0; i < MAX_GANG; i++)
		gangs[i].head = i;																				// all people are separated gangs
	int num_call, threshold;																			// number of phone calls; the weight threshold
	scanf("%d %d", &num_call, &threshold);
	for (int i = 0; i < num_call; i++) {
		char a[4], b[4];
		int weight;
		scanf("%s %s %d", a, b, &weight);
		merge(gangs, str_to_num(a), str_to_num(b), weight);
	}

	vector<int> gangs_valid;																			// valid gangs
	for (int i = 0; i < MAX_GANG; i++)
		if ((gangs[i].head == i) && (gangs[i].total_weight > threshold) && (gangs[i].num_member > 2))	// valid gangs have total weight larger than threshold and more than 2 members
			gangs_valid.push_back(i);
	printf("%d\n", gangs_valid.size());
	for (int i = 0; i < gangs_valid.size(); i++)
		printf("%c%c%c %d\n", gangs_valid[i] / 676 + 'A', (gangs_valid[i] % 676) / 26 + 'A', gangs_valid[i] % 26 + 'A', gangs[gangs_valid[i]].num_member);

	return 0;
}