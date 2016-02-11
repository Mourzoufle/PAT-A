#include <iostream>
#include <string>

using namespace std;

const string DIGITS[] = {
	" ling",
	" yi",
	" er",
	" san",
	" si",
	" wu",
	" liu",
	" qi",
	" ba",
	" jiu"
};

void get_spell(string &spell, bool add_ling, int num) {
	int qian = num / 1000, bai = (num % 1000) / 100, shi = (num % 100) / 10, ge = num % 10;
	if (qian > 0)
		spell += DIGITS[qian] + " Qian";
	else if (add_ling)
		spell += DIGITS[0];
	if (bai > 0)
		spell += DIGITS[bai] + " Bai";
	else if ((qian > 0) && ((shi > 0) || (ge > 0)))
		spell += DIGITS[0];
	if (shi > 0)
		spell += DIGITS[shi] + " Shi";
	else if ((bai > 0) && (ge > 0))
		spell += DIGITS[0];
	if (ge > 0)
		spell += DIGITS[ge];
}

int main() {
	int num;
	cin >> num;
	string spell;
	if (num < 0) {
		spell += " Fu";
		num = -num;
	}
	int yi = num / 100000000, wan = (num % 100000000) / 10000, ge = num % 10000;
	if (yi > 0)
		spell += DIGITS[yi] + " Yi";
	if (wan > 0) {
		get_spell(spell, yi > 0, wan);
		spell += " Wan";
	}
	if (ge > 0)
		get_spell(spell, (yi > 0) || (wan > 0), ge);
	if (num == 0)
		spell += DIGITS[0];
	cout << spell.substr(1);

	return 0;
}