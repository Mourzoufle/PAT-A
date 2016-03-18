#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_STUDENT = 26 * 26 * 26 * 10;						// max number of students (since each of them is represented by three capital letters and one digit)

/* map each string of name to an integer */
int str_to_num(char *str) { return (str[0] - 'A') * 6760 + (str[1] - 'A') * 260 + (str[2] - 'A') * 10 + str[3] - '0'; }

int main() {
	int num_student, num_course;
	scanf("%d %d", &num_student, &num_course);
	vector<int> *courses_reg = new vector<int>[MAX_STUDENT];	//  list of courses each student registers
	for (int i = 0; i < num_course; i++) {
		int course, num_reg;
		scanf("%d %d", &course, &num_reg);
		for (int j = 0; j < num_reg; j++) {
			char student[8];
			scanf("%s", student);
			courses_reg[str_to_num(student)].push_back(course);
		}
	}

	for (int i = 0; i < MAX_STUDENT; i++)
		if (!courses_reg[i].empty())
			sort(courses_reg[i].begin(), courses_reg[i].end());	// the coursed will be listed according to their indices
	for (int i = 0; i < num_student; i++) {
		char student[8];
		scanf("%s", student);
		int idx_student = str_to_num(student);
		printf("%s %d", student, courses_reg[idx_student].size());
		for (int j = 0; j < courses_reg[idx_student].size(); j++)
			printf(" %d", courses_reg[idx_student][j]);
		printf("\n");
	}

	return 0;
}