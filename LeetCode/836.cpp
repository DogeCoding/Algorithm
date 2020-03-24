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

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return !(rec1[2] <= rec2[0] ||   // left
             rec1[3] <= rec2[1] ||   // bottom
             rec1[0] >= rec2[2] ||   // right
             rec1[1] >= rec2[3]);    // top
}

int main(int argc, char const *argv[])
{
	vector<int> rec1 = {0,0,2,2};
	vector<int> rec2 = {1,1,3,3};
	cout << isRectangleOverlap(rec1, rec2) << endl;
	return 0;
}