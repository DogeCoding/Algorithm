#include <iostream>
#include <vector>

using namespace std;

int minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.size() == 0)
		return 0;
	int min = rotateArray[0];
	for (int i = 1; i < rotateArray.size(); i++)
		if (rotateArray[i] < min)
			min = rotateArray[i];
	return min;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}