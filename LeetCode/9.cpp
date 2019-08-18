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

bool isPalindrome(int x) {
	if (x < 0) return false;
	string str = to_string(x);
	int length = str.length();
	for (int i = 0; i < length / 2; i++) {
		if (str[i] == str[length - 1 - i])
			continue;
		else 
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	isPalindrome(1234);
	return 0;
}