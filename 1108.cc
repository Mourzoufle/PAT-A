#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAX_LENGTH = 1 << 16;

bool is_valid(char *str, double &num) {
	int idx_dot = -1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '-') {
			if (i > 0)
				return false;
		}
		else if (str[i] == '.') {
			if (idx_dot < 0)
				idx_dot = i;
			else
				return false;
		}
		else if ((str[i] < '0') || (str[i] > '9'))
			return false;
	}
	if ((idx_dot >= 0) && (strlen(str) - idx_dot) > 3)
		return false;
	num = atof(str);
	return (num >= -1000) && (num <= 1000);
}

int main() {
	int num_num, num_valid = 0;
	double sum = 0;
	scanf("%d", &num_num);
	for (int i = 0; i < num_num; i++) {
		char *str = new char[MAX_LENGTH];
		scanf("%s", str);
		double num;
		if (is_valid(str, num)) {
			sum += num;
			num_valid++;
		}
		else
			printf("ERROR: %s is not a legal number\n", str);
		delete[] str;
	}
	if (num_valid == 0)
		printf("The average of 0 numbers is Undefined");
	else if (num_valid == 1)
		printf("The average of 1 number is %.2lf", sum);
	else
		printf("The average of %d numbers is %.2lf", num_valid, sum / num_valid);

	return 0;
}