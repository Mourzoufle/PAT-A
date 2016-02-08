#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string spells[] = {
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
	stack<int> digits;
	while (sum > 0) {
		digits.push(sum % 10);
		sum /= 10;
	}
	if (digits.size() == 0)
		digits.push(0);
	while (true) {
		printf("%s", spells[digits.top()].c_str());
		digits.pop();
		if (digits.size() > 0)
			printf(" ");
		else
			return 0;
	}
}