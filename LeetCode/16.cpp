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

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3) return 0;
	int closest = nums[0] + nums[1] + nums[2];
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++) {
		if (i > 0 && nums[i] == nums[i+1]) continue;
		int left = i+1, right = nums.size() - 1;
		while (left < right) {
			if (nums[i] + nums[left] + nums[right] == target) {
				return target;
			}
			if (abs(nums[i]+nums[left]+nums[right]-target) < abs(closest-target)) {
				closest = nums[i]+nums[left]+nums[right];
			}
			if (nums[i]+nums[left]+nums[right] > target) --right;
			else ++left;
		}
	} 
	return closest;       
}

int main(int argc, char const *argv[])
{
	
	return 0;
}