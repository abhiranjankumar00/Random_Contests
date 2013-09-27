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



int main()
{
	int n;
	cin >> n;
	ST st;
	getline(cin, st);
	forab(test, 1, n) {
		map <char, int> m;
		getline(cin, st);
//		cin >> st;
//		for(char ch : st)
		forn(i, st.size()) {
			char ch = st[i];
			m[ch]++;
		}

		int ans = 123456;
		ST t = "HAKERUP";
		forn(i, t.size()) {
			char ch = t[i];
//		for(char ch : "HAKERUP") if(ch != '\0') {
//			Pf("%c : %d\n", ch, m[ch] );
			ans = min(ans, m[ch]);
		}

		char ch = 'C';
//		Pf("%c : %d\n", ch, m[ch] );
		ans = min(ans, m[ch]/2);
		Pf("Case #%d: %d\n", test, ans);
	}

	return 0;
}

