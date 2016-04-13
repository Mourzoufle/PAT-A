#include <cstdio>

const int MAX_LENGTH = 1024;

int main() {
	int indices_stucked[256];				// index of each ASCII character whose corresponding key is -1: normal; 0: unchecked; > 0: stucked
	for (int i = 0; i < 256; i++)
		indices_stucked[i] = 0;
	int num_repeat, num_check = 0;
	char str[MAX_LENGTH];
	scanf("%d\n%s", &num_repeat, str);

	int idx = -1;							// index of the character under checking
	while (str[++idx] != '\0') {
		int cur_repeat = 1;
		while (str[idx] == str[idx + 1]) {
			cur_repeat++;
			idx++;
		}
		if (cur_repeat % num_repeat > 0)	// this key is normal
				indices_stucked[str[idx]] = -1;
		else if (indices_stucked[str[idx]] == 0)
			indices_stucked[str[idx]] = ++num_check;
	}
	for (int i = 1; i <= num_check; i++)
		for (int j = 0; j < 256; j++)
			if (indices_stucked[j] == i)
				printf("%c", j);
	printf("\n");
	for (int i = 0; str[i] != '\0'; i++) {
		printf("%c", str[i]);
		if (indices_stucked[str[i]] > 0)	// then omit num_repeat occurrance of this character but one
			i += num_repeat - 1;
	}

	return 0;
}