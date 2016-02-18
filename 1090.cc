#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() {
	int num_node;
	double base, ratio;
	scanf("%d %lf %lf", &num_node, &base, &ratio);
	vector<int> *nodes = new vector<int>[num_node];
	queue<int> indices;
	queue<int> depths;
	for (int i = 0; i < num_node; i++) {
		int upper;
		scanf("%d", &upper);
		if (upper < 0) {
			indices.push(i);
			depths.push(0);
		}
		else
			nodes[upper].push_back(i);
	}

	int max = -1, num_sell = 0;
	while (!indices.empty()) {
		int idx = indices.front();
		int depth = depths.front();
		indices.pop();
		depths.pop();
		for (int i = 0; i < nodes[idx].size(); i++) {
			indices.push(nodes[idx][i]);
			depths.push(depth + 1);
		}
		if (max < depth) {
			max = depth;
			num_sell = 1;
		}
		else if (max == depth)
			num_sell++;
		if (indices.empty())
			printf("%.2f %d", base * pow(1 + ratio / 100, max), num_sell);
	}

	return 0;
}