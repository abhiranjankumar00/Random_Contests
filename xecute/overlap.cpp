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
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int64,int64> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
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

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

vector < ii > p;
int N;

int binarySearch(int64 v, int l, int r) {
	if(l == r)
		return l;
	int mid = (l+r+1)/2;

	if(p[mid].first <= v)
		return binarySearch(v, mid, r);
	else
		return binarySearch(v, l, mid-1);
}

int main()
{
	int test;
	read(test);

	while(test--) {
		p.clear();
		read(N);

		forn(i, N) {
			int64 a, b;
			Sf("%lld  %lld", &a, &b);
			if(a > b)
				swap(a, b);
			p.pb(mp(a, b));
		}
		sort(all(p));

		tr(it, p)
			Pf("(%lld, %lld),  ", it->first, it->second);
		cout << endl;

		int64 ans = 0;

		forn(i, N) {
			int idx = binarySearch(p[i].second, i, N-1);
			Pf("(%lld, %lld) - (%lld, %lld)\n", p[i].first, p[i].second, p[idx].first, p[idx].second);
			ans += ((int)idx- i);
		}
		cout << ans << endl;
		cout << endl;
	}

	return 0;
}

