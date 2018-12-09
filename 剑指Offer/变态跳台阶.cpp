#include <iostream>

using namespace std;

int jumpFloorII(int number)
{
	int tmp1 = 1, ans = 2;
	if (number == 1)
		return tmp1;
	for (int i = 3; i <= number; i++)
		ans = ans*2;
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << jumpFloorII(3) << endl;
	return 0;
}