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

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

int main()
{
	int test;
	cin >> test;

	forab(_test, 1, test) {
		int n, idx = 0, oidx = 0, bidx = 0, opos = 1, bpos = 1, ret = 1, x;
		char ch;
		vi o, b, chance;

		cin >> n;

		forn(i, n) {
			cin >> ch >> x;

			if(ch == 'O')
				o.pb(x), 	chance.pb(0);
			else
				b.pb(x), 	chance.pb(1);
		}

		idx = ret = 0;

		while(true) {

			if(idx >= chance.size())	break;

			if(chance[idx] == 0) {
				
				assert(oidx < o.size());

				if(opos == o[oidx])
					oidx++, 	idx++;
				else 
					opos += opos < o[oidx] ? 1 : -1;

				if(bidx < b.size() && b[bidx] != bpos)
					bpos += bpos < b[bidx] ? 1 : -1;
			}
			else {

				assert(bidx < b.size());

				if(bpos == b[bidx])
					bidx++, 	idx++;
				else
					bpos += bpos < b[bidx] ? 1 : -1;

				if(oidx < o.size() && opos != o[oidx])
					opos += opos < o[oidx] ? 1 : -1;
			}

			ret++;
		}
		Pf("Case #%d: %d\n", _test, ret);
	}

	return 0;
}
