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

int removeElement(vector<int>& nums, int val) {
	int i = 0;
	for (int j = 0; j < nums.size(); j++) {
		if (nums[j] != val) {
			nums[i] = nums[j];
			i++;
		}
	}       
	return i;
}

int main(int argc, char const *argv[]) {
	
	return 0;
}