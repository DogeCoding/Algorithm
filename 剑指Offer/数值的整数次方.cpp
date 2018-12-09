#include <iostream>

using namespace std;

double Power (double base, int exponent)
{
	double ans = base;
	if (exponent == 0)
		return 1;
	if (exponent < 0)
	{
		ans = 1/base;
		exponent = -exponent;
		for (int i = 1; i < exponent; i++)
			ans = ans/base;
		return ans;
	}
	for (int i = 1; i < exponent; i++)
		ans *= base;
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << Power(2, -3) << endl;
	return 0;
}