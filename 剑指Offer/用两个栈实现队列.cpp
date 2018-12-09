#include <iostream>
#include <stack>

using namespace std;

stack <int> stack1;
stack <int> stack2;

void push(int node)
{
	while (stack1.empty() != 1)
	{
		stack2.push(stack1.top());
		stack1.pop();
	}
	stack1.push(node);
	while (stack2.empty() != 1)
	{
		stack1.push(stack2.top());
		stack2.pop();
	}
}

int pop()
{
	int ans = stack1.top();
	stack1.pop();
	return ans;
}

int main(int argc, char const *argv[])
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	for (int i = 0; i < 5; i++)
		cout << pop() << endl;
	return 0;
}