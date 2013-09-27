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

int64 cnt[12];
int64 ten[12], five[12];

void init() {
	ten[0] = five[0] = 1;
	forab(i, 1, 11) {
		ten[i] = 10*ten[i-1];
		five[i] = 5*five[i-1];
	}
	cnt[0] = 0;
	cnt[1] = 5;
	int64 fiveTen[12] = {};

	forab(n, 2, 11) {
		int64 tmp = 0;
		forab(r, 2, n)
			tmp += five[r]*ten[n-r];
		fiveTen[n] = tmp;
		cnt[n] = 4*ten[n-1] + tmp + cnt[n-1];
	}
}

string st;

int64 solve(int id = st.size()-1) {
	assert(id >= 0 && id < st.size()-1);
	if(id == 0) 
		return (st[id]-'0')/2 + 1;

	int64 ret = 0;

	if(id == st.size()-1) {
		ret += cnt[id];
	}

	forab(i, 1,  st[id] - '0'-1) {
		if(i % 2 == 0 )
			ret += ten[id];
		else if(i % 2 == 1){ 
			int n = id+1;	int64 tmp = 0;
			forab(r, 2, n)
				tmp += five[r]*ten[n-r];
			ret += tmp;
		}
	}
	if(st[id] != '0') {
		ret += cnt[id];
	}
	return ret;
}

int main()
{
	init();
	st = "9999";

	reverse(all(st));
	cout << solve();

	return 0;
}

