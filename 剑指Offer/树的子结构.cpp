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

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL)
		return false;
	if (pRoot2 == NULL)
		return false;
	queue <TreeNode*> q1;
	queue <TreeNode*> q2;
	q1.push(pRoot1);
	while (!q1.empty())
	{
		TreeNode *temp1 = q1.front();
		q1.pop();
		if (temp1->val == pRoot2->val)
		{
			q2.push(pRoot2);
			queue <TreeNode*> q3;
			q3.push(temp1);
			while (q2.size()&&q3.size())
			{
				TreeNode *temp2 = q2.front();
				TreeNode *temp3 = q3.front();
				q2.pop();
				q3.pop();
				if (temp3->left->val == temp2->left->val && temp3->right->val == temp2->right->val)
				{
					q3.push(temp3->left);
					q3.push(temp3->right);
					q2.push(temp2->left);
					q2.push(temp2->right);
				}
				else if (temp3->left->val == temp2->left->val && temp2->right == NULL)
				{
					q3.push(temp3->left);
					q2.push(temp2->left);
				}
				else if (temp2->left == NULL && temp3->right->val == temp2->right->val)
				{
					q3.push(temp3->right);
					q2.push(temp2->right);
				}
				else
					return false;
			}
			return true;
		}
		if (temp1->left != NULL)
			q1.push(temp1->left);
		if (temp1->right != NULL)
			q1.push(temp1->right);
	}
	return true;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}