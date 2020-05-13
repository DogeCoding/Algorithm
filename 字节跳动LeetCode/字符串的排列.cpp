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

bool checkInclusion(string s1, string s2) {
	if (s1.length() > s2.length()) return false;
	unordered_map<char, int> map;
	for (int i = 0; i < s1.length(); i++) {
		if (map.find(s1[i]) == map.end()) {
			map[s1[i]] = 1;
		} else {
			map[s1[i]] = map[s1[i]]+1;
		}
	}
	for (int i = 0; i <= s2.length() - s1.length(); i++) {
		unordered_map<char, int> tempMap = map;
		for(unordered_map<char,int>::iterator iter=tempMap.begin();iter!=tempMap.end();iter++) {
			cout << iter->first << " --- " << iter->second << " ||| ";
		}
		cout << endl;
		if (tempMap.find(s2[i]) != tempMap.end()) {
			for (int j = i; j < s1.length() + i; j++) {
				if (tempMap.find(s2[j]) != tempMap.end()) {
					if (tempMap[s2[j]] <= 0) {
						break;
					}
					tempMap[s2[j]] = tempMap[s2[j]]-1;
					cout << tempMap[s2[j]] << endl;
				} else {
					break;
				}
			}
			bool ans = true;
			for(unordered_map<char,int>::iterator iter=tempMap.begin();iter!=tempMap.end();iter++) {
				cout << iter->first << " --- " << iter->second << endl;
				if (iter->second != 0) {
					ans = false;
					break;
				}
			}
			if (ans) return ans;			
		}
		
	}
	return false;

}

int main(int argc, char const *argv[])
{
	cout << checkInclusion("adc", "dcda") << endl;
	return 0;
}













