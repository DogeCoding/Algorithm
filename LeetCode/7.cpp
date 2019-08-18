#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

int reverse(int x) {
	long long temp = 1;
    if (x > ((temp << 31) - 1) || x < (1 << 31) || !x) return 0;
    long long ans = 0;
    while (x) {
    	ans = ans * 10 + x % 10;
    	x = x / 10; 
    	// cout << "temp: " << ans << " ";
    }
    if (ans > ((temp << 31) - 1) || ans < (1 << 31) || !ans) return 0;
    return ans;
}

long long func1(long long x, long long y) {
	long long temp = 1;
	if (y) {
		return (temp << x);
	} else {
		return -(temp << x);
	}
}

int main(int argc, char const *argv[])
{
	cout << reverse(1534236469) << endl;
	
	return 0;
}