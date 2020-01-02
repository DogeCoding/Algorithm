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

int mySqrt(int x) {
    if (x == 0) return 0;
    double last=0;
    double res=1;
    while(res!=last) {
        last=res;
        res=(res+x/res)/2;
    }
    return int(res);
}

int main(int argc, char const *argv[]) {
	
	return 0;
}