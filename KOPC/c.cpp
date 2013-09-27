//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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

const int sz = 2*(1e6+10);
const int64 mod = 1e9+7;

int64 fact[sz];

//a^b
int64 _pow(int a, int b) {
	if(b == 0)
		return 1LL;
	int64 tmp = _pow(a, b/2);
	tmp = (tmp*tmp)%mod;
	if(b&1)
		tmp = (tmp*a)%mod;
	return tmp;
}

int64 inv(int a) {
	return _pow(a, mod-2);
}
int main()
{
	fact[0] = 1;
	forab(i, 1, sz-1)
		fact[i] = (fact[i-1]*i)%mod;
	int T;
	read(T);

	while(T--) {
		int n;
		read(n);
		n--;
		int64 ans = fact[2*n+1];
		int64 t = inv((fact[n]*fact[n]) % mod);
		ans = (ans*t) % mod;
		Pf("%lld\n", ans);
	}

	return 0;
}
/*
int64 nCr(int n, int r) {
	int64 ans = fact[n];
	int64 t1 = inv(fact[r]), t2 = inv(fact[n-r]);
	ans = (ans*t1) % mod;
	ans = (ans*t2) % mod;
}

int main()
{
	fact[0] = 1;
	forab(i, 1, sz-1)
		fact[i] = (fact[i-1]*i)%mod;
	int T;

	forab(i, 1, 15){
		int n = i;
		int64 ans = 0, tmp;

		forab(r, 1, n) {
			tmp = nCr(n, r);
			tmp = (tmp*tmp) % mod;
			tmp = (r*tmp) % mod;
			ans += tmp;
		}
		Pf("%lld,",ans);
	}
	cout << endl;


	read(T);

	while(T--) {
		int n;
		int64 ans = 0, tmp;
		read(n);

		forab(r, 1, n) {
			tmp = nCr(n, r);
			tmp = (tmp*tmp) % mod;
			tmp = (r*tmp) % mod;
			ans += tmp;
		}
		Pf("%lld\n",ans);
	}

	return 0;
}
*/
