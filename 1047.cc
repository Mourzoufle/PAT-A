#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int num_student, num_course;
	scanf("%d %d", &num_student, &num_course);
	vector<string> *regs = new vector<string>[num_course];
	for (int i = 0; i < num_student; i++) {
		char student[5];
		int num_reg;
		scanf("%s %d", student, &num_reg);
		for (int j = 0; j < num_reg; j++) {
			int course;
			scanf("%d", &course);
			regs[--course].push_back(student);
		}
	}
	for (int i = 0; i < num_course; i++) {
		printf("%d %d\n", i + 1, regs[i].size());
		sort(regs[i].begin(), regs[i].end());
		for (vector<string>::iterator iter = regs[i].begin(); iter != regs[i].end(); iter++)
			printf("%s\n", iter->c_str());
	}

	return 0;
}