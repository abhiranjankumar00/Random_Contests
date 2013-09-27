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

int N;
int loc[55];
int mxTime[55];

enum {L, R};

struct Node {
	int side, l, r, t;
	Node(int _s, int _l, int _r, int _t) : side(_s), l(_l), r(_r), t(_t) {}
	const bool operator <(const Node &x) const {
		if(side != x.side)
			return side < x.side;
		if(l != x.l)
			return l < x.l;
		if(r != x.l)
			return r < x.l;
		return t < x.t;
	}
};

map <Node, int> ret;
int solve(int side, int l, int r, int t) {
	int id = side == L ? l : r;

	if(t > mxTime[id])  {
		return -1;
	}

	if(l == 0 && r == N-1)  {
		return t;
	}

	Node nd(side, l, r, t);
	map <Node, int> :: iterator it = ret.find(nd);
	if(it != ret.end())
		return it->second;

	int ans = -1;
	if(l > 0) {
		int tmpAns = solve(L, l-1, r, t + loc[id] - loc[l-1]);
		ans = tmpAns;
	}
	if(r < N-1) {
		int tmpAns = solve(R, l, r+1, t + loc[r+1] - loc[id]);
		if(tmpAns > -1)
			if(ans == -1 || tmpAns < ans)
				ans = tmpAns;
	}
	return ret[nd]= ans;
}

int main()
{
	cin >> N;
	forn(i, N)
		cin >> loc[i];
	forn(i, N)
		cin >> mxTime[i];

	map <int, int> mt;
	forn(i, N) {
		if(mt.find(loc[i]) == mt.end())
			mt[loc[i]] = mxTime[i];
		else 
			mt[loc[i]] = min(mt[loc[i]], mxTime[i]);
	}
	N = mt.size();
	int idx = 0;
	tr(it, mt) {
		loc[idx] = it->first;
		mxTime[idx] = it->second;
		idx++;
	}
	
	int start;
	cin >> start;
	idx = lower_bound(loc, loc+N, start) - loc;

	int ans;
	if(idx == N )
		ans = solve(L, N-1, N-1, start - loc[N-1]);
	else if(loc[idx] == start || idx == 0) 
		ans = solve(R, idx, idx, loc[idx] - start);
	else {
		int tmpAns1 = solve(R, idx, idx, loc[idx] - start);
		int tmpAns2 = solve(R, idx-1, idx-1, start - loc[idx-1]);
		ans = tmpAns1;
		if(tmpAns2 != -1) 
			if(ans == -1 || ans > tmpAns2 )
				ans = tmpAns2;
	}
	
	cout << ans << endl;
	return 0;
}

