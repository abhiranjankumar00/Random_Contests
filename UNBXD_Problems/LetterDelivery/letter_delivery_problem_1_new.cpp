//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

const int INF = 1e8 + 1e8;
int dp[2][55][55];
int add[55], mxTime[55];
int N;
int start;
enum {L = 0, R = 1};

int solve(int side, int l , int r) {
	int &ret = dp[side][l][r];
	if(ret > -1)
		return ret;
	ret = INF;
	if(l == r) {
		ret = abs(start - add[l]);
		if(ret > mxTime[l])
			ret = INF;
		return ret;
	}
	if(side == L) {
		ret = min(solve(L, l+1, r) + add[l+1] - add[l], solve(R, l+1, r) + add[r] - add[l]);
		if(ret > mxTime[l])
			ret = INF;
		return ret;
	}
	ret = min(solve(L, l, r-1) + add[r] - add[l], solve(R, l, r-1) + add[r] - add[r-1]);
	if(ret > mxTime[r])
		ret = INF;
	return ret;
}

int main()
{
	cin >> N;
	forn(i, N)
		cin >> add[i];
	forn(i, N)
		cin >> mxTime[i];
	cin >> start;
	
	ii tmp[55];

	forn(i, N)
		tmp[i] = mp(add[i], mxTime[i]);
	sort(tmp, tmp+N);
	forn(i, N) {
		add[i] = tmp[i].first;
		mxTime[i] = tmp[i].second;
	}
	
	CL(dp, -1);
	int ret = min(solve(L, 0, N-1), solve(R, 0, N-1));
	ret =  ret == INF ? -1 : ret;
	cout << ret << endl;
        
	return 0;
}

