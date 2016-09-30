#include <iostream>
#include <cmath>

using namespace std;

const int MAX_BIRD = 10000;

int find_root(int *roots, int node) {
	while (roots[node] != node)
		node = roots[node];

	return node;
}

/* Union-Find Sets - merge the sets that a and b belong to */
void merge(int *roots, int a, int b) {
	int root = find_root(roots, a);
	while (roots[a] != root) {									// path compression of a and b
		int tmp = roots[a];
		roots[a] = root;
		a = tmp;
	}
	while (roots[b] != root) {
		int tmp = roots[b];
		roots[b] = root;
		b = tmp;
	}
}

int main() {
	int *roots = new int[MAX_BIRD];
	for (int i = 0; i < MAX_BIRD; i++)
		roots[i] = i;

	int num_photo, num_query, max_idx = 0;
	cin >> num_photo;
	for (int i = 0; i < num_photo; i++) {
		int num_bird;
		cin >> num_bird;
		int *birds = new int[num_bird];
		for (int j = 0; j < num_bird; j++) {
			cin >> birds[j];
			max_idx = max(max_idx, birds[j]--);
		}
		for (int j = 1; j < num_bird; j++)
			for (int k = 0; k < j; k++)
				merge(roots, birds[j], birds[k]);
	}

	int num_tree = 0;
	for (int i = 0; i < max_idx; i++)
		if (roots[i] == i)
			num_tree++;
	cout << num_tree << " " << max_idx << endl;

	cin >> num_query;
	for (int i = 0; i < num_query; i++) {
		int a, b;
		cin >> a >> b;
		if (find_root(roots, --a) == find_root(roots, --b))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}