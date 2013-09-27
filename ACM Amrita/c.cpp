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
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int) b; i>=loop_ends_here; i--)

#define read(n)	scanf("%d",&n)

int main() {
	int test;
	read(test);

	while(test--) {
		int n;
		read(n);

		if(n == 1) {
			int tmp;
			read(tmp);
			Pf("%d\n", tmp <0 ? -tmp + 1 : 1);
			continue;
		}

		int tmp, ans = 0, cur, mn = 1<<20;

		cur = 0;
		forn(i, n) {
			read(tmp);
			cur += tmp;
			mn = min(mn, cur);
		}
		Pf("%d\n", mn < 0 ? -mn + 1 : 1);
	}

	return 0;
}

/*
int main()
{
	int test;
	cin >> test;

	while(test--) {
		int cur, mn = 1000000, n;

		cin >> n;
		int tmp;
		cur = 0;

		int ans = 0;

		forn(_n, n){
			Sf("%d", &tmp);
			cur += tmp;
			if(cur <= 0)
				ans = min(ans, cur);
		}
//		cout << ans << endl;
//		if(ans >= 0)
//			cout << 0 << endl;
//		else
			cout << -ans + 1 << endl;
//		cout << endl;
/ *
		int ans;
//		cout << mn << endl;
		if(mn >= 1)
			ans = 0;
		else
			ans = abs(mn) + 1;

		Pf("%d\n", ans);
//		cout << endl;		// remove;
//
* /
	}

	return 0;
}
*/
