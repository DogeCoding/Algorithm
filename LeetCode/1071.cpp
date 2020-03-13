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

static int maxLen;

int LCS(string str1, string str2, int b[maxLen][maxLen]) {
	int len1 = str1.length();
	int len2 = str2.length();
	int a[maxLen][maxLen];
	for (int i = 0; i <= len1; i++) {
		a[0][i] = 0;
	}
	for (int i = 0; i <= len2; i++) {
		a[i][0] = 0;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i] == str2[j]) {
				a[i][j] = a[i-1][j-1] + 1;
				b[i][j] = 1;
			} else if (a[i-1][j] > a[i][j-1]) {
				a[i][j] = a[i-1][j];
				b[i][j] = 2;
			} else {
				a[i][j] = a[i][j-1];
				b[i][j] = 3;
			}
		}
	}
	int max = 0;
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	return max;
}

void LCSStr(string str, int b[maxLen][maxLen], int n, int m, string &ans, int index) {
	if (n == 0 || m == 0) return;
	if (b[n][m] == 1) {
		ans[--index] = str[n];
	} else if (b[n][m] = 2) {
		LCSStr(str, b, n-1, m, ans, index);
	} else {
		LCSStr(str, b, n, m-1, ans, index);
	}
}

string gcdOfStrings(string str1, string str2) {
	int len1 = str1.length(), len2 = str2.length();
	maxLen = max(len1, len2);
	int b[maxLen][maxLen];
	int LCSLen = LCS(str1, str2, b);
	string ans(maxLen, ' ');
	LCSStr(str1, b, len1, len2, ans, maxLen);
	return ans;
}

int main(int argc, char const *argv[])
{
	string str1("ABCABC");
	string str2("ABC");
	cout << gcdOfStrings(str1, str2) << endl;
	return 0;
}