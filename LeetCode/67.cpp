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

string addBinary(string a, string b) {
    string ans = "";
    int carry = 0;
    int lengthA = a.length(), lengthB = b.length();
    while(lengthA && lengthB) {
        int num = a[--lengthA] - '0' + b[--lengthB] - '0' + carry;
        carry = num / 2;
        ans.insert(ans.begin(), (num % 2) + '0');
    }
    while(lengthA) {
        int num = a[--lengthA] - '0' + carry;
        carry = num / 2;
        ans.insert(ans.begin(), (num % 2) + '0');
    }
    while(lengthB) {
        int num = b[--lengthB] - '0' + carry;
        carry = num / 2;
        ans.insert(ans.begin(), (num % 2) + '0');
    }
    if (carry) ans.insert(ans.begin(), carry + '0');
    return ans;
}

int main(int argc, char const *argv[]) {
	cout << addBinary("1010", "1011") << endl;
	return 0;
}