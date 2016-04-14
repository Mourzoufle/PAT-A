#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_FAMILY = 10000;

struct Family {
	int first;								// first member of the family
	int num_person;
	int estate;								// total estates
	int area;								// total area of the estates

	Family(): num_person(1), estate(0), area(0) {}
};

/* Union-Find Sets - merge the families that a and b belong to, and update the first member of the family */
void merge(Family *families, int a, int b, int estate = 0, int area = 0) {
	int first_a = a, first_b = b;
	while (families[first_a].first != first_a)
		first_a = families[first_a].first;
	while (families[first_b].first != first_b)
		first_b = families[first_b].first;
	int first = min(first_a, first_b);
	while (families[a].first != first) {	// path compression of a and b
		int tmp = families[a].first;
		families[a].first = first;
		a = tmp;
	}
	while (families[b].first != first) {
		int tmp = families[b].first;
		families[b].first = first;
		b = tmp;
	}
	if (first_a != first_b) {				// a and b belong to different families - merge them
		families[first].num_person = families[first_a].num_person + families[first_b].num_person;
		families[first].estate = families[first_a].estate + families[first_b].estate;
		families[first].area = families[first_a].area + families[first_b].area;
	}
	families[first].estate += estate;
	families[first].area += area;
}

/* compare function for sorting families - first according to the average area, then the IDs of the first members if there is a tie */
bool cmp(Family *a, Family *b) {
	double avg_area_a = 1.0 * a->area / a->num_person, avg_area_b = 1.0 * b->area / b->num_person;
	if (avg_area_a != avg_area_b)
		return avg_area_a > avg_area_b;
	return a->first < b->first;
}

int main() {
	Family *families = new Family[MAX_FAMILY];
	for (int i = 0; i < MAX_FAMILY; i++)
		families[i].first = i;
	int num_person;
	scanf("%d", &num_person);
	for (int i = 0; i < num_person; i++) {
		int person, father, mother, num_child, estate, area;
		scanf("%d %d %d %d", &person, &father, &mother, &num_child);
		int *children = new int[num_child];
		for (int j = 0; j < num_child; j++)
			scanf("%d", &children[j]);
		scanf("%d %d", &estate, &area);
		merge(families, person, person, estate, area);
		if (father >= 0)
			merge(families, person, father);
		if (mother >= 0)
			merge(families, person, mother);
		for (int j = 0; j < num_child; j++)
			merge(families, person, children[j]);
		delete[] children;		
	}

	vector<Family *> families_valid;		// true families - i.e., the members who are the first of their families
	for (int i = 0; i < MAX_FAMILY; i++)
		if ((families[i].first == i) && (families[i].estate > 0))
			families_valid.push_back(families + i);
	sort(families_valid.begin(), families_valid.end(), cmp);
	printf("%d\n", families_valid.size());
	for (int i = 0; i < families_valid.size(); i++)
		printf("%04d %d %.3lf %.3lf\n", families_valid[i]->first, families_valid[i]->num_person, 1.0 * families_valid[i]->estate / families_valid[i]->num_person, 1.0 * families_valid[i]->area / families_valid[i]->num_person);

	return 0;
}