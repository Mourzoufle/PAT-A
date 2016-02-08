#include <iostream>

using namespace std;

int main() {
	string id_in, id_out, first = "24:00:00", last = "00:00:00";
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string id, in, out;
		cin >> id >> in >> out;
		if (in < first) {
			id_in = id;
			first = in;
		}
		if (out > last) {
			id_out = id;
			last = out;
		}
	}
	cout << id_in << " " << id_out;

	return 0;
}