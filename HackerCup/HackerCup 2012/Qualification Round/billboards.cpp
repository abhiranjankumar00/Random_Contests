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

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

vs st;
vi num;
int W, H;

bool in(int sz, bool show = false) {
	int h = H, w = W, idx = 0;

	int fst, lst;
	if(show) {
		Pf("W = %d, H = %d, sz = %d\n", W , H, sz);
	}

	while(idx < st.size()) {

		fst = idx;

		if(sz > h)
			return false;
		w = W;
		if(st[idx].size()*sz > w)
			return false;
		h -= sz;
		w -= (st[idx].size()*sz);
		idx++;
		while(idx < st.size() && st[idx].size()*sz + sz <= w) {
			w -= (st[idx].size()*sz + sz);
			idx++;
		}
		lst = idx;

		if(show) {
			while(fst < lst) {
				Pf("%s ", st[fst].c_str());
				fst++;
			}
			cout << endl;
		}
	}

	return idx == st.size() ? true : false;
}

int solve() {
	int idx = 0;
	while(idx < 1111) {
		if(!in(idx))
			break;
		idx++;
	}
	idx--;
	return idx;
}

int bin_solve() {
	int left = 0, right = 1111;

	while(left < right) {
		int mid = left + right+1;
		mid /= 2;
		if(in(mid))
			left = mid;
		else
			right = mid-1;
	}
	return left;
}

int main()
{
	ST tmp;
	int test;
	cin >> test;
	getline(cin, tmp);
	forn(i, 2000)
		num.pb(i);

	forab(_test,1, test) {
		cin >> W >> H;
		getline(cin, tmp);
		SS ss(tmp);
		st.clear();
		while(ss >> tmp)
			st.pb(tmp);
			
		int ans = bin_solve();
//		int ans = solve();
//		in(ans, true);
		Pf("Case #%d: %d\n", _test, ans);
	}

	return 0;
}

