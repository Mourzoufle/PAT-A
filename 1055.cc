#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_AGE = 200;
const int MAX_DISPLAY = 100;								// maximum number of outputs

struct Person {
	char name[16];
	int age;
	int worth;
};

/* compare fuction for sorting people - according to the worth first, then the age, then the names */
bool cmp(const Person &a, const Person &b) {
	if (a.worth != b.worth)
		return a.worth > b.worth;
	if (a.age != b.age)
		return a.age < b.age;
	return strcmp(a.name, b.name) < 0;
}

int main() {
	int num_person, num_query;
	scanf("%d %d", &num_person, &num_query);
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++)
		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
	sort(people, people + num_person, cmp);

	int counts_age[MAX_AGE];								// count of the people in each age
	for (int i = 0; i < MAX_AGE; i++)
		counts_age[i] = 0;
	vector<Person *> people_valid;							// the people that are possible to be output
	for (int i = 0; i < num_person; i++)
		if (++counts_age[people[i].age - 1] <= MAX_DISPLAY)	// if the people at this age is more than the maximum number of outputs, the surplus people are ignored
			people_valid.push_back(people + i);

	for (int i = 0; i < num_query; i++) {
		int max_display, age_lower, age_upper;
		scanf("%d %d %d", &max_display, &age_lower, &age_upper);
		printf("Case #%d:\n", i + 1);
		int num_display = 0;
		for (int j = 0; j < people_valid.size(); j++) {
			if ((people_valid[j]->age < age_lower) || (people_valid[j]->age > age_upper))
				continue;
			if (++num_display > max_display)				// the number of outputs has reached the upper bound
				break;
			printf("%s %d %d\n", people_valid[j]->name, people_valid[j]->age, people_valid[j]->worth);
		}
		if (num_display == 0)
			printf("None\n");
	}

	return 0;
}