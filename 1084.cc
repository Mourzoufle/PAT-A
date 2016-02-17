#include <iostream>

using namespace std;

int main() {
	string ori, cur, keys;
	cin >> ori >> cur;
	int idx_ori = 0, idx_cur = 0;
	while (idx_ori < ori.size()) {
		if (ori[idx_ori] == cur[idx_cur])
			idx_cur++;
		else {
			if ((ori[idx_ori] >= 'a') && (ori[idx_ori] <= 'z'))
				ori[idx_ori] += 'A' - 'a';
			bool detect = false;
			for (int i = 0; i < keys.size(); i++) {
				if (keys[i] == ori[idx_ori]) {
					detect = true;
					break;
				}
			}
			if (!detect)
				keys += ori[idx_ori];
		}
		idx_ori++;
	}
	cout << keys;

	return 0;
}