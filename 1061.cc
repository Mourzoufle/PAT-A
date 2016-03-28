#include <cstdio>

const char DAYS[][4] = {
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};

int main() {
	char strs[4][64];																														// the strings
	for (int i = 0; i < 4; i++)
		scanf("%s", strs[i]);

	int idx = 0;																															// the index of current char
	while ((strs[0][idx] < 'A') || (strs[0][idx] > 'G') || (strs[0][idx] != strs[1][idx]))													// find a common capital letter in the first two strings
		idx++;
	printf("%s ", DAYS[strs[0][idx] - 'A']);
	while (++idx) {
		if (strs[0][idx] == strs[1][idx]) {																									// find next common character in the first two strings
			if ((strs[0][idx] >= 'A') && (strs[0][idx] <= 'N'))
				printf("%d:", strs[0][idx] - 'A' + 10);
			else if ((strs[0][idx] >= '0') && (strs[0][idx] <= '9'))
				printf("0%d:", strs[0][idx] - '0');
			else																															// not indicates the hour, continue to find
				continue;
			break;
		}
	}
	for (int i = 0; strs[2][i] != '\0'; i++) {
		if ((strs[2][i] == strs[3][i]) && (((strs[2][i] >= 'A') && (strs[2][i] <= 'Z')) || ((strs[2][i] >= 'a') && (strs[2][i] <= 'z')))) {	// find a common English letter in the last two strings
			printf("%02d", i);
			break;
		}
	}

	return 0;
}