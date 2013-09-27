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
	int N = 50;	// 1 <= N <= 50 

	time_t tm;
	time(&tm);
	srand(tm);
	cout << N << endl;
	vs s(N, "");

	forn(i, N) {
		forn(j, N)
			s[i] += (char)('a' + rand() % 26);
		cout << s[i];
		cout << endl;
	}

	int T = 50;		// T <= 1000

	cout << T << endl;

	forn(_T, T) {
		int x = rand() % N, y = rand() % N;
		int len = min(N - x, N - y);
		int xadd = rand() % 2, yadd = rand() % 2;

		if(xadd + yadd == 0)
			if(rand() % 2 == 0)
				xadd++;
			else
				yadd++;

		ST st = "";
		while(len--) {
			st += s[y][x];
			x += xadd;
			y += yadd;
		}
		cout << st.size() << " " << st << endl;
	}

/*
	forn(_T, T) {
		int m = 1 + rand() % N;
		cout << m << " ";
		forn(i, m)
			Pf("%c", 'a' + rand() % 26);
		cout << endl;
	}
*/	
	return 0;
}

