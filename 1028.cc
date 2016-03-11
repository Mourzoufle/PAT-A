#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Person {
	int id;
	char name[16];
	int grade;
};

/* compare fuction for sorting records - according to id */
bool cmp_id(const Person &a, const Person &b) { return a.id < b.id; };

/* compare fuction for sorting records - according to name, then id */
bool cmp_name(const Person &a, const Person &b) {
	if (strcmp(a.name, b.name) != 0)
		return strcmp(a.name, b.name) < 0;
	return a.id < b.id;
}

/* compare fuction for sorting records - according to higher grade, then id */
bool cmp_grade(const Person &a, const Person &b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	return a.id < b.id;
}

int main() {
	int num_person, idx_sort;
	scanf("%d %d", &num_person, &idx_sort);
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++)
		scanf("%d %s %d", &people[i].id, people[i].name, &people[i].grade);
	switch (idx_sort) {
	case 1:
		sort(people, people + num_person, cmp_id);
		break;
	case 2:
		sort(people, people + num_person, cmp_name);
		break;
	case 3:
		sort(people, people + num_person, cmp_grade);
	}
	for (int i = 0; i < num_person; i++)
		printf("%06d %s %d\n", people[i].id, people[i].name, people[i].grade);

	return 0;
}