#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
	string name;
	int age;
	int net_worth;
};

bool compare(const Person &a, const Person &b) {
	if (a.net_worth != b.net_worth)
		return a.net_worth > b.net_worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return a.name < b.name;
}

int main() {
	int num_person, num_query;
	cin >> num_person >> num_query;
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++)
		cin >> people[i].name >> people[i].age >> people[i].net_worth;

	sort(people, people + num_person, compare);
	int age_counts[200];
	for (int i = 0; i < 200; i++)
		age_counts[i] = 0;
	vector<Person *> list;
	for (int i = 0; i < num_person; i++)
		if (++age_counts[people[i].age - 1] <= 100)
			list.push_back(people + i);

	for (int i = 0; i < num_query; i++) {
		int max, lower, upper;
		cin >> max >> lower >> upper;
		cout << "Case #" << i + 1 << ":" << endl;
		int num_output = 0;
		for (int j = 0; j < list.size(); j++) {
			if ((list[j]->age < lower) || (list[j]->age > upper))
				continue;
			if (++num_output > max)
				break;
			else
				cout << list[j]->name << " " << list[j]->age << " " << list[j]->net_worth << endl;
		}
		if (num_output == 0)
			cout << "None" << endl;
	}

	return 0;
}