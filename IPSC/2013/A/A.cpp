//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 				int64;
typedef vector<int> 			vi;
typedef string 					ST;		// Never used it :X
typedef stringstream 			SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 			ii;
typedef vector<string> 			vs;

// WHY YOU DON'T WORK :X
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)		for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)	// \m/ Defined 3rd time.
#define forn(i, n)		for(int i = 0, __even_my_fish_codes_better__ = (int)n; i <  __even_my_fish_codes_better__; i++)
#define forab(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i <= __even_my_fish_codes_better__; i++)
#define rep(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i >= __even_my_fish_codes_better__; i--)

#define PI				M_PI		// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define E 				M_E			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define endl			("\n")		// Really required?

#define	all(c)			(c).begin(), (c).end()
#define	cl(a, b)		memset(a, b, sizeof(a))
#define mp				make_pair
#define pb				push_back

#define	Sf				scanf
#define	Pf				printf
#define read(n)			scanf("%d", &n)
#define write(n)		printf("%d ", (int)n)
#define writeln(n)		printf("%d\n", (int)n)

#if (0 or defined ONLINE_JUDGE)		// Why topcoder doesn't use it. :(
	#define	debug
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

vector < pair <int, int> > idx;

int dp[(int)1e4 + 111][14];

int solve(int val) {
	int &ret = dp[val][13];
	if(ret > -1)
		return ret;
//	cout << "val = " << val << "\n"; 

	tr(it, idx) {
		int preval = val - it->first;
		if(preval < 0)
			continue;
		int ways = solve(preval);
//		cout << "preval = " << preval << "\n"; 
		if(ret == -1 || ret > ways + 1) {
			ret = ways + 1;
//			printf("(%d, %d) \n", it->first, it->second);
			for(int i = 0; i < 13; ++i) {
//				printf("i = %d ", i);
				if(i == it->second) {
//					printf("in" );
					dp[val][i] = dp[preval][i] + 1;
				}
				else {
//					printf("out" );
					dp[val][i] = dp[preval][i] ;
				}
//				cout << "\n";
			}
		}
	}

	return ret;
}

int main()
{
	idx.clear();
	for(int i = 1; i <= 1e4; ++i) {
		dp[i][13] =-1;
	}
//	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < 14; ++i) {
		dp[0][i] = 0;
	}
	idx.push_back(make_pair(1, 0));
	idx.push_back(make_pair(2, 1));
	idx.push_back(make_pair(5, 2));
	idx.push_back(make_pair(10, 3));
	idx.push_back(make_pair(20, 4));
	idx.push_back(make_pair(50, 5));
	idx.push_back(make_pair(100, 6));
	idx.push_back(make_pair(200, 7));
	idx.push_back(make_pair(500, 8));
	idx.push_back(make_pair(1000, 9));
	idx.push_back(make_pair(2000, 10));
	idx.push_back(make_pair(5000, 11));
	idx.push_back(make_pair(10000, 12));
/*
	for(__typeof((idx).begin()) it = (idx).begin(); it != (idx).end(); ++it) {
		dp[it->first][13] = 1;
		for(int i = 0; i < 13; ++i) {
			if(i == it->second)
				dp[it->first][i] = 1;
			else
				dp[it->first][i] = 0;

		}
	}
*/
	for(int i = 0; i < 1e4; ++i) {
		solve(i);
	}
	int test;
	cin >> test;

	while(test--) {
		int e, c;
		cin >> e >> c;
		int val = e*100 + c;
		solve(val);
		for(int i = 0; i < 13; ++i) {
			printf("%d ", dp[val][i]);
		}
		cout << "\n";
	}

	return 0;
}

