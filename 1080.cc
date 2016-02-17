#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
	int idx;
	int score_e;
	int score_i;
	vector<int> schools;
};

bool compare(const Student &a, const Student &b) {
	if (a.score_e + a.score_i != b.score_e + b.score_i)
		return a.score_e + a.score_i > b.score_e + b.score_i;
	return a.score_e > b.score_e;
}

int main() {
	int num_student, num_school, num_choice;
	cin >> num_student >> num_school >> num_choice;
	int *quotas = new int[num_school];
	for (int i = 0; i < num_school; i++)
		cin >> quotas[i];
	Student *students = new Student[num_student];
	for (int i = 0; i < num_student; i++) {
		students[i].idx = i;
		cin >> students[i].score_e >> students[i].score_i;
		for (int j = 0; j < num_choice; j++) {
			int school;
			cin >> school;
			students[i].schools.push_back(school);
		}
	}
	sort(students, students + num_student, compare);

	vector<int> *admits = new vector<int>[num_school];
	for (int i = 0; i < num_student; i++) {
		for (int j = 0; j < num_choice; j++) {
			int school = students[i].schools[j];
			if ((admits[school].size() < quotas[school]) || !compare(students[admits[school].back()], students[i])) {
				admits[school].push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < num_school; i++) {
		if (admits[i].empty()) {
			cout << endl;
			continue;
		}
		for (int j = 0; j < admits[i].size(); j++)
			admits[i][j] = students[admits[i][j]].idx;
		sort(admits[i].begin(), admits[i].end());
		for (int j = 0; j < admits[i].size() - 1; j++)
			cout << admits[i][j] << " ";
		cout << admits[i].back() << endl;
	}

	return 0;
}