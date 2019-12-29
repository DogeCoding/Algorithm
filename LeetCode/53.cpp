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

int searchInsert(vector<int>& nums, int target) {
	if (!nums.size()) return 0;
	int left = 0, right = nums.size();
	int mid = (right - left) / 2 + left;
	while (left < right) {
		if (nums[mid] == target) return mid;
		if (nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
		mid = (right - left) / 2 + left;
	}
	return left;
}

int main(int argc, char const *argv[]) {
	
	return 0;
}