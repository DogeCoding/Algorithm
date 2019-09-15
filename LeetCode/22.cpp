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

void generateAll(string &combination, int index, vector<string> &results);
bool valid(string str);

vector<string> generateParenthesis(int n) {
	vector<string> ans;
	string str(2*n, ' ');
	generateAll(str, 0, ans);
	return ans;
}

void generateAll(string &combination, int index, vector<string> &results) {
	if (index == combination.length()) {
		if (valid(combination)) {
			results.push_back(combination);
		}
	} else {
		combination[index] = '(';
	generateAll(combination, index+1, results);
	combination[index] = ')';
	generateAll(combination, index+1, results);
	}
}

bool valid(string str) {
	int balance = 0;
	for (char c : str) {
		if (c == '(') balance++;
		else balance--;
		if (balance < 0) return false;
	}
	return (balance == 0);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}