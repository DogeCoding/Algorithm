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

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
    	int expectValue = target-nums[i];
    	if (hash.find(expectValue) != hash.end()) {
    		result.push_back(hash[expectValue]);
    		result.push_back(i);
    		return result;
    	}
    	hash[nums[i]] = i;
    }
    return result;
}

int lengthOfLongestSubstring(string s) {
    if (!s.size()) return 0;
    unordered_map<char, int> hash;
    int ans[s.size()];
    memset(ans, 0, sizeof(int) * s.size());
    ans[0] = 1;
    hash[s[0]] = 0;
    int max = 1;
    for (int i = 1; i < s.size(); i++) {
        if (hash.find(s[i]) == hash.end()) {
            ans[i] = ans[i-1] + 1;
            hash[s[i]] = i;
        } else {
            cout << "tmp: " << ((ans[i-1] - ans[hash[s[i]]]) ? : 0) + 1 << endl;
            ans[i] = ((ans[i-1] - ans[hash[s[i]]]) ? : 0) + 1;
        }
        if (ans[i] > max) {
            max = ans[i];
        }
    }
    for (int i = 0; i < s.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return max;
}

int main(int argc, char const *argv[]) {
	string s = "dvdf";
    cout << "ans: " << lengthOfLongestSubstring(s) << endl;
	return 0;
}