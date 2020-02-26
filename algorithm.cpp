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

int maxProfit(vector<int>& prices) {
	int length = prices.size();
	int max = 0;
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			if (prices[j] - prices[i] >  max) {
				max = prices[j] - prices[i];
			}
		}
	}
	return max;
}

int maxProfit(vector<int>& prices) {
	int minPrice = 0x7fffffff;
	int maxProfit = 0;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < minPrice) {
			minPrice = prices[i];
		}
		if (prices[i] - minPrice > maxProfit) {
			maxProfit = prices[i] - minPrice;
		}
	}
	return maxProfit;
}

// 题解
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-dp-7-xing-ji/
// 

int main(int argc, char const *argv[])
{
	
	return 0;
}