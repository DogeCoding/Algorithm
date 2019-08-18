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

bool allUnique(string s, int start, int end) {
	unordered_map<char, int> hash;
	for (int i = start; i < end; i++) {
		if (hash.find(s[i]) == hash.end()) {
			hash[s[i]] = i;
		} else {
			return false;
		}
	}
	return true;
}

int lengthOfLongestSubstring(string s) {
    if (!s.size()) return 0;
    int max = 1;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j <= s.size(); j++) {
        	if (allUnique(s, i, j)) {
        		max = max > j - i ? max : j - i;
        	}
        }
    }
    return max;
}


int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int ans, i, j;
    ans = i = j = 0;
    while(i < s.size() && j < s.size()) {
    	if (hash.find(s[j]) == hash.end()) {
    		hash[s[j++]] = j;
    		ans = ans > j - i ? ans : j - i;
    	} else {
    		hash.erase(s[i++]);
    	}
    }
    return ans;
}

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int ans = 0;
    for (int i = 0, j = 0; j < s.size(); j++) {
    	if (hash.find(s[j]) != hash.end()) {
    		i = hash[j] > i ? hash[j] : i;
    	}
    	ans = ans > j - i + 1 ? ans : j - i + 1;
    	hash[s[j]] = j + 1;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	string s = "au";
    cout << "ans: " << lengthOfLongestSubstring(s) << endl;
	return 0;
}