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

bool isValid(string s) {
    stack<char> st;
    for (char &c : s) {
        if (c == ')' || c == ']' || c == '}') {
            cout << c << " " << st.top() << endl;
            cout << (c-1 || c-2) << endl;
            if (st.empty()) return false;
            if (st.top() != c-1 && st.top() != c-2) return false;
            st.pop();
        } else {
            st.push(c);
        }
    } 
    return st.empty();
}

int main(int argc, char const *argv[]) {
	cout << isValid("()") << endl;
    // cout << ((int)'(') << endl;
    // cout << ((int)')') << endl;
    // cout << ((int)'[') << endl;
    // cout << ((int)']') << endl;
    // cout << ((int)'{') << endl;
    // cout << ((int)'}') << endl;
	return 0;
}