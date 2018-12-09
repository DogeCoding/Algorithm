#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool judge(vector<int> &arr, int left, int right)
{
	if (left >= right)
		return true;
	int tmp = arr[right];
	int l = left;
	while(l < right && arr[l] < tmp)
			l++;
	for(int j = l; j < right; j++)
		if (arr[j] < tmp)
			return false;
	return judge(arr, left, l-1) && judge(arr, l, right-1);
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.size() == 0) return false;
	return judge(sequence, 0, sequence.size()-1);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}