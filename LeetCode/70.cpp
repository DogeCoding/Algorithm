#include <stdlib.h>
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

int climbStairs(int n) {
	double sqrt5 = sqrt(5);
	double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
	return (int)(fibn / sqrt5);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}