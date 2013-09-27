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
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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
	int n;
	cin >> n;
	int64 cnt[2000];
	const int64 mod = 4207849484LL;

	forab(loop, 1, n) {
		int m;
		ST st;
		cin >> m >> st;
		st = " " + st;
		fill(cnt, cnt+2000, 0);

		cnt[0] = 1;

//		cout << st << endl << endl;
		forab(i, 1, st.size() - 0) {
//			cout << st.substr(i) << " = " << cnt[i-1] << endl;
			int j = 1;
			while(i+j <= st.size()) {
				int t = atoi(st.substr(i, j).c_str());
				if (t < 1 || t > m)
					break;
				cnt[i+j-1] = (cnt[i+j-1] + cnt[i-1]) % mod;
//				Pf("i = %d, j = %d, substr = %s\n", i, j, st.substr(i, j).c_str());
				j++;
			}
//			cout << endl;
		}


		Pf("Case #%d: %lld\n", loop, cnt[st.size()-1]);
//		cout << endl << endl ;
	}

	return 0;
}

