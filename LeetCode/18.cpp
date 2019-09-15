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

vector<vector<int> > fourSum(vector<int>& nums, int target) {
	vector<vector<int> > ans;
	if (nums.size() < 4) return ans;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int expect = target - (nums[i] + nums[j]);
			int left = j + 1, right = nums.size() - 1;
			while (left < right) {
				if (nums[left] + nums[right] == expect) {
					vector<int> temp;
					temp.push_back(nums[i]);
					temp.push_back(nums[j]);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					ans.push_back(temp);
				} else if (nums[left] + nums[right] < expect) {
					left++;
				} else {
					right--;
				}
			}
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}