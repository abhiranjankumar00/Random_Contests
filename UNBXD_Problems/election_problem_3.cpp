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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

int dp[55][(1<<17) + 110];
int N, inf[55], resist[55];

void printBin(int n) {
	rep(i, 16, 0)
		Pf("%d", (n & (1<<i)) != 0 ? 1 : 0);
}

int solve(int idx, int flag) {
	assert(idx >= 0 && idx <= N);
	assert(flag >= 0 && flag < (1<<17));

	if(idx == N)
		return 0;
	int &ret = dp[idx][flag];

	if(ret > -1)
		return ret;

	int tmp = resist[idx];
//	Pf("RESIST = %2d, ", tmp);

	if( (flag & (1<<8)) != 0 ) {
		tmp -= inf[idx];
	}

	rep(i, 7, 0)	if( (flag & (1<<i)) != 0 ) {
		int dist = 8 - i;
		if(idx + dist >= 0 && idx + dist < N)
			tmp -= ( inf[idx+dist] / (1<<dist)  );
	}

	forab(i, 9, 16)	if( (flag & (1<<i)) != 0 ) {
		int dist = i - 8;
		if(idx - dist >= 0 && idx - dist < N) 
			tmp -= ( inf[idx-dist] / (1<<dist) );
	}
	
	if(tmp > 0)
		return ret = N+1;
/*
	Pf("idx = %d, flag: ", idx);
	printBin(flag);
	Pf(" \tresist = %d\n", tmp);
*/
	flag &= ~(1<<16);
	flag <<= 1;

	int ans1 = solve(idx+1, flag);

	tmp = idx + 8 >= N ? 0 : 1;
	int ans2 = solve(idx+1, flag | tmp);

	if(ans1 == N+1 && ans2 == N+1)
		ret = N+1;
	else if(ans1 != N+1 && ans2 == N+1)
		ret = ans1;
	else if(ans1 == N+1 && ans2 != N+1)
		ret = tmp + ans2;
	else
		ret = min(ans1, tmp+ans2);

	return ret;
}

int main()
{
	CL(dp, -1);

	cin >> N;
	forn(i, N)
		cin >> inf[i];
	forn(i, N)
		cin >> resist[i];

	int ans = N+1;
	forn(i, (1<<9)) {
		int tmpAns = solve(0, i);
		if(tmpAns == N+1)
			continue;
		ans = min(ans, __builtin_popcount(i) + solve(0, i));
	}
	ans = ans == N+1 ? -1 : ans;
	cout << ans << endl;

	return 0;
}
