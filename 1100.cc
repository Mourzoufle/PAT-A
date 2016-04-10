#include <cstdio>
#include <cstring>
#include <cstdlib>

const char SPELLS[][8] = {
	"tret",
	"jan",
	"feb",
	"mar",
	"apr",
	"may",
	"jun",
	"jly",
	"aug",
	"sep",
	"oct",
	"nov",
	"dec",
	"tam",
	"hel",
	"maa",
	"huh",
	"tou",
	"kes",
	"hei",
	"elo",
	"syy",
	"lok",
	"mer",
	"jou"
};

int main() {
	int num_num;									// number of given numbers
	scanf("%d\n", &num_num);
	for (int i = 0; i < num_num; i++) {
		char str[16];
		gets(str);
		if ((str[0] >= '0') && (str[0] <= '9')) {	// an Earth number
			int num = atoi(str);
			if (num > 12) {							// has higher digit
				printf("%s", SPELLS[num / 13 + 12]);
				if (num % 13 > 0)
					printf(" %s", SPELLS[num % 13]);
				printf("\n");
			}
			else
				printf("%s\n", SPELLS[num]);
		}
		else {										// a Mars number
			int num = 0;
			if (strlen(str) > 4) {					// the number contains two spells
				int idx = -1;
				while (str[++idx] != ' ');
				str[idx] = '\0';
				for (int i = 13; i < 25; i++) {
					if (strcmp(str, SPELLS[i]) == 0) {
						num = (i - 12) * 13;
						break;
					}
				}
				for (int i = 0; i < 13; i++) {
					if (strcmp(str + idx + 1, SPELLS[i]) == 0) {
						num += i;
						break;
					}
				}
			}
			else {									// the number contains only one spell
				for (int i = 0; i < 25; i++) {
					if (strcmp(str, SPELLS[i]) == 0) {
						num = (i > 13 ? (i - 12) * 13 : i);
						break;
					}
				}
			}
			printf("%d\n", num);
		}
	}

	return 0;
}