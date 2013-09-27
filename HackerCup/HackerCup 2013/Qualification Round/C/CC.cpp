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
typedef vector<int> 		vi;
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

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

vi arr;
int K, N;

int absentee(int l, int r) {
	set <int> st;
	forab(i, l, r)
		st.insert(arr[i]);
	forab(i, 0, K)
		if(st.find(i) == st.end()) {
			return  i;
		}
}

void solve(int test) {
	int64 b, c, r;
	cin >> N >> K;

	arr.clear();
	vi period1, period2;
	//arr = vi(2*K+1);
	arr = vi(K);
	cin >> arr[0] >> b >> c >> r;;

	forab(i, 1, K-1)
		arr[i] = (b*arr[i-1] + c) % r;
	forab(k, K, 2*K) {
//	forab(k, K, 2*K)
		arr.pb( absentee(k-1 - K+1, k-1) );
		period1.pb(arr.back());
	}
/*
	forab(k, 2*K+1, 3*K+1) {
		arr.pb( absentee(k-1 - K+1, k-1) );
		period2.pb(arr.back());
	}
	tr(it, period1)
		Pf("%2d ", *it);
	cout << endl;
	tr(it, period2)
		Pf("%2d ", *it);
	cout << endl;
*/
/*
	DEBUG(arr.size());
	forn(i, arr.size()) {
//	forn(i, 2*K+1) {
		write(arr[i]);
		if(i == K-1)
			cout << "| ";
	}
	cout << endl;
*/
	N-=K;
	N--;

	cout << period1[ N%(K+1)] << endl;
	cout << endl;
}

int main()
{
	int Test;
	cin >> Test;
//	Test = 1;

	forab(test, 1, Test)
		solve(test);

	return 0;
}

