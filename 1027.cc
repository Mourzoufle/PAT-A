#include <cstdio>

int main() {
	printf("#");
	for (int i = 0; i < 3; i++) {
		int num;
		scanf("%d", &num);
		if (num >= 130)							// the first digit > 9
			printf("%c", num / 13 + 'A' - 10);
		else
			printf("%d", num / 13);
		num %= 13;
		if (num >= 10)							// the second digit > 9
			printf("%c", num + 'A' - 10);
		else
			printf("%d", num);
	}

	return 0;
}