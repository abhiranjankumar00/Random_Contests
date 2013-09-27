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

#define X first
#define Y second

const int mid = 1010;
bool vis[2111][2111];
ii pt[2511];
ii st, fin;

struct Node {
	int tm, X, Y;
	Node(int t, int x, int y) {
		tm = t, X = x, Y  = y;
	}
	const bool operator <(const Node &x) const {
		return this->tm > x.tm;
	}
};

void solve() {
	CL(vis, 0);
	int N;
	read(N);

	forn(i, N) {
		Sf("%d %d", &pt[i].X, &pt[i].Y);
		pt[i].X += 1001;
		pt[i].Y += 1001;
	}
	Sf("%d %d", &st.X, &st.Y);
	Sf("%d %d", &fin.X, &fin.Y);
	st.X += 1001;
	st.Y += 1001;
	fin.X += 1001;
	fin.Y += 1001;
	pt[N].X = fin.X;
	pt[N].Y = fin.Y;
	N++;
/*
	Pf("Pts are : ");
	forn(i, N)
		Pf("(%d, %d) ", pt[i].X, pt[i].Y);
	cout << endl;
	Pf("Start = (%d, %d)\n", st.X, st.Y);
	Pf("fin   = (%d, %d)\n", fin.X, fin.Y);
*/

	priority_queue <Node> pq;

	pq.push(Node(0, st.X, st.Y));

	while(pq.empty() == false) { Node nd = pq.top();
		pq.pop();
		int x = nd.X, y = nd.Y, t = nd.tm;

	//	Pf("(%d: %d, %d)\n", t, x, y);

		if(vis[x][y] == true)
			continue;

		vis[x][y] = true;

		if(x == fin.X && y == fin.Y) {
			Pf("%d\n", t);
			return;
		}

		forn(i, N)	if(vis[pt[i].X][pt[i].Y] == false) {
			int d = t + (x-pt[i].X) * (x-pt[i].X) + (y - pt[i].Y)*(y - pt[i].Y);
//			Pf("Pushed (%d: %d, %d)\n", d, pt[i].X, pt[i].Y);
			pq.push(Node(d, pt[i].X, pt[i].Y));
		}
	}
//	cout << -1 << endl;
}

int main()
{
	int T;
	read(T);

	while(T--) {
		solve();
	}

	return 0;
}

