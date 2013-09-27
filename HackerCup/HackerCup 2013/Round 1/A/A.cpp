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
const int64 _mod = 1e9 + 7;
int64 _C[sz][sz];

void init() {
	forn(i, sz) {
		forn(j, i+1) {
			if(j == 0 || i == j)
				_C[i][j] = 1;
			else
				_C[i][j] = (_C[i-1][j-1] + _C[i-1][j]) % _mod;
		}
	}
}

inline int64 C(int n, int r) {
	assert(n < sz);
	assert(r>= 0);
	assert(r <= n);
	return (r < 0 || r > n) ? 0 : _C[n][r];
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

