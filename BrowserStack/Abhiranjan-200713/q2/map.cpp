// Please enable g++0x while compiling it.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

long long charToInt[26];

map<long long, char> intToChar;
map<long long, char> par;

long long find(char ch) {
	int id = ch - 'A';
	assert(ch >= 'A' && ch <= 'Z');
	long long &ret = charToInt[id];
	if(ret == -1) {
		if(ch == 'A')
			ret = 1;
		else
			ret = find(ch-1)*2 + (id + 1);
		intToChar[charToInt[id]] = ch;
	}
	return ret;
}

bool solve(long long num) {
	if(num <= 0)
		return false;

	if(intToChar.count(num) != 0) {
		par[num] = intToChar[num];
		return true;
	}

	for(int ch = 'Z'; ch >= 'A'; --ch) {
		if(solve(num - find(ch))) {
			par[num] = ch;
			break;
		}
	}
	return true;
}

int main()
{
	memset(charToInt, -1, sizeof(charToInt)); find('Z');
// Uncomment below lines to get the mappings.
/*
	for(char ch = 'A'; ch <= 'Z'; ++ch) {
		cout << ch << " " << find(ch) << "\n";
	}
	for(auto it = (intToChar).begin(); it != (intToChar).end(); ++it) {
		cout << it->first << " " << it->second << "\n";
	}
*/
	long long num;
	cin >> num;
	solve(num);

	string ans = "";
	while(num > 0) {
		char ch = par[num];
		ans += ch;
		num -= find(ch);
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";

	return 0;
}

