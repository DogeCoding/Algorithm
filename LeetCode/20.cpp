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
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case ')': {
                if (map.find('(') == map.end())
                    return false;
                else 
                    map['(']--;
                break;
            }
            case '}': {
                if (map.find('{') == map.end())
                    return false;
                else
                    map['{']--;
                break;
            }
            case ']': {
                if (map.find('[') == map.end())
                    return false;
                else 
                    map['[']--;
                break;
            }
            default: {
                if (map.find(s[i]) == map.end()) {
                    map[s[i]] = 1;
                } else {
                    map[s[i]]++;
                }
            }
        } 
    }
    cout << "yfk" << endl;
    cout << map['('] << "k" << endl;
    for (unordered_map<char, int>::iterator i = map.begin(); i != map.end(); i++){
        if (i->second != 0)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
	cout << isValid("()") << endl;
	return 0;
}