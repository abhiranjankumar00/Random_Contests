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
const int sz = 1e4 + 11;
const int _mod = 1e9 + 7;
int fact[sz];

void init() {
	fact[0] = 1;
	forab(i, 1, sz-1)
		fact[i] = (1ll*fact[i-1]*i) % _mod;
}

int64 _pow(int a, int p) {
	if(p == 0)
		return 1;
	int64 ret = _pow(a, p/2);
	ret = (1ll*ret*ret)%_mod;
	if(p % 2 == 1)
		ret = (1ll*ret*a) % _mod;
	return ret;
}

inline int64 C(int n, int r) {
	int64 a = fact[n], b = fact[n-r], c = fact[r];
	int64 x = pow(b, _mod-2), y = pow(c, _mod-2);
	int64 ret = (x*y) % _mod;;
	ret = (ret * a) % _mod;;
	return ret;
}

int N, K;
int arr[sz];

void solve(int test) {
	Sf("%d %d", &N, &K);
	forn(i, N)
		read(arr[i]);
	sort(arr, arr+N);
/*
	DEBUG(N);
	DEBUG(K);
	forn(i, N) 
		write(arr[i]);
	cout << endl;
*/
	int64 ans = 0, tmp;
	forab(idx, K-1, N-1) {
		tmp = (C(idx, K-1)*arr[idx])%_mod;
		assert(tmp >= 0 && tmp < _mod);
//		Pf("arr[%d] = %d, cnt = %lld\n", idx, arr[idx], tmp);
		ans = (ans + tmp) % _mod;
	}

	Pf("Case #%d: %lld\n", test, ans);
}

int main()
{
	init();
	int Test;
	read(Test);

	forab(test, 1, Test)
		solve(test);

	return 0;
}

