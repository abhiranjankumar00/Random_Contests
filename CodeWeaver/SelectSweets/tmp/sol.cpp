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
// /*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
// */

const int64 mod = (int)1e9 + 7;
const int sz = (int)5e6;
int64 fact[sz];

int64 _fact(int n) {
	return n == 0 ? 1 : (n * _fact (n-1)) % mod;
}

// a^x = (a)
int64 _pow(int64 a, int64 x) {
	if(x == 0)
		return 1ll;
	int64 ret = _pow(a, x/2);
	ret = (ret * ret) % mod;

	if(x % 2 == 1)
		ret = (ret * a) % mod;

	return ret;
}

int64 inv(int64 a) {
	return _pow(a, mod-2);
}

int64 C(int n, int r) {
	if(n < 0)
		return 0;
	if(r < 0 || r > n)
		return 0;

	DEBUG(n);
	DEBUG(r);
	DEBUG(n-r);

	//int64 num = _fact(n);
	int64 num = fact[n];
	DEBUG(num);
//	int64 den1 = _fact(r);
	int64 den1 = fact[r];
	DEBUG(den1);
//	int64 den2 = _fact(n-r);
	int64 den2 = fact[n-r];
	DEBUG(den2);

	int64 ans = num;
	ans = (ans * inv(den1)) % mod;
	ans = (ans + mod) % mod;
	ans = (ans * inv(den2)) % mod;
	ans = (ans + mod) % mod;
	return ans;
}

int main()
{
	fact[0] = 1;
	forab(i, 1, sz-1)
		fact[i] = (i * fact[i-1]) % mod;

	int N, M, K;

	cin >> N >> M >> K;
	assert(N >= 1 && N <= 1e6);
	assert(M >= 1 && M <= 1e6);
	assert(K >= 0 && K <= M);

	while(K--) {
		int tmp, cnt;
		cin >> tmp >> cnt;
		assert(tmp >= 1 && tmp <= M);
		assert(cnt >= 1 && cnt <= 1e6);
		N -= cnt;
	}
	DEBUG(N);

	DEBUG("#0");
	if(N < 0) {
		cout << 0 << endl;
		return 0;
	}

	DEBUG("#1");
	cout << C(N+M-1, M-1) << endl;

	return 0;
}

