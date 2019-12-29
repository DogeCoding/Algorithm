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

int lengthOfLastWord(string s) {
	int max = 0;
	int last = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') max++;
		else {
			if (!max) {
				last = max;
				max = 0;
			}
		} 
	}
	return max;
}

int main(int argc, char const *argv[]) {
	
	return 0;
}