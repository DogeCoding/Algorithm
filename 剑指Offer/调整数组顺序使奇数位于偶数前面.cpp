#include <iostream>

using namespace std;

void reOrderArray(vector<int> &array)
{
	vector<int> odd, even;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i]%2)
			odd.push_back(array[i]);
		else
			even.push_back(array[i]);
	}
	for (int i = 0, j = 0, k = 0; i < array.size(); i++)
	{
		if (j < odd.size())
			array[i] = odd[j++];
		else
			array[i] = even[k++];
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}