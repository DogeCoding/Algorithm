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

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    string ans = strs[0];
    bool isChange = false;
    for (int i = 1; i < strs.size(); i++) {
        string temp = ans;
        isChange = false;
        for (int j = 0; j < strs[i].size(); j++) {
            if (strs[i][j] == temp[j]) {
                ans = temp.substr(0, j+1);
                isChange = true;
            } else {
                if (!j) ans = "";
                break;
            }
        }
        temp = ans;
        if (!temp.size()) break;
    }
    return isChange ? ans : "";
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty() == 1) return "";
    int min = strs[0].length();
    for (int i = 1; i < strs.length(); i++) {
        if (strs[i].length() > min) min = strs[i].length();
        for (int j = 0; j < min; j++) {
            if (strs[i-1][j] != strs[i][j]) {
                min = j;
                break;
            }
        }
    }
    return strs[0].substr(0, min);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}