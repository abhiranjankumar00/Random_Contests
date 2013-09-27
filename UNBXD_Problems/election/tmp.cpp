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

const int shift = 7;
int N;
int resist[55], inf[55];
int dp[55][(1<<shift)+10];

void printBit(int n) {
	rep(i, 2*shift, 0) {
		cout << ((n & (1<<i)) != 0 ? 1 : 0);
	}
}

int solve(int idx, int flag ) {
	assert(idx >= 0 && idx < N);
	if(false && flag < 0 || flag >= (1<<N)) {
		cout << flag << ": ";
		printBit(flag);
		cout << endl;
	}
	assert(flag >= 0 && flag < (1<< N));
	if(idx == N)
		return 0;
	int &ret = dp[idx][flag];

	if(ret > -1)
		return ret;

	int tmp = resist[idx];

	forn(i, 2*shift+1)
		if((flag & (1<<i)) != 0 && idx - (i-shift) >= 0 && idx - (i-shift) < N) {
			int p = 1<<abs(shift-i);
			int newIdx = idx - (i-shift);
			int red = inf[newIdx]/p;
			Pf("tmp = %d, newIdx = %d, inf = %d, pow = %d, reducesBy = %d\n", tmp, newIdx, inf[newIdx], p, red);
			tmp -= inf[idx - (i-shift)] / (1<<abs(shift-i));
		}

	ret = N+1;
	if(tmp > 0) {
		Pf("FAILS: id = %2d, flag = %4d : ", idx, flag);
		printBit(flag);
		Pf(" , resist = %d\n ", tmp);
		cout << endl;
		return ret;
	}

	flag = flag & (~(1<<(2*shift)));
	flag <<= 1;
	int ans1 = solve(idx+1, flag);
	int ans2 = solve(idx+1, flag | 1);

	if(ans1 == N+1 && ans2 == N+1)
		ret = N+1;
	else if(ans1 == N+1 && ans2 != N+1)
		ret = ans2 + 1;
	else if(ans1 != N+1 && ans2 == N+1)
		ret = ans1;
	else
		ret = min(ans1, ans2+1);

	Pf("id = %2d, flag = %4d : ", idx, flag);
	printBit(flag);
	cout << endl << endl;
	return ret;
}

int main()
{
	CL(resist, 0);
	CL(inf, 0);
	CL(dp, -1);

	cin >> N;
	forn(i, N)
		cin >> inf[i];
	forn(i, N)
		cin >> resist[i];

	int ans = N+1;
	forn(i, (1<<(shift))) {

		int tmp = solve(0, i);
		cout << i << ": ";
		printBit(i);
		cout << " : " << tmp;
		cout << endl;
		cout << endl;

		int ret = solve(0, i);
		if(ret == N+1)
			continue;
		ret += __builtin_popcount(i);

		ans = min(ans, ret);
	}
	ans = ans == N+1 ? -1 : ans;
	DEBUG(ans);

	return 0;
}

