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

const int sz = 1e3 + 111;

int V, mod;
int S[sz];
//int cnt[sz][sz];
//int mx[sz][sz];
int cnt[555][1110];
int mx[555][1110];

void solve() {
	//cin >> V >> mod;
	read(V);
	read(mod);

	assert(V >= 1 && V <= 500);
	assert(mod >= 1 && mod <= 1000);
	forn(i, V)
		read(S[i]);
	//	cin >> S[i];

	CL(cnt, -1);
//	CL(cnt, 0);
	cnt[0][0] = 0;
	CL(mx, 0);

	forn(i, V) {
		forn(j, mod) {
			if(cnt[i][j] > -1) {
				// Without including i'th box;
//				cnt[i+1][j] = max(cnt[i][j], cnt[i+1][j]);
				if(cnt[i][j] > cnt[i+1][j]) {
					cnt[i+1][j] = cnt[i][j];
					mx[i+1][j] = mx[i][j];
				}
				else if(cnt[i][j] == cnt[i+1][j])
					mx[i+1][j] = max(mx[i+1][j], mx[i][j]);

				// Including i'th box
				int sum = (j + S[i]) % mod;
				assert(sum >= 0 && sum < mod);

//				cnt[i+1][sum] = max(cnt[i+1][sum], cnt[i][j] + 1);
				if(cnt[i][j] + 1 > cnt[i+1][sum]) {
					cnt[i+1][sum] = cnt[i][j] + 1;
					mx[i+1][sum] = mx[i][j] + S[i];
				}
				else if(cnt[i][j]+1 == cnt[i+1][sum]) {
					mx[i+1][sum] = max(mx[i+1][sum], mx[i][j] + S[i]);
				}
			}
		}
	}
	Pf("%d %d\n", cnt[V][0], mx[V][0]/mod);
}

int main()
{
	int test;
	read(test);

	while(test--)
		solve();

	return 0;
}

