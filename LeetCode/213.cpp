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

int rob(vector<int>& nums) {
	int length = nums.size();
	if (length < 2) return 0;
	int dp1[length], dp2[length];
	dp1[0] = nums[0];	// 偷第一间房子
	dp1[1] = dp1[0];
	dp2[0] = 0;
	dp2[1] = nums[1];
	for (int i = 2; i < length; i++) {
		dp1[i] = max(dp1[i-2]+nums[i], dp1[i-1]);
		dp2[i] = max(dp2[i-2]+nums[i], dp2[i-1]);
	}
	return max(dp1[length-2], dp2[length-1]);
}


int main(int argc, char const *argv[])
{
	
	return 0;
}