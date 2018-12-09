#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
#include <unordered_map>

using namespace std;

void adjustHeap(int *h, int index, int length) {
	int tmp = h[index];
	int child = index*2+1;
	while(child < length) {
		if (child+1 < length && h[child] < h[child+1]) ++child;
		if (h[index] < h[child]) {
			h[index] = h[child];
			index = child;
			child = index*2+1;
		} else break;
		h[index] = tmp;
	}
}

void buildHeap(int *h, int length) {
	for (int i = (length-1)/2; i >= 0; i--) 
		adjustHeap(h, i, length);
}

void sortHeap(int *h, int length) {
	buildHeap(h, length);
	for (int i = length-1; i > 0; i--) {
		h[i] ^= h[0];
		h[0] ^= h[i];
		h[i] ^= h[0];
		adjustHeap(h, 0, i);
	}
}

int binarySearch(int *h, int length, int target) {
	int left = 0, right = length;
	int mid = (right-left)/2;
	
	while(left <= right) {
		if (h[mid] == target) return 1;
		if (h[mid] < target) left = mid+1;
		else right = mid-1;
		mid = (right-left)/2+left;
	}
	return 0;
}

void _quick_sort(int *h, int length, int left, int right) {
	int first = left, last = right;
	int key = h[first];
	if (left >= right) return;
	while(first < last) {
		while(first < last && h[last] > key) last--;
		h[first] = h[last];
		while(first < last && key > h[first]) first++;
		h[last] = h[first];
	}
	h[first] = key;
	_quick_sort(h, length, left, first-1);
	_quick_sort(h, length, first+1, right);
}

void quick_sort(int *h, int length) {
	_quick_sort(h, length, 0, length-1);
}

int main(int argc, char const *argv[])
{
	int a[] = {2, 4, 3, 1, 7, 6, 5, 80, 23, 55};
	// sortHeap(a, 10);
	quick_sort(a, 10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << binarySearch(a, 10, 23) << endl;
	return 0;
}

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    	TreeNode* root = reConstructBinaryTree(pre, 0, pre.size()-1, in, 0, in.size()-1);
    	return root;
    }
    
    private:
    TreeNode* reConstructBinaryTree(vector<int> pre, int preLeft, int preRight, vector<int> in, int inLeft, int inRight) {
    	if (preLeft > preRight || inLeft > inRight) return NULL;
    	TreeNode *root = new TreeNode(pre[preLeft]);
    	int i = 0;
    	for (i = inLeft; i <= inRight; i++) 
    		if (in[i] == pre[preLeft]) break;
    	root->left = reConstructBinaryTree(pre, preLeft+1, preLeft+i-inLeft, in, inLeft, i-1);
    	root->right = reConstructBinaryTree(pre, preLeft+i-inLeft+1, preRight, in, i+1, inRight);
    	return root;
    }
        
};





