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

const int64 sz = 5001, ssz = 10000010;
int64 grid[sz][sz], cnt[ssz];

int main()
{
	forn(i, ssz)
		cnt[i] = i;

	forn(i, sz) {
		forn(j, sz) {
			if(i == 0 || j == 0)
				grid[i][j] = 1;
			else if(grid[i-1][j] >= ssz || grid[i][j-1] >= ssz)
				grid[i][j] = ssz;
			else
				grid[i][j] = grid[i-1][j] + grid[i][j-1];

			int64 t = grid[i][j];
			if(t >= ssz)
				continue;
			if(1*i + j < cnt[t] && i+j > 0)
				cnt[t] = 1*i+j;
		}
	}
/*
	forab(i, 0, 100)
		Pf("%d -> %lld\n",i, cnt[i]);
*/
	int R, S;
	read(R);

	forab(r, 1, R) {
		read(S);
		int64 ans = S+1;
		for(int i = 1; i*i <= S; i++)
			if(S % i == 0)
				ans = min(ans, cnt[i]+cnt[S/i]);
		Pf("Case #%d: %lld\n", r, ans);
	}
	return 0;
}

