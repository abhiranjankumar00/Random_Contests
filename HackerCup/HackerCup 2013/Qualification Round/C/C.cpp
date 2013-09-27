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

vector < ii > p;
int K, N;
vi arr, uni;

int numbersLessThan(int n) {
	return lower_bound(all(uni), n) - uni.begin();
}
/*
int numbersGreaterThan(int n) {
	return arr.end() - upper_bound(all(arr), n);
}
*/
int idx(int n) {
	return K + n - numbersLessThan(n);
}

int findNext(int n, int l = 0, int r = p.size()-1) {
	if(l == r)
	       	return p[l].first <= n && n <= p[r].second ? p[l].second +1 : n;
	int mid = (l+r)/2;
	return p[mid].second >= n ? findNext(n, l, mid): findNext(n, mid+1, r);;
}

int binarySearch(int l = 0, int r = 100) {
	if(l == r)
		return findNext(l);

	int mid = (l+r)/2;
	int id = idx(mid);
	//Pf("l = %d, r = %d, mid = %d, id = %d\n", l, r, mid, id);

	if(id >= N)
		return binarySearch(l, mid);
	else
		return binarySearch(mid+1, r);
}

void solve() {
	arr.clear();
	p.clear();
/*
	cin >> K >> N;
	arr = vi(K);
	forn(i, K)
		cin >> arr[i];
*/
	cin >> N >> K;
	int64 b, c, r;
	arr = vi(K);
	cin >> arr[0] >> b >> c >> r;

	forab(i, 1, K-1)
		arr[i] = (arr[i-1]*b + c) % r;
	forn(i, K)
		write(arr[i]);
	cout << endl;

	sort(all(arr));
	uni.pb(arr.front());
	p.pb(mp(arr[0], arr[0]));
	
	forn(i, K) {
		if(arr[i] != uni.back())
			uni.pb(arr[i]);
		if(arr[i] == p.back().second)
			;
		else if(arr[i] == p.back().second+1)
			p.back().second++;
		else
			p.pb(mp(arr[i], arr[i]));

	}

	forn(i, K)
		write(arr[i]);
	cout << endl;
	forn(i, uni.size())
		write(uni[i]);
	cout << endl;

	
	tr(it, p)
		Pf("(%d, %d) ", it->first, it->second);
	cout << endl;

	int M = N;
	forab(i, K, N) {
		N = i;
		Pf("arr[%d] = %d\n", N, binarySearch());
	}

	N = M;
	N--;
	if(N < K)
		DEBUG("hahaha");
	else
		cout << binarySearch() << endl;



}

int main()
{
	int Test;
	cin >> Test;
	Test = 1;

	forab(test, 1, Test) {
		solve();
	}

	return 0;
}

