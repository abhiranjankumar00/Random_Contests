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

const int sz = 33554432;

int Ans[sz];
int dist[sz];
bool vis[sz];

int64 a, b, c, n;
int begin;

int dfs(int64 u, int par = -1) { 
	assert(u >= 0 && u < n);
//	cout << u << " ";
	if(Ans[u] > -1)
		return Ans[u];

	if(vis[u] == true) {
		begin = u;
		Ans[u] = dist[par] - dist[u] + 1;
		return Ans[u];
	}
	vis[u] = true;

	if(par != -1)
		dist[u] = dist[par] + 1;
	else
		dist[u] = 0;


	int64 v = ((((a*u)%n + n) * u) % n + n) %n;
	v = ((v + (b*u)%n + n) % n + n ) %n;
	v = ((v+c)%n + n )% n;

//	int64 v = edge(u);

	int dd = dfs(v, u);

	if(begin > -1)
		Ans[u] =  dd;
	else
		Ans[u] = dd + 1;

	if(begin == u)
		begin = -1;
	
	return Ans[u];
}

int main()
{
	int test = 1;
	cin >> test;

	forn(_test, test) {
		cin >> a >> b >> c >> n;
		int ret = 0;
		CL(vis, 0);
		CL(Ans, -1);
		begin = -1;
		
		forn(i, n) {
			ret = max(ret, dfs(i));
//			cout << i << " " << dfs(i) << endl;
		}
		cout << ret << endl;
	}

	return 0;
}

