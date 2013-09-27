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

int ret;

int a[20];

void bt(int idx, int n, const vi & num) {

	if(idx == n) {
		int s1 = 0, s2 = 0, sum1 = 0, sum2 = 0;
		
		forn(i, n) 
			if(a[i])
				s1 ^= num[i], 	sum1 += num[i];
			else
				s2 ^= num[i], 	sum2 += num[i];

		if(s1 == s2 && s1 > 0 && s2 > 0 )
			ret = max(ret, max(sum1, sum2));

		return;
	}

	a[idx] = 0;
	bt(idx+1, n, num);
	a[idx] = 1;
	bt(idx+1, n, num);
}

int main()
{
	int test;
	cin >> test;

	forab(_test, 1, test) {
		ret = -1;
		int n;
		cin >> n;

		vi num(n);

		forn(i, n)
			cin >> num[i];

		bt(0, n, num);
		
		Pf("Case #%d: ", _test);
		if(ret < 0)
			cout << "NO\n";
		else
			cout << ret << endl;

	}

	return 0;
}
