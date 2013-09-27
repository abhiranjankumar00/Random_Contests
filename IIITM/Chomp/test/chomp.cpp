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

int dp[111][111][111];

enum {P, N};

int PN(int row1, int row2, int row3) {
	assert(row1 >= 0 && row1 <= 100);
	assert(row2 >= 0 && row2 <= row1);
	assert(row3 >= 0 && row3 <= row2);

	int &ret = dp[row1][row2][row3];

	if(ret > -1)
		return ret;

	ret = P;

	rep(r3, row3-1, 0)
		if(PN(row1, row2, r3) == P)
			return ret = N;

	rep(r2, row2-1, 0)
		if(PN(row1, r2, min(r2, row3)) == P)
			return ret = N;

	rep(r1, row1-1, 0)
		if(PN(r1, min(r1, row2), min(r1, row3)) == P)
			return ret = N;

	return ret = P;
}

int main()
{
	CL(dp, -1);
	dp[0][0][0] = N;
	dp[1][0][0] = P;

	int T;
	cin >> T;
	assert(T > 0 && T <= 1e4);

	while(T--) {
		int row1, row2, row3;
		cin >> row1 >> row2 >> row3;
		assert(0 <= row1 && row1 <= 100);
		assert(0 <= row3 && row3 <= row2 && row2 <= row1);

		cout << (PN(row1, row2, row3) == N ? "WIN" : "LOSE") << endl;
	}

	return 0;

	forab(row1, 1, 8)
		forab(row2, 0, row1)
			forab(row3, 0, row2)
				if(PN(row1, row2, row3) == P)
					Pf("%d %d %d\n", row1, row2, row3);
	
	return 0;
}

