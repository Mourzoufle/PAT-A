#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int num_student, num_course;
	scanf("%d %d", &num_student, &num_course);
	vector<string> *students_regs = new vector<string>[num_course];	// registered students of each course
	for (int i = 0; i < num_student; i++) {
		char student[8];
		int num_reg;
		scanf("%s %d", student, &num_reg);
		for (int j = 0; j < num_reg; j++) {
			int course;
			scanf("%d", &course);
			students_regs[--course].push_back(student);
		}
	}

	for (int i = 0; i < num_course; i++) {
		sort(students_regs[i].begin(), students_regs[i].end());
		printf("%d %d\n", i + 1, students_regs[i].size());
		for (int j = 0; j < students_regs[i].size(); j++)
			printf("%s\n", students_regs[i][j].c_str());
	}

	return 0;
}