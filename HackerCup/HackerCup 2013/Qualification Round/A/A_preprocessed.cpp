#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;

string filter(string st) {
	string ret = "";
	for(int i = 0, lets_stop_here = (int)st.size(); i < lets_stop_here; i++) {
		st[i] = tolower(st[i]);
		if(st[i] >= 'a' && st[i] <= 'z')
			ret += st[i];
	}
	sort((ret).begin(), (ret).end());
	return ret;
}

int main()
{
	int Test;
	scanf("%d\n", &Test);
	string st;
	for(int test = 1, lets_stop_here = (int)Test; test <= lets_stop_here; test++) {
		getline(cin, st);
		st = filter(st);
		vector <int> group;
		group.push_back(1);
		for(int i = 1, lets_stop_here = (int)st.size()-1; i <= lets_stop_here; i++)
			if(st[i] == st[i-1])
				group.back() += 1;
			else
				group.push_back(1);
		sort((group).begin(), (group).end(), greater<int>());
		int mul = 26, ret = 0;
		for(__typeof((group).begin()) it = (group).begin(); it != (group).end(); it++) {
			ret += mul**it;
			mul--;
		}
		printf("Case #%d: %d\n", test, ret);
	}
	return 0;

}
