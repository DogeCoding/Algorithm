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
    if (!s.length()) return s.length();
    int max = 0;
    unordered_map <char, int> map;
    for (int i = 0; i < s.length(); i++) {
    	int temp = 0;
    	map.clear();
    	for (int j = i; j < s.length(); j++) {
			if (map.find(s[j]) == map.end()) {
				temp++;
				map[s[j]] = 1;	
			} else {
				break;
			}
    	}
    	if (temp > max) max = temp;
    }
    return max;
}

int lengthOfLongestSubstring(string s) {
	if (!s.length()) return s.length();
	int left = 0, right = 1;
	int max = 1;
	unordered_map <char, int> map;
	map[s[0]] = 0;
	while (right < s.length()) {
		if (map.find(s[right]) != map.end()) {
			left = map[s[right]] + 1 > left ? map[s[right]] + 1 : left;
			map[s[right]] = right;			
		}
		if (right - left + 1 > max) max = right - left + 1;
		map[s[right]] = right;
		right++;		
	}
	return max;
}

int main(int argc, char const *argv[])
{
	cout << lengthOfLongestSubstring("abcabcbb") << endl;
	return 0;
}













