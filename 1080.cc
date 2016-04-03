#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Applicant {
	int idx;
	int grade_e;																												// national entrance exam grade
	int grade_i;																												// interview grade
	vector<int> schools;																										// schools the applicant preferred
};

/* compare fuction for sorting applicants - first according to the final grade, then sorted by the national entrance exam grade if there is a tie */
bool cmp(const Applicant &a, const Applicant &b) {
	if (a.grade_e + a.grade_i != b.grade_e + b.grade_i)
		return a.grade_e + a.grade_i > b.grade_e + b.grade_i;
	return a.grade_e > b.grade_e;
}

int main() {
	int num_applicant, num_school, num_choice;
	scanf("%d %d %d", &num_applicant, &num_school, &num_choice);
	int *quotas = new int[num_school];																							// quota of each school
	for (int i = 0; i < num_school; i++)
		scanf("%d", &quotas[i]);
	Applicant *applicants = new Applicant[num_applicant];
	for (int i = 0; i < num_applicant; i++) {
		applicants[i].idx = i;
		scanf("%d %d", &applicants[i].grade_e, &applicants[i].grade_i);
		for (int j = 0; j < num_choice; j++) {
			int school;
			scanf("%d", &school);
			applicants[i].schools.push_back(school);
		}
	}
	sort(applicants, applicants + num_applicant, cmp);

	vector<int> *admissions = new vector<int>[num_school];																		// admissions of each school
	for (int i = 0; i < num_applicant; i++) {
		for (int j = 0; j < num_choice; j++) {
			int school = applicants[i].schools[j];
			if ((admissions[school].size() < quotas[school]) || !cmp(applicants[admissions[school].back()], applicants[i])) {	// if the school is still available or the applicant ties against the last one in the admissions
				admissions[school].push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < num_school; i++) {
		if (admissions[i].empty()) {
			printf("\n");
			continue;
		}
		for (int j = 0; j < admissions[i].size(); j++)
			admissions[i][j] = applicants[admissions[i][j]].idx;																// replace the rank of each applicant with the index
		sort(admissions[i].begin(), admissions[i].end());
		for (int j = 0; j < admissions[i].size() - 1; j++)
			printf("%d ", admissions[i][j]);
		printf("%d\n", admissions[i].back());
	}

	return 0;
}