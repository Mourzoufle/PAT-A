#include <cstdio>
#include <string>

using namespace std;

const string DIGITS[] = {		// spell of each digit
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

/* get the spell of part of the number (in 10000) */
string get_spell(int num, bool has_higher_digit, const string suffix) {
	if (num == 0)
		return "";

	string spell;
	int qian = num / 1000, bai = (num % 1000) / 100, shi = (num % 100) / 10, ge = num % 10;
	if (qian > 0)
		spell += DIGITS[qian] + " Qian";
	else if (has_higher_digit)	// lower than 1000 and there are digits higher than this part of the number
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
	return spell + suffix;
}

int main() {
	int num;
	scanf("%d", &num);

	string spell;				// spell of the number
	if (num < 0) {
		spell += " Fu";
		num = -num;
	}
	int yi = num / 100000000, wan = (num % 100000000) / 10000, ge = num % 10000;
	if (yi > 0)
		spell += DIGITS[yi] + " Yi";
	spell += get_spell(wan, yi > 0, " Wan") + get_spell(ge, num > 9999, "");
	if (spell.empty())
		spell = DIGITS[0];
	printf("%s", spell.substr(1).c_str());

	return 0;
}