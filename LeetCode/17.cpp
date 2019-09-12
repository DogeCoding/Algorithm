#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> letterCombinations(string digits) {
	if (digits.empty()) return {};
	unordered_map<char, string > map = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
	string combinations(digits.length(), ' ');
	vector<string> results;
	letterCombinations(digits, combinations, 0, map, results);
	return results;
}

void letterCombinations(string digits, string &combinations, int index, unordered_map<char, string> map, vector<string> &results) {
	if (index == digits.length()) {
		results.push_back(combinations);
		return ;
	}
	for (char c : map[digits[index]]) {
		combinations[index] = c;
		letterCombinations(digits, combinations, index+1, map, results);
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}