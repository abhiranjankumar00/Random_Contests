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
#include <numeric>	// +1
#include <cassert>
#include <utility>	// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;		// Never used it :X
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

// WHY YOU DON'T WORK :X
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)	// \m/ Defined 3rd time.
#define forn(i, n)	for(int i = 0, __even_my_fish_codes_better__ = (int)n; i <  __even_my_fish_codes_better__; i++)
#define forab(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i <= __even_my_fish_codes_better__; i++)
#define rep(i, a, b)	for(int i = a, __even_my_fish_codes_better__ = (int)b; i >= __even_my_fish_codes_better__; i--)

#define PI		M_PI			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define E 		M_E			// Fish!!! Fails on some compilers (probably MSVC++ & some GNU C++).
#define endl		("\n")								// Really required?

#define	all(c)		(c).begin(), (c).end()
#define	cl(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())			// Map & Set // Shh... copied from topcoder article. Never used.
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	// Vector & List // Shh... copied from topcoder article. Never used.

#define	Sf		scanf
#define	Pf		printf
#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", (int)n)
#define writeln(n)	printf("%d\n", (int)n)

#if (0 or defined ONLINE_JUDGE)				// Why topcoder doesn't use it. :(
	#define	debug
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

const int sz = 1e5;
//const int sz = 100;
int par[sz];

int findSet(int u) {
	return par[u] = u == par[u] ? u : findSet(par[u]);
}

void mergeSet(int u, int v) {
	int pu = findSet(u), pv = findSet(v);
	if(pu < pv)
		par[pv] = pu;
	else
		par[pu] = pv;
}

int main()
{
	time_t tm;
	time(&tm);
	srand(tm);

	int N = rand() % sz + 1;
	int M = min(sz/100ll, (rand() % (1ll*N*(N-1)/2))/100ll + 1);

	forn(i, N)
		par[i] = i;

	set < ii > edges;
	forn(i, M) {
		int u = rand() % N, v = rand() % N;
		if(u > v)
			swap(u, v);
		if(u == v)
			continue;
		edges.insert(mp(u, v));
	}

	int baseVertex = rand() % N;
	forn(i, N) {
		if(findSet(i) != findSet(baseVertex)) {
			mergeSet(i, baseVertex);
			int u = min(baseVertex, i), v = max(baseVertex, i);
			edges.insert(mp(u, v));
		}
	}


	M = edges.size();
	assert(edges.size() >= 0 && edges.size() <= sz);

	cout << N << " " << M << endl;
	tr(it, edges)
		cout << it->first << " " << it->second << endl;

	return 0;
}

