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

const int mx = 1e5;
const int MAXSCORE = 200;

void dfs(int u, vector <bool> &vis, vector <vector <int> >&G) {
	if(vis[u])
		return;
	vis[u] = true;
	tr(it, G[u])
		dfs(*it, vis, G);
}

int main(int argc, char **argv)
{
	assert(argc==3);
// Input Check
	ifstream in(argv[1]);

	set < ii >edges;
	int N, M;

	in >> N >> M;

	assert(1 <= N && N <= mx);
	assert(0 <= M && M*1ll <= min(mx*1ll, 1ll*N*(N-1)/2));
	vector < vector <int> > G(N);

	forn(i, M) {
		int a, b;
		in >> a >> b;
		if(a > b)
			swap(a, b);
		assert(a!=b);
		assert(edges.find(mp(a, b)) == edges.end());
		edges.insert(mp(a, b));
		G[a].pb(b); G[b].pb(a);
	}

	vector <bool> vis(N, false);
	dfs(0, vis, G);
	forn(i, N)
		assert(vis[i]);

//===========================
// Output Check

	ifstream out(argv[2]);
	int P;

	out >> P;
	assert(P >= 0 && P <= M);
	set < int > V;

	forn(i, P) {
		int u;
		out >> u;
		assert(u >= 0 && u < N);
		assert(V.find(u) == V.end());
		V.insert(u);
	}

	assert(P == V.size());

	fill(all(vis), false);
	
	tr(it, V) {
		int u = *it;
		vis[u] = true;
		tr(it, G[u])
			vis[*it] = true;
	}

	forn(i, N)
		assert(vis[i]);

	double score = (N - P*1.0)/N * MAXSCORE;
	cout << score << endl;
	
	return 0;
}

