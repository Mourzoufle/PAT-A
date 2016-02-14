#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
	int id;
	int virtue;
	int talent;
};

bool compare(const Person *a, const Person *b) {
	if (a->virtue + a->talent != b->virtue + b->talent)
		return a->virtue + a->talent > b->virtue + b->talent;
	if (a->virtue != b->virtue)
		return a->virtue > b->virtue;

	return a->id < b->id;
}

int main() {
	vector<Person *> lists[4];
	int num_person, lower, higher;
	scanf("%d %d %d", &num_person, &lower, &higher);
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++) {
		scanf("%d %d %d", &people[i].id, &people[i].virtue, &people[i].talent);
		if ((people[i].virtue < lower) || (people[i].talent < lower))
			continue;
		if ((people[i].virtue >= higher) && (people[i].talent >= higher))
			lists[0].push_back(people + i);
		else if (people[i].virtue >= higher)
			lists[1].push_back(people + i);
		else if (people[i].virtue >= people[i].talent)
			lists[2].push_back(people + i);
		else
			lists[3].push_back(people + i);
	}

	printf("%d\n", lists[0].size() + lists[1].size() + lists[2].size() + lists[3].size());
	for (int i = 0; i < 4; i++) {
		sort(lists[i].begin(), lists[i].end(), compare);
		for (vector<Person *>::iterator iter = lists[i].begin(); iter != lists[i].end(); iter++)	
			printf("%08d %d %d\n", (*iter)->id, (*iter)->virtue, (*iter)->talent);
	}

	return 0;
}