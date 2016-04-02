#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	char str[16384];
	scanf("%s", str);

	if (str[0] == '-')					// print the minus sign
		printf("-");

	int expon, idx = 3;					// the exponent of the number; the index of the exponent notification
	while (str[idx++] != 'E');
	expon = atoi(str + idx);
	str[--idx] = '\0';					// the exponent part is no longer needed
	if (expon < 0) {					// number less than 1
		printf("0.");
		for (int i = -1; i > expon; i--)
			printf("0");
		printf("%c%s", str[1], str + 3);
	}
	else {								// number no less than 1
		printf("%c", str[1]);
		if (expon < strlen(str + 3)) {	// the number has fractional part
			for (int i = 0; i < expon; i++)
				printf("%c", str[i + 3]);
			printf(".%s", str + expon + 3);
		}
		else {							// the number has no fractional part, may add zero to the tail of it
			printf("%s", str + 3);
			for (int i = strlen(str + 3); i < expon; i++)
				printf("0");
		}
	}

	return 0;
}