#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

/* compare fuction for segments - if the combining segments as {ab} is smaller than {ba}, then sort a in the front of b */
bool cmp(const string &a, const string &b) { return a + b < b + a; }

/* find the index of the first nonzero number in the segment */
int get_idx_nonzero(string num) {
	for (int i = 0; i < num.size(); i++)
		if (num[i] != '0')
			return i;
	return -1;												// if all the numbers in the segments are zeros, return -1
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
	sort(segments, segments + num_segment, cmp);

	bool print = false;										// flag indicating if there is a nonzero number is found and printed
	for (int i = 0; i < num_segment; i++) {
		if (print)											// if there is already a nonzero number printed, just print this segment
			printf("%s", segments[i].c_str());
		else {
			int idx_nonzero = get_idx_nonzero(segments[i]);	// or find the first nonzero number in this segment
			if (idx_nonzero >= 0) {							// if a nonzero number is found, then print part of the segment starting from the number
				printf("%s", segments[i].substr(idx_nonzero).c_str());
				print = true;
			}
		}
	}
	if (!print)												// if all the numbers in the segments are zeros, just print 0
		printf("0");

	return 0;
}