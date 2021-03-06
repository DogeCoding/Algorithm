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

string replaceSpace(string s) {
	vector<char> str;
	for (auto &c : s) {
		if (c != ' ') {
			str.push_back(c);
		} else {
			str.push_back('%');
			str.push_back('2');
			str.push_back('0');
		}
	}
	string ans(str.begin(), str.end());
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}