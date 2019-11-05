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

int strStr(string haystack, string needle) {
     if (!needle.size()) return 0;
     int position = haystack.find(needle);
     if (position != haystack.npos) {
     	return position;
     }
     return -1;
}

int strStr(string haystack, string needle) {
     if (!needle.size()) return 0;
     for (int i = 0; i < haystack.size(); i++) {
     	if (haystack[i] == needle[0]) {
     		for (int j = 0; j < needle.size(); j++) {
     			if (haystack[i+j] != needle[j]) {
     				break;
     			}
     			if (j == needle.size() - 1) {
     				return i;
     			}
     		}
     	}
     }
     return -1;
}

int main(int argc, char const *argv[]) {
	
	return 0;
}