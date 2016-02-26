#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

void merge(int *nodes, int src, int dst) {
	while (nodes[dst] != dst)
		dst = nodes[dst];
	while (nodes[src] != src) {
		int tmp = nodes[src];
		nodes[src] = dst;
		src = tmp;
	}
	nodes[src] = dst;
}

int get_part(int *heads, int *tails, int num_node) {
	int *nodes = new int[num_node];
	for (int i = 0; i < num_node; i++)
		nodes[i] = i;
	for (int i = 0; i < num_node - 1; i++)
		merge(nodes, heads[i], tails[i]);
	int num_part = 0;
	for (int i = 0; i < num_node; i++)
		if (nodes[i] == i)
			num_part++;

	return num_part;
}

set<int>* find_root(int *heads, int *tails, int num_node, int src) {
	set<int> *roots = new set<int>;
	bool *visit = new bool[num_node];
	for (int i = 0; i < num_node; i++)
		visit[i] = false;
	queue<int> nodes, lengths;
	nodes.push(src);
	lengths.push(0);
	int max_length = 0;
	while (!nodes.empty()) {
		int cur_node = nodes.front();
		int cur_length = lengths.front();
		nodes.pop();
		lengths.pop();
		bool end = true;
		for (int i = 0; i < num_node - 1; i++) {
			if (visit[heads[i]] || visit[tails[i]])
				continue;
			if ((heads[i] != cur_node) && (tails[i] != cur_node))
				continue;
			nodes.push(heads[i] == cur_node ? tails[i] : heads[i]);
			lengths.push(cur_length + 1);
			end = false;
		}
		visit[cur_node] = true;
		if (end) {
			if (cur_length > max_length) {
				roots->clear();
				max_length = cur_length;
			}
			if (cur_length == max_length)
				roots->insert(cur_node);
		}
	}
	delete[] visit;

	return roots;
}

int main() {
	int num_node;
	scanf("%d", &num_node);
	int *heads = new int[num_node - 1];
	int *tails = new int[num_node - 1];
	for (int i = 0; i < num_node - 1; i++) {
		scanf("%d %d", &heads[i], &tails[i]);
		heads[i]--;
		tails[i]--;
	}
	int num_part = get_part(heads, tails, num_node);
	if (num_part != 1) {
		printf("Error: %d components", num_part);
		return 0;
	}
	set<int> *init = find_root(heads, tails, num_node, 0);
	set<int> *final = find_root(heads, tails, num_node, *(init->begin()));
	final->insert(init->begin(), init->end());
	for (set<int>::iterator iter = final->begin(); iter != final->end(); iter++)
		printf("%d\n", (*iter) + 1);

	return 0;
}