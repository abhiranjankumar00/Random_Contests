//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

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

vvi G;
vi ord;
bool in[111] = {false};
//map <int, int> v;
int v[111];
int Ans[111];

void dfs(int n) {
	if(in[n])
		return;
	in[n] = true;
	for(auto &x: G[n])
		dfs(x);
	ord.pb(n);
}

int solve(int a) {
	int &ret = Ans[ord[a]];

	if(ret > -1)
		return ret;

	ret = 1;

	forab(b, a+1, ord.size() -1 ) {
//		Pf("a = %d, b = %d, ord[a] = %d, ord[b] = %d, v[ord[a]] = %d, v[ord[b]] = %d, cont = %d\n", a, b, ord[a], ord[b], v[ord[a]], v[ord[b]], max(v[ord[a]], v[ord[b]]) < b-a ? 1: 0 );
//		cout << endl;
		if( max(v[ord[a]], v[ord[b]]) < b-a ) {
			ret = max(ret, 1+solve(b));
		}
	}
	return ret;
}

int main()
{
	G.clear();	ord.clear();	//v.clear();
	CL(Ans, -1);

	int N;
	read(N);
	G.resize(N);

	forn(i, N) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}

	forn(i, N-1) {
		int u, v;
		cin >> u >> v;
		u--;	v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	forn(i, N)
		dfs(i);
	reverse(all(ord));
/*
	forn(i, N)	solve(i);
	forn(i, N)
		Pf("%d -> %d\n", ord[i], solve(i));
	cout << endl;
*/
	int ans = 0;
	forn(i, N)
		ans = max(solve(i), ans);
	writeln(ans);

	return 0;
}

