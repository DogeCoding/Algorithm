#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack <int> dataStack, minStack;

void push(int value)
{
	dataStack.push(value);
	if (minStack.empty())
		minStack.push(value);
	else
		if (value < minStack.top())
			minStack.push(value);
}
void pop()
{
	if (dataStack.top() == minStack.top())
		minStack.pop();
	dataStack.pop();
}
int top()
{
	return dataStack.top();
}
int min()
{
	return minStack.top();
}

int main(int argc, char const *argv[])
{
	
	return 0;
}