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

int lengthOfLIS(vector<int>& nums) {
	int length = nums.size();
	vector<int> len(length, 1);
	for (int i = length - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (nums[j] < nums[i]) {
				len[j] = max(len[j], len[i] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < length; i++) {
		if (len[i] > ans) {
			ans = len[i];
		}
	}
	return ans;
}

int lengthOfLIS(vector<int>& nums) {
    int len = 1, n = (int)nums.size();
    if (n == 0) return 0;
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < n; ++i) {
        if (nums[i] > d[len]) d[++len] = nums[i];
        else{
            int l = 1, r = len, pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (d[mid] < nums[i]) {
                    pos = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            d[pos + 1] = nums[i];
        }
    }
    return len;
}
    

int main(int argc, char const *argv[])
{
	
	return 0;
}