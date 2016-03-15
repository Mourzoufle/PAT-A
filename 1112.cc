#include <cstdio>

const int MAX_LENGTH = 1024;

int main() {
	int indices_check[256];
	for (int j = 0; j < 256; j++)
		indices_check[j] = 0;
	int num_repeat, num_check = 0;
	char str[MAX_LENGTH];
	scanf("%d\n%s", &num_repeat, str);

	for (int i = 0; str[i] != '\0'; i++) {
		int cur_repeat = 1;
		while (str[i] == str[i + 1]) {
			cur_repeat++;
			i++;
		}
		if (cur_repeat % num_repeat > 0) {
			if (indices_check[str[i]] > 0)
				indices_check[str[i]] = -1;
		}
		else {
			if (indices_check[str[i]] == 0)
				indices_check[str[i]] = ++num_check;
		}
	}
	for (int i = 1; i <= num_check; i++)
		for (int j = 0; j < 256; j++)
			if (indices_check[j] == i)
				printf("%c", j);
	printf("\n");
	for (int i = 0; str[i] != '\0'; i++) {
		printf("%c", str[i]);
		if (indices_check[str[i]] > 0)
			i += num_repeat - 1;
	}

	return 0;
}