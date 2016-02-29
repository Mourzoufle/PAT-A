#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
	int id;
	string name;
	int score;
};

bool compare_id(const Person &a, const Person &b) { return a.id < b.id; };

bool compare_name(const Person &a, const Person &b) {
	if (a.name != b.name)
		return a.name < b.name;
	return a.id < b.id;
}

bool compare_score(const Person &a, const Person &b) {
	if (a.score != b.score)
		return a.score < b.score;
	return a.id < b.id;
}

int main() {
	int num_person, idx;
	scanf("%d %d", &num_person, &idx);
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++) {
		char name[16];
		scanf("%d %s %d", &people[i].id, name, &people[i].score);
		people[i].name = name;
	}
	switch (idx) {
	case 1:
		sort(people, people + num_person, compare_id);
		break;
	case 2:
		sort(people, people + num_person, compare_name);
		break;
	case 3:
		sort(people, people + num_person, compare_score);
	}
	for (int i = 0; i < num_person; i++)
		printf("%06d %s %d\n", people[i].id, people[i].name.c_str(), people[i].score);

	return 0;
}