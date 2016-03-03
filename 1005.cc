#include <cstdio>
#include <vector>

using namespace std;

const char SPELLS[][8] = {
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
};

int main() {
	char num[128];
	scanf("%s", num);
	int sum = 0;
	for (int i = 0; num[i] != '\0'; i++)
		sum += num[i] - '0';

	vector<int> digits;	// the digits - from the lowest to the highest
	while (sum > 0) {
		digits.push_back(sum % 10);
		sum /= 10;
	}
	if (digits.empty())	// if the sum is zero
		digits.push_back(0);
	printf("%s", SPELLS[digits.back()]);
	for (int i = digits.size() - 2; i >= 0; i--)
		printf(" %s", SPELLS[digits[i]]);

	return 0;
}