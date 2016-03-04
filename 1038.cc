#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) { return a + b < b + a; }

int idx_nonzero(string num) {
	for (int i = 0; i < num.size(); i++)
		if (num[i] != '0')
			return i;
	return num.size();
}

int main() {
	int num_segment;
	scanf("%d", &num_segment);
	string *segments = new string[num_segment];
	for (int i = 0; i < num_segment; i++) {
		char segment[16];
		scanf("%s", segment);
		segments[i] = segment;
	}
	sort(segments, segments + num_segment, compare);

	bool print = false;
	for (int i = 0; i < num_segment; i++) {
		if (print)
			printf("%s", segments[i].c_str());
		else {
			int idx = idx_nonzero(segments[i]);
			if (idx < segments[i].size()) {
				printf("%s", segments[i].substr(idx).c_str());
				print = true;
			}
		}
	}
	if (!print)
		printf("0");

	return 0;
}