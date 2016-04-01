#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

int main() {
	string cur_word;					// current word
	map<string, int> counts_word;		// frequency of each word
	for (char c = tolower(getchar()); (c != '\0') && (c != EOF); c = tolower(getchar())) {
		if (((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')))
			cur_word += c;
		else if (!cur_word.empty()) {	// current word is full read
			if (counts_word.find(cur_word) == counts_word.end())
				counts_word[cur_word] = 1;
			else
				counts_word[cur_word]++;
			cur_word = "";
		}
	}
	if (!cur_word.empty()) {
		if (counts_word.find(cur_word) == counts_word.end())
			counts_word[cur_word] = 1;
		else
			counts_word[cur_word]++;
	}
	for (map<string, int>::iterator iter = counts_word.begin(); iter != counts_word.end(); iter++)
		if (cur_word.empty() || (counts_word[cur_word] < iter->second))
			cur_word = iter->first;
	printf("%s %d", cur_word.c_str(), counts_word[cur_word]);

	return 0;
}