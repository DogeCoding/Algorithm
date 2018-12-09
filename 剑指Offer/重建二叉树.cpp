#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode *reConstructBinaryTree (vector<int> pre, vector<int> in)
	{
		TreeNode *root = reConstructBinaryTree(pre, 0, pre.size()-1, in, 0, in.size()-1);
		return root;
	}
private:
	TreeNode *reConstructBinaryTree(vector<int> pre, int startPre, int endPre, vector<int> in, int startIn, int endIn)
	{
		if (startPre > endPre || startIn > endIn)
			return NULL;
		TreeNode *root = new TreeNode(pre[startPre]);
		for (int i = startIn; i <= endIn; i++)
		{
			if (pre[startPre] == in[i])
			{
				root->left = reConstructBinaryTree(pre, startPre+1, startPre+i-startIn, in, startIn, i-1);
				root->right = reConstructBinaryTree(pre, startPre+i-startIn+1, endPre, in, i+1, endIn);
			}
		}
		return root;
	}
	
};


int main(int argc, char const *argv[])
{
	
	return 0;
}