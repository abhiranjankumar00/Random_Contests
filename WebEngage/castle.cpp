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
#define	eps		1e-9

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

const int sz = 1e3 + 111;
bool vis[sz][sz];
int D[sz][sz];

struct triplet {
	int x, y, t;
	const bool operator < (const triplet &a) const {
		return a.t < t;
	}
	void set(int a, int b, int c) {
		x = a, y = b, t = c;
	}
	triplet() {
	}
	triplet(int a, int b, int c) {
		set(a, b, c);
	}
};

const int X[] = {1, -1, 0, 0};
const int Y[] = {0, 0, 1, -1};

void solve(int N, int M) {
	assert(N > 0 && N <= 1000);
	assert(M > 0 && M <= 1000);

	forn(i, N)
		forn(j, M) {
			read(D[i][j]);
			vis[i][j] = false;
		}
	int x, y, t;
	cin >> x >> y >> t;
	x--;	y--;
	assert(x >= 0 && x < N);
	assert(y >= 0 && y < M);

	priority_queue <triplet> pq;
	pq.push(triplet(0, 0, D[0][0]));

	while(pq.empty() == false) {
		triplet nd = pq.top();
		pq.pop();

		if(nd.x == x && nd.y == y) {
			cout << "YES\n" << t - nd.t << endl;
			return;
		}

		if(vis[nd.x][nd.y] == true)
			continue;
		vis[nd.x][nd.y] = true;

		
		forn(i, 4) {
			int xx = nd.x + X[i], yy = nd.y + Y[i];
			if(xx >= 0 && xx < N && yy >= 0 && yy < M && vis[xx][yy] == false && nd.t + D[xx][yy] <= t) {
				pq.push(triplet(xx, yy, D[xx][yy] + nd.t));
			}
		}

	}
	cout << "NO" << endl;

}

int main()
{
	int test;
	cin >> test;

	while(test--) {
		int N, M;
		cin >> N >> M;
		solve(N, M);
	}

	return 0;
}

