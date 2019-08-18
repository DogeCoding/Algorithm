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

bool isPalindrome(string s) {
	int len = s.size();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) return false;
	}
	return true;
}

string longestPalindrome(string s) {
	int len = s.size();
	int maxIndex = 0, max = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (isPalindrome(s.substr(i, j - i + 1))) {
				if (j - i + 1 > max){
					max = j-i+1;
					maxIndex = j;
				}
			}
		}
	}
	return s.substr(maxIndex - max + 1, max);
}

string longestPalindrome(string s) {
	int length = s.size();
	if (!length) return "";
	if (length == 1) return s;
	int dp[length][length];
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (i >= j) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	int maxLen = 1;
	int tl = 0, tr = 0;
	for (int k = 1; k < length; k++) {
		for (int i = 0; k + i < length; i++) {
			int j = i + k;
			if (s[i] != s[j]) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = dp[i+1][j-1];
				if (dp[i][j]) {
					if (k + 1 > maxLen) {
						maxLen = k + 1;
						tl = i;
						tr = j;
					}
				}
			}
		}
	}
	return s.substr(tl, tr - tl + 1);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}