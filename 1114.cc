#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_FAMILY = 10000;

struct Family {
	int first;
	int num_person;
	int estate;
	int area;

	Family(): num_person(1), estate(0), area(0) {}
};

void merge(Family *familys, int a, int b, int estate = 0, int area = 0) {
	int first_a = a, first_b = b;
	while (familys[first_a].first != first_a)
		first_a = familys[first_a].first;
	while (familys[first_b].first != first_b)
		first_b = familys[first_b].first;
	int first = (first_a < first_b ? first_a : first_b);
	while (familys[a].first != first) {
		int tmp = familys[a].first;
		familys[a].first = first;
		a = tmp;
	}
	while (familys[b].first != first) {
		int tmp = familys[b].first;
		familys[b].first = first;
		b = tmp;
	}
	if (first_a != first_b) {
		familys[first].num_person = familys[first_a].num_person + familys[first_b].num_person;
		familys[first].estate = familys[first_a].estate + familys[first_b].estate;
		familys[first].area = familys[first_a].area + familys[first_b].area;
	}
	familys[first].estate += estate;
	familys[first].area += area;
}

bool cmp(Family *a, Family *b) {
	double avg_area_a = 1.0 * a->area / a->num_person, avg_area_b = 1.0 * b->area / b->num_person;
	if (avg_area_a != avg_area_b)
		return avg_area_a > avg_area_b;
	return a->first < b->first;
}

int main() {
	Family *familys = new Family[MAX_FAMILY];
	for (int i = 0; i < MAX_FAMILY; i++)
		familys[i].first = i;
	int num_person;
	scanf("%d", &num_person);
	for (int i = 0; i < num_person; i++) {
		int person, father, mother, num_child, estate, area;
		scanf("%d %d %d %d", &person, &father, &mother, &num_child);
		int *children = new int[num_child];
		for (int j = 0; j < num_child; j++)
			scanf("%d", &children[j]);
		scanf("%d %d", &estate, &area);
		merge(familys, person, person, estate, area);
		if (father >= 0)
			merge(familys, person, father);
		if (mother >= 0)
			merge(familys, person, mother);
		for (int j = 0; j < num_child; j++)
			merge(familys, person, children[j]);
		delete[] children;		
	}

	vector<Family *> familys_valid;
	for (int i = 0; i < MAX_FAMILY; i++)
		if ((familys[i].first == i) && (familys[i].estate > 0))
			familys_valid.push_back(familys + i);
	sort(familys_valid.begin(), familys_valid.end(), cmp);
	printf("%d\n", familys_valid.size());
	for (int i = 0; i < familys_valid.size(); i++)
		printf("%04d %d %.3lf %.3lf\n", familys_valid[i]->first, familys_valid[i]->num_person, 1.0 * familys_valid[i]->estate / familys_valid[i]->num_person, 1.0 * familys_valid[i]->area / familys_valid[i]->num_person);

	return 0;
}