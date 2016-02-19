#include <iostream>

using namespace std;

int main() {
	string sell, buy;
	cin >> sell >> buy;
	int sells[256], buys[256];
	for (int i = 0; i < 256; i++) {
		sells[i] = 0;
		buys[i] = 0;
	}
	for (int i = 0; i < sell.size(); i++)
		sells[sell[i]]++;
	for (int i = 0; i < buy.size(); i++)
		buys[buy[i]]++;
	int diff = 0;
	for (int i = 0; i < 256; i++)
		if (sells[i] < buys[i])
			diff += buys[i] - sells[i];
	if (diff == 0)
		cout << "Yes " << sell.size() - buy.size();
	else
		cout << "No " << diff;

	return 0;
}