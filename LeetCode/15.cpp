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

vector<vector<int> > threeSum(vector<int>& nums) {
	vector<vector<int> > res;
	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size(); i++) {
		int target = -nums[i];
		int front = i + 1, back = nums.size() - 1;
		while (front < back) {
			if (nums[front] + nums[back] < target) {
				front++;
			} else if (nums[front] + nums[back] > target) {
				back--;
			} else {
				vector<int> triplet(3, 0);
				triplet[0] = nums[i];
				triplet[1] = nums[front];
				triplet[2] = nums[back];
				res.push_back(triplet);
				while(front < back && nums[front] == triplet[1]) front++;
				while(front < back && nums[back] == triplet[2]) back--;
			}
		}
		while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}