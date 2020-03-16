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

int countCharacters(vector<string>& words, string chars) {
	unordered_map<char, int> charMap;
	for (auto &c : chars) {
		charMap[c]++;
	}
	int ans = 0;
	for (auto &str : words) {
		unordered_map<char, int> tempMap = charMap;
		bool cover = true;
		for (auto &c : str) {
			if (tempMap.find(c) == tempMap.end()) {
				cover = false;
				break;
			} else if (!tempMap[c]) {
				cover = false;
				break;
			} else {
				tempMap[c]--;
			}
		}
		if (cover) {
			ans += str.length();
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}