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
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef string ST;
typedef stringstream SS;

#define Pf	printf
#define	Sf	scanf

#define	ep	1e-9
#define	CL(a, b)	memset(a, b, sizeof(a))

#define pb	push_back
#define mp	make_pair
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

char ch;

unsigned int CountOne(unsigned int n)
{
	int ret = 0;

	rep(i, 31, 0)
	{
		if( (n & (1 << i)) !=  0 )
		{
			++ret;
//			cout << 1;
		}
//		else	cout << 0;
	}
//	cout << endl << ret << endl;

	if(ch == 'a' )	ret++;

	if(ret&1)	// odd
	{
		Pf("a");
//		cout << 'a';
		
	}
	else
	{
		Pf("b");
//		cout << 'b' ;
	}

	return ret;
}


int main()
{
	int t, cnt, i;


	cin >> t;
	unsigned int n, k;

	forn(_t, t)
	{
		if(_t)
			Pf("\n");
//		cin >> ch >> n >> k;
		Sf("%c %u %u", &ch, &n, &k);
//		Pf("#%d : ch = %c , n = %d , k = %d\n", _t, ch, n, k);
		CountOne(k-1);
//		--k;
//		k = _t;
/*		cnt = 0;

		for(i = 31; i > -1; i--)
			if( k & (1 << i))
				cnt++;

		if(ch == 'a')	cnt++;

		if(cnt&1)
			Pf("a");
		else
			Pf("b");
*/
//c		cin >> ch >> n >> k;

//		cout << ch << endl;
		
//		CountOne(k-1);
//		CountOne(_t);
	}

	return 0;
}
