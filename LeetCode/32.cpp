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

int longestValidParentheses(string s) {
	int length = s.size();
	if (!length) return 0;
	int dp[length], max[length];
	memset(dp, 0, sizeof(int) * length);
	memset(max, 0, sizeof(int) * length);
	dp[0] = s[0] == '(' ? 1 : 0;
	max[0] = dp[0] ? : 0;
	for (int i = 1; i < length; i++) {
		if (s[i] == '(') {
			dp[i] = dp[i-1] + 1;
		} else {
			dp[i] = dp[i-1] - 1;
		}
		max[i] = max[i-1] + 1;
		if (dp[i] < 0) {
			dp[i] = 0;
			max[i] = 0;
		}
	}
	for (int i = 0; i < length; i++) {
		cout << dp[i] << "   " << max[i] << endl;
	}
	int temp = 0;
	if (dp[length - 1] != 0) {
		for (int i = length - 1; i >= 0; i--) {
			if (!dp[i]) {
				temp = max[i];
				break;
			}
		}
		cout << temp << endl;
	}
	
	max[length - 1] = max[length - 1] - temp - dp[length - 1];
	int ans = 0;
	for (int i = 0; i < length; i++) {
		if (max[i] > ans) ans = max[i];
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	cout << longestValidParentheses("()(()") << endl;
	return 0;
}