#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot)
{
	// 边界判断！！！
	if (pRoot == NULL)
		return;
	queue <TreeNode*> q;
	q.push(pRoot);
	while (q.size())
	{
		TreeNode *temp = q.front();
		q.pop();
		if (temp->left != NULL || temp->right != NULL)
		{
			TreeNode *qTemp = temp->left;
			temp->left = temp->right;
			temp->right = qTemp;
		}
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
}

int main(int argc, char const *argv[])
{
	queue <int> q;
	q.push(1);
	cout << q.front() << endl;
	q.pop();
	cout << q.empty() << endl;
	return 0;
}