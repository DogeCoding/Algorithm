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

void merge(vector<int>& A, int m, vector<int>& B, int n) {
	int p1 = m-1,p2 = n-1,cur = m+n-1;
    while ((p1 >= 0) && (p2 >= 0)) A[cur--] = A[p1] > B[p2] ? A[p1--] : B[p2--];
    while (p1 >= 0) A[cur--] = A[p1--];
    while (p2 >= 0) A[cur--] = B[p2--];
}

int main(int argc, char const *argv[])
{
	vector<int> A = {1,2,3,0,0,0};
	vector<int> B = {2,5,6};
	merge(A, 3, B, 3);
	for (int i = 0; i < 6; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}