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

string compressString(string S) {
	if (!S.size()) return S;
	string ans = "";
	string temp = S.substr(0, 1);
	int count = 0;
	for (char& c : S) {
		if (c != temp[0]) {
			ans.append(temp);
			ans.append(to_string(count));
			temp[0] = c;
			count = 1;
		} else {
			count++;
		}
	}
	ans.append(temp);
	ans.append(to_string(count));
	if (ans.size() >= S.size())
		return S;
	return ans;
}

int main(int argc, char const *argv[])
{
	string s = "aabcccccaa";
	cout << compressString(s) << endl;
	return 0;
}