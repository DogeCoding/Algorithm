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

string convert(string s, int numRows) {
	char *map[numRows];
	int i = 0, r = 0, h = 1;
	int flag = 0;
	for (; i < s.length(); i++) {
		if (!flag) {
			if (r < numRows) {
				map[h-1][r] = s[i];
				cout << "1: " << map[h-1][r] << " ";
				r++;
			} else {
				h++;
				r = numRows-2;
				flag = 1;
				map[h-1][r] = s[i];
				cout << "2: " << map[h-1][r] << " ";
				r--;
			}
		} else {
			h++;
			if (!r) {
				flag = 0;
				map[h-1][r] = s[i];
				cout << "3: " << map[h-1][r] << " ";
				r++;
			} else {
				map[h-1][r] = s[i];
				cout << "4: " << map[h-1][r] << " ";
				r--;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < numRows; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return "";        
}

int main(int argc, char const *argv[]) {
	convert("PAYPALISHIRING", 4);
	return 0;
}