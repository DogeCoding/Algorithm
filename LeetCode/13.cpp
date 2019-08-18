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

int romanToInt(string s) {
	unordered_map<char, int>map;
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;
	int ans = 0;
	int i;
	for (i = 0; i < s.length() - 1; i++) {
		if (map[s[i]] < map[s[i+1]]) {
			ans += map[s[i+1]] - map[s[i]];
			i++;
		} else {
			ans += map[s[i]];
		}
	}
	if (i == s.length() - 1) {
		ans += map[s[i]];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}