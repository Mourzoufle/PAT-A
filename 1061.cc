#include <iostream>
#include <cstdio>

using namespace std;

string DAYS[] = {
	"MON ",
	"TUE ",
	"WED ",
	"THU ",
	"FRI ",
	"SAT ",
	"SUN "
};

int main() {
	string codes[4];
	for (int i = 0; i < 4; i++)
		cin >> codes[i];
	int idx = 0;
	while ((codes[0][idx] < 'A') || (codes[0][idx] > 'G') || (codes[0][idx] != codes[1][idx]))
		idx++;
	cout << DAYS[codes[0][idx] - 'A'];
	while (true) {
		if (codes[0][++idx] != codes[1][idx])
			continue;
		else if ((codes[0][idx] >= 'A') && (codes[0][idx] <= 'N')) {
			printf("%d:", codes[0][idx] - 'A' + 10);
			break;
		}
		else if ((codes[0][idx] >= '0') && (codes[0][idx] <= '9')) {
			printf("0%d:", codes[0][idx] - '0');
			break;
		}
	}
	for (int i = 0; i < codes[2].length(); i++) {
		if (codes[2][i] != codes[3][i])
			continue;
		else if (((codes[2][i] >= 'A') && (codes[2][i] <= 'Z')) || ((codes[2][i] >= 'a') && (codes[2][i] <= 'z'))) {
			printf("%02d", i);
			break;
		}
	}

	return 0;
}