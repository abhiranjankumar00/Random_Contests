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
typedef vector<int64> 		vi;
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
#define	eps		1e-9

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

#define read(n)		scanf("%lld", &n)
#define write(n)	printf("%lld ", n)
#define writeln(n)	printf("%lld\n", n)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/
const int sz = 1e5 + 111;
int64 arr[sz], sum[sz];
int64 N, T;

int main()
{
	cin >> N >> T;

	forn(i, N) {
		read(arr[i]);
		sum[i] = arr[i] + (i == 0 ? 0 : sum[i-1]);
	}

	forn(i, N)
		write(arr[i]);
	cout << endl;
	forn(i, N)
		write(sum[i]);
	cout << endl;

	long double ans = 0;
	int64 totElements = 0;

	forn(i, N) {
		if(arr[i] > T)
			continue;
		int64 sm = T + (i == 0 ? 0 : sum[i-1]);
		int idx = upper_bound(sum + i, sum + N, sm) - sum;
		idx--;
		totElements += idx - i + 1;
		Pf("%d-%d : sm = %lld\n", i, idx, sm);
	}
	double aans = 0;
	if(totElements > 0)
		aans = totElements*2.0/(N*(N+1));
	DEBUG(aans);
	return 0;

	cout << endl << endl;

	int totSum = 0, totLen = 0;
	forn(i, N)	forab(j, i, N-1) {
		int sm = sum[j] - (i>0 ? sum[i-1] : 0);
		if(sm <= T) {
			Pf("[%d, %d], sum = %d, len = %d\n", i, j, sm, j-i+1);
			totLen += j-i+1;
			totSum += sm;
		}
	}
	DEBUG(totSum);
	DEBUG(totLen);

	return 0;
}

