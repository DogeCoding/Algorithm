#include <iostream>
#include <math.h>

using namespace std;

int NumberOf1(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	cout << NumberOf1(-2147483648) << endl;
	return 0;
}