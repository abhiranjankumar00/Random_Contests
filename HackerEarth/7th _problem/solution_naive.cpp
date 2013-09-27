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

int main()
{
	int N, M;
	cin >> N >> M;
	vector <set <int> > G(N);
	set < ii > edges;

	forn(i, M) {
		int u, v;
		cin >> u >> v;
		if(u > v)
			swap(u, v);
		edges.insert(mp(u, v));
		G[u].insert(v);
		G[v].insert(u);
	}

	set <int> V;

	while(!edges.empty()) {
		ii edge = *edges.begin();
		int u = edge.first, v = edge.second;
		edges.erase(edge);
		V.insert(u);
		V.insert(v);

		tr(it, G[u]) {
			int x= min(*it, u), y = max(*it, u);
			//assert(edges.find(mp(x, y)) != edges.end());

			edges.erase(mp(x, y));
			G[*it].erase(u);
		}
		tr(it, G[v]) {
			int x= min(*it, v), y = max(*it, v);
			//assert(edges.find(mp(x, y)) != edges.end());

			edges.erase(mp(x, y));
			G[*it].erase(v);
		}
	}
	cout << V.size() << endl;
	tr(it, V)
		cout << *it << " ";
	cout << endl;

	return 0;
}

