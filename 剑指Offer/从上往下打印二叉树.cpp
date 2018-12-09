#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

vector<int> PrintFromTopToBottom(TreeNode *root)
{
	queue <TreeNode*> q;
	vector <int> ans;
	q.push(root);
	while (!q.empty())
	{
		TreeNode *tree = q.front();
		q.pop();
		ans.push_back(tree->val);
		if (tree->left)
			q.push(tree->left);
		if (tree->right)
			q.push(tree->right);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}


{
	queue<TreeNode*> q;
	q.push(root);
	vector<int> r;
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		if(!root) continue;
		r.push_back(root -> val);
		q.push(root -> left);
		q.push(root -> right);
	}
	return r;
}