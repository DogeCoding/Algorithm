#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> printMatrix(vector<vector <int> > matrix)
{
	int row = matrix.size();
	int column = matrix[0].size();
	vector<int> res;

	if (row == 0 || column == 0)
		return res;

	int left = 0, top = 0, right = column-1, bottom = row-1;
	while(left<=right && top<=bottom)
	{
		for (int i = left; i <= right; i++)
			res.push_back(matrix[top][i]);
		top++;
		for (int i = top; i <= bottom; i++)
			res.push_back(matrix[i][right]);
		right--;
		if (top <= bottom)
			for (int i = right; i >= left; i--)
				res.push_back(matrix[bottom][i]);
		bottom--;
		if (left <= right)
			for (int i = bottom; i >= top; i--)
				res.push_back(matrix[i][left]);
		left++;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	vector <vector <int> > input;
	vector <int> input2;
	for (int i = 1; i <= 5; i++)
	{
		if (i%5 != 0)
			input2.push_back(i);
		else
		{
			input2.push_back(i);
			input.push_back(input2);
			input2.clear();
		}
	}
	// for (int i = 0; i < input.size(); i++)
	// {
	// 	for (int j = 0; j < input[i].size(); j++)
	// 		cout << input[i][j] << " ";
	// 	cout << endl;
	// }
	vector<int> ans = printMatrix(input);

	cout << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}

/*  1  2  3  4 
    5  6  7  8
    9 10 11 12
   13 14 15 16 */