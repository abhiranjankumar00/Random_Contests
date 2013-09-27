//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

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

map <ii, int> bl, gr;
ST s;

int blue(int l, int r) {
	if(r - l < 1)
		return -1;
	if(r - l == 1)
		return (s[l] == 'a' && s[r] == 'b') ? 3 : -1;

	auto iter = bl.find(mp(l, r));

	if (iter != bl.end())
		return iter->second;

	int t;
	if(s[r] == 'a' && (t = blue(l, r-1)) > 0)
		return bl[mp(l, r)] = t + 2;

	return bl[mp(l, r)] = -1;
}

int green(int l, int r) {
	if(r - l < 2)
		return -1;

	if(s[l] != 'b')
		return -1;

	auto iter = gr.find(mp(l, r));
	if(iter != gr.end())
		return iter->second;

	int t = blue(l+1, r);
	if(t > 0)
		return gr[mp(l, r)] = t + 2;

	return gr[mp(l, r)] = -1;
}

int main()
{
	int test;
	read(test);

	while(test--) {
		bl.clear();
		gr.clear();
		cin >> s;

		if(s[0] == 'b') {
			Pf("IMPOSSIBLE\n");
			continue;
		}

		int ret = -1;

		forn(i, s.size()-1) {
			int b = blue(0, i);
			int g = green(i+1, s.size() - 1);
			if(b > 0 && g > 0) {
				if(ret < 0)
					ret = b+g+1;
				else
					ret = min(ret, b+g+1);
			}
		}
		if(ret > 0)
			Pf("%d\n", ret);
		else
			Pf("IMPOSSIBLE\n");
	}
	
	return 0;
}

