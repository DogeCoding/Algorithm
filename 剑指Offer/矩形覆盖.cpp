#include <iostream>

using namespace std;

int rectCover(int number)
{
	if (number <= 0)
		return 0;
	int ans[number];
	ans[0] = 1;
	ans[1] = 2;
	for (int i = 2; i < number; i++)
		ans[i] = ans[i-1] + ans[i-2];
	return ans[number-1];

}

int main(int argc, char const *argv[])
{
	cout << rectCover(4) << endl;
	return 0;
}