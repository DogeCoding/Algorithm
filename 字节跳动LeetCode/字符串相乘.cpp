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

string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";
	vector<int> result(num1.length() + num2.length(), 0);
	for (int i = 0; i < num1.length(); i++) {
		for (int j = 0; j < num2.length(); j++) {
			result[i+j] += (num1[i] - '0') * (num2[j] - '0');
		}
	}
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << "result -- " << result[i] << endl;
		if (result[i] < 10) continue;
		result[i-1] += result[i] / 10;
		result[i] %= 10;
	}
	string ans = "";
	for (int i = 0; i < result.size() - 1; i++) {
		cout << result[i] << endl;
		if (!i && !result[i]) continue;
		cout << ans << endl;
		cout << (char)(result[i] + '0') << endl;
		ans.push_back(result[i] + '0');
		cout << ans << endl;
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	cout << multiply("9", "9") << endl;
	return 0;
}













