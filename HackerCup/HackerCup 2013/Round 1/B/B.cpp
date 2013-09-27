//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

void solve(int test) {
	int m, l;
	string k1, k2;
	cin >> m >> k1 >> k2;
	l = k1.size()/m;

	DEBUG(m);
	DEBUG(l);
	DEBUG(k1);
	DEBUG(k2);
	cout << endl;

	map <string, int> cnt1, cnt2, ans;

	for(int idx = 0; idx < k1.size(); idx+= l)
		cnt1[k1.substr(idx, l)] ++;
	for(int idx = 0; idx < k2.size(); idx+= l)
		cnt2[k2.substr(idx, l)] ++;

	tr(it, cnt1)
		cout << it->first << ": " << it->second << ", \t";
	cout << endl;
	tr(it, cnt2)
		cout << it->first << ": " << it->second << ", \t";
	cout << endl;

	tr(it, cnt1) if(it->second > 0) {
		map <string, int> :: iterator jt = cnt2.find(it->first);
		if(jt != cnt2.end() && jt->second > 0 ) {
			int mn = min(it->second, jt->second);
			string st = it->first;
			forn(i, st.size())	if(st[i] == '?')
				st[i] = 'a';
			ans[st] += mn;
			it->second -= mn;
			jt->second -= mn;
			if(it->second == 0)
				cnt1.erase(it);
			if(jt->second == 0)
				cnt2.erase(jt);
		}
	}

	tr(it, cnt1)
		cout << it->first << ": " << it->second << ", \t";
	cout << endl;
	tr(it, cnt2)
		cout << it->first << ": " << it->second << ", \t";
	cout << endl;

	tr(it, ans)
		cout << it->first << ": " << it->second << ", \t";
	cout << endl;

	cout << endl;
	cout << endl;
}

int main()
{
	int Test;
	cin >> Test;

	forab(test, 1, Test) 
		solve(test);

	return 0;
}

