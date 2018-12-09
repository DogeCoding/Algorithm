#include <iostream>
#include <vector>

using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
	stack <int> s;
	int i = 0, j = 0;
	s.push(pushV[i]);
	while (!s.empty())
	{
		cout << s.top() << " " << popV[j] << endl;
		if (s.top() == popV[j] && i < pushV.size()-1)
		{
			s.pop();
			s.push(pushV[++i]);
			j++;
		}
		else if (s.top() == popV[j])
		{
			s.pop();
			j++;
		}
		else if (s.top() != popV[j] && i < pushV.size()-1)
		{
			s.push(pushV[++i]);
		}
		else
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}