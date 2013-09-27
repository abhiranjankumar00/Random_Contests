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

#define read(n)		scanf("%lld", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

int64 ca[111], ta[111], cb[111], tb[111];
int64 N, M;

void input() {
	read(N);
	read(M);

	forn(i, N) {
		read(ca[i]);
		read(ta[i]);
	}

	forn(i, M) {
		read(cb[i]);
		read(tb[i]);
	}
/*
	cout << "Box: ";
	forn(i, N)
		Pf("%d:%d   ", ta[i], ca[i]);
	cout << endl;
	cout << "Gam: ";
	forn(i, N)
		Pf("%d:%d   ", tb[i], cb[i]);
	cout << endl;
	cout << endl;
*/
}

int64 ans[111][111];

int64 solve(int i, int j) {
	if(i >= N || j >= M)
		return 0;

	int64 &ret = ans[i][j];

	if(ret > -1)
		return ret;


	ret = 0;

	if(ta[i] == tb[j]) {
		ret = min(ca[i], cb[j]) + solve(i+1, j+1) ;
//
		ret = max(solve(i+1, j), ret);
		ret = max(ret, solve(i, j+1));

	}

	else {
		int64 t1 = solve(i+1, j);
		int64 t2 = solve(i, j+1);

		ret = max(t1, t2);
	}

	Pf("(%d, %d) = %lld\n", i, j, ret);

	return ret;
}

int main()
{
	int64 T;
	read(T);

	forab(test, 1, T) {
		input();
		CL(ans, -1);
		Pf("Case #%d: %lld\n", test, solve(0, 0));
	}
	
	return 0;
}

