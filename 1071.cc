#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
	char str[1 << 21];
	gets(str);
	string cur;
	map<string, int> counts;
	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] += 'a' - 'A';
		if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= '0') && (str[i] <= '9')))
			cur += str[i];
		else if (!cur.empty()) {
			if (counts.find(cur) == counts.end())
				counts[cur] = 1;
			else
				counts[cur]++;
			cur = "";
		}
	}
	if (!cur.empty()) {
		if (counts.find(cur) == counts.end())
			counts[cur] = 1;
		else
			counts[cur]++;
	}

	for (map<string, int>::iterator iter = counts.begin(); iter != counts.end(); iter++)
		if (cur.empty() || (counts[cur] < iter->second))
			cur = iter->first;
	printf("%s %d", cur.c_str(), counts[cur]);

	return 0;
}