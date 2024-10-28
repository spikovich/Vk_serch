

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_map>



/**
 * @brief Compares two strings to determine if they are isomorphic.
 *
 * Two strings s1 and s2 are isomorphic if the characters in s1 can be replaced to get s2.
 * No two characters may map to the same character, but a character may map to itself.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return true if the strings are isomorphic, false otherwise.
 */

bool compare(const std::string& s1, const std::string& s2)
{
	if (s1.size() != s2.size() || s1.empty() || s2.empty()) {
		return false;
	}
	std::unordered_map<char, char> letters, used;
	for (int i = 0; i < s1.size(); ++i) {
		if (letters.count(s1[i]) == 0) {
			if (used.count(s2[i]) == 0) {
				letters[s1[i]] = s2[i];
				used[s2[i]] = s1[i];
			} else {
				return false;
			}
		} else {
			if (letters[s1[i]] != s2[i]) {
				return false;
			}
		}
	}
	return true;
}

void do_test(const std::string& s1, const std::string& s2)
{
	bool result = compare(s1, s2);
	printf("\n'%s' : '%s' -> '%s'\n", s1.c_str(), s2.c_str(), result ? "true" : "false");
}

int main()
{
	do_test("egg", "add");
	do_test("foo", "bar");
	do_test("paper", "title");

	do_test("foooww", "baaarr!");
	do_test("fxooowf", "baaarr");
	do_test("fxooowf", "byaaary");

	getchar();
}

