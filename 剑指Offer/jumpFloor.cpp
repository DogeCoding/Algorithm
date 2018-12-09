#include <iostream>

using namespace std;

// 递归：到达n级台阶有两种方式。1：走一步；2：走两步。即f(n) = f(n-1)+f(n-2)
int jumpFloor(int number)
{
	// if (number == 0)
	// 	return 0;
	if (number == 1)
		return 1;
	if (number == 2)
		return 2;
	return jumpFloor(number-1)+jumpFloor(number-2);
}

// 迭代：类似递归思想，用缓存来记录数据
int jumpFloor2(int number)
{
	int before = 1, present = 1, tmp = 0;
	if (number == 1)
		return present;
	for (int i = 2; i <= number; i++)
	{
		tmp = present;
		present = present + before;
		before = tmp;
	}
	return present;
}

int main(int argc, char const *argv[])
{
	// cout << jumpFloor(3) << endl;
	cout << jumpFloor2(3) << endl;
	return 0;
}