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
#include <string>

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

string reverseWords(string s) {
	string ans = "";
	string temp = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			if (temp != "") {
				ans = (ans == "" ? temp : temp + " ") + ans;
				temp = "";
			}
		} else {
			temp.push_back(s[i]);
		}
		if (i == s.length() - 1 && temp != "") {
			ans = (ans == "" ? temp : temp + " ") + ans;
		} 
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	cout << reverseWords("the sky is blue") << endl;
	return 0;
}













