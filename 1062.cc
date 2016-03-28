#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
	int id;
	int virtue;
	int talent;
};

/* compare fuction for sorting records - sorted by score, then id if the scores are equal */
bool cmp(const Person *a, const Person *b) {
	if (a->virtue + a->talent != b->virtue + b->talent)
		return a->virtue + a->talent > b->virtue + b->talent;
	if (a->virtue != b->virtue)
		return a->virtue > b->virtue;

	return a->id < b->id;
}

int main() {
	vector<Person *> people_valids[4];									// people that are qualified as sages, noblemen, fools, and small men
	int num_person, lower, upper;										// number of people; the lower bound of the qualified grades; the higher line of qualification
	scanf("%d %d %d", &num_person, &lower, &upper);
	Person *people = new Person[num_person];
	for (int i = 0; i < num_person; i++) {
		scanf("%d %d %d", &people[i].id, &people[i].virtue, &people[i].talent);
		if ((people[i].virtue < lower) || (people[i].talent < lower))	// not qualified to be ranked
			continue;
		if ((people[i].virtue >= upper) && (people[i].talent >= upper))	// sage
			people_valids[0].push_back(people + i);
		else if (people[i].virtue >= upper)								// nobleman
			people_valids[1].push_back(people + i);
		else if (people[i].virtue >= people[i].talent)					// fool
			people_valids[2].push_back(people + i);
		else															// small man
			people_valids[3].push_back(people + i);
	}
	printf("%d\n", people_valids[0].size() + people_valids[1].size() + people_valids[2].size() + people_valids[3].size());
	for (int i = 0; i < 4; i++) {
		sort(people_valids[i].begin(), people_valids[i].end(), cmp);
		for (int j = 0; j < people_valids[i].size(); j++)	
			printf("%08d %d %d\n", people_valids[i][j]->id, people_valids[i][j]->virtue, people_valids[i][j]->talent);
	}

	return 0;
}