#include <iostream>
#include <cstdio>

using namespace std;

const string RES[] = {
	"W ",
	"T ",
	"L "
};

int main() {
	double profit = 1;
	double *odds = new double[3];
	for (int i = 0; i < 3; i++) {
		int idx = 0;
		for (int j = 0; j < 3; j++) {
			cin >> odds[j];
			if (odds[idx] < odds[j])
				idx = j;
		}
		profit *= odds[idx];
		cout << RES[idx];
	}
	printf("%.2lf", (profit * 0.65 - 1) * 2);

	return 0;
}