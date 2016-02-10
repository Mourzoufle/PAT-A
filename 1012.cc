#include <iostream>
#include <map>

using namespace std;

const string COURSES[] = {
	" A",
	" C",
	" M",
	" E"
};

int get_rank(int *arr, int size, int idx) {
	int rank = 1;
	for (int i = 0; i < size; i++)
		if (arr[idx] < arr[i])
			rank++;

	return rank;
}

int main() {
	int num_all, num_query;
	cin >> num_all >> num_query;
	int **scores = new int*[4];
	for (int i = 0; i < 4; i++)
		scores[i] = new int[num_all];
	map<int, int> indices;
	for (int i = 0; i < num_all; i++) {
		int id;
		cin >> id >> scores[1][i] >> scores[2][i] >> scores[3][i];
		scores[0][i] = (scores[1][i] + scores[2][i] + scores[3][i]) / 3;
		indices.insert(pair<int, int>(id, i));
	}

	int *ranks = new int[4];
	for (int i = 0; i < num_query; i++) {
		int id;
		cin >> id;
		if (indices.find(id) == indices.end()) {
			cout << "N/A" << endl;
			continue;
		}
		int idx = indices[id];
		int min = 0;
		for (int j = 0; j < 4; j++) {
			ranks[j] = get_rank(scores[j], num_all, idx);
			if (ranks[min] > ranks[j])
				min = j;
		}
		cout << ranks[min] << COURSES[min] << endl;
	}

	return 0;
}