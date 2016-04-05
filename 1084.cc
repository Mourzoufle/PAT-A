#include <cstdio>

int main() {
	bool check[256];						// flag indicating if each key is checked to be broken
	for (int i = 0; i < 256; i++)
		check[i] = false;
	char origin[128], out[128];				// the original string; the typed-out string
	scanf("%s\n%s", origin, out);

	int idx = 0;							// index of character in the typed-out string that is currently under processing
	for (int i = 0; origin[i] != '\0'; i++) {
		if (origin[i] == out[idx])
			idx++;
		else {
			char c = origin[i];
			if ((c >= 'a') && (c <= 'z'))	// capitalized
				c += 'A' - 'a';
			if (!check[c]) {				// first time this key is checked - print it
				putchar(c);
				check[c] = true;
			}
		}
	}

	return 0;
}