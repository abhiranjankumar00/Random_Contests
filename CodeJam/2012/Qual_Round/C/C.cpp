//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

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

int main()
{
/*
	3
		ejp mysljylc kd kxveddknmc re jsicpdrysi
		rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
		de kr kd eoya kw aej tysr re ujdr lkgc jv


		Output
		Case #1: our language is impossible to understand
		Case #2: there are twenty six factorial possibilities
		Case #3: so it is okay if you want to just give up
*/		ST as = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		ST bs = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		ST cs = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

		
		ST aa = "our language is impossible to understand";
		ST bb =  "there are twenty six factorial possibilities";
		ST cc = "so it is okay if you want to just give up";

		map <char, char> m;

		forn(i, as.size())
			m[as[i]] = aa[i];

		forn(i, bs.size())
			m[bs[i]] = bb[i];

		forn(i, cs.size())
			m[cs[i]] = cc[i];

		set <char> s;
		m['z'] = 'q';
		m['q'] = 'z';
/*
		for(auto &x: m) {
			cout << x.first << " " << x.second << endl;
			s.insert(x.second);
		}
		cout << endl;

		for(auto &x: s)
			cout << x << " ";
		cout << endl;
*/
		int T;cin >> T;
		ST t;
		getline(cin, t);

		forn(_t, T) {
			ST s;
			getline(cin, s);

			Pf("Case #%d: ", _t + 1);
			forn(i, s.size())
				cout << m[s[i]];
			cout << endl;
		}

	return 0;
}

