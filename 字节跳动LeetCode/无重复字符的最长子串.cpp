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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* creatList(int *list, int length) {
	ListNode *head = new ListNode(0);
	ListNode *ans = head;
	for (int i = 0; i < length; i++) {
		head->next = new ListNode(list[i]);
		head = head->next;
	}
	return ans->next;
}

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int lengthOfLongestSubstring(string s) {
        if (!s.length() || s.length() == 1) return s.length();
        int max = 0 ^ s[0];
        int maxValue = 1;
        vector<int> temp(s.length(), 0);
        temp[0] = 1;
        for (int i = 1; i < s.length(); i++) {
        	cout << "max before: " << max << endl;
            int value = max^s[i] > max ? temp[i-1] + 1 : temp[i-1];
            max = value > temp[i-1] ? max^s[i] : 0^s[i];
            temp[i] = value > temp[i-1] ? value : 1;
            cout << "max after: " << max << " value: " << value << " temp: " << temp[i] << endl;
            if (temp[i] > maxValue) maxValue = temp[i];
        }
        return maxValue;
    }

int main(int argc, char const *argv[])
{
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	return 0;
}