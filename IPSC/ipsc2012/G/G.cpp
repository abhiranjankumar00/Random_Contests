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

const int sz = (1<<25);
bool vis[sz];

int cnt ;
int64 a, b, c, n;

void dfs(int64 v) {
	if(vis[v])	return;
//	cout << v << " ";
	vis[v] = true;
	cnt++;

	int64 u = (((((a*v)%n)*v) + (b*v)%n) % n + c ) % n;
	dfs(u);
}

int main()
{
	int test;
	read(test);

	forn(_test, test) {
		cin >> a >> b >> c >> n;
		CL(vis, 0);
		int ret = 0;

//		cout << "Test: " << _test << endl;
		forab(i,1, n-1)	if(!vis[i]) {
			if(1ll*i == c)	continue;
			cnt = 0;
			dfs(i);
			ret = max(ret, cnt);
//			cout << endl;
		}

		CL(vis, 0);
		cnt = 0;
		dfs(0);
		ret = max(ret, cnt);

		CL(vis, 0);
		cnt = 0;
		dfs(c);
		ret = max(ret, cnt);


		cout << ret << endl;
//		cout << endl;
	}

	return 0;
}

