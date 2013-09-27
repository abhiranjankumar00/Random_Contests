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

const int sz = 1e6 + 10;

int rotate(int n) {
//	Pf("n = %d, ",n);
	int nZero = 0;
	while(n % 10 == 0) {
		nZero ++;
		n /= 10;
	}

//	Pf("nZero = %d, new n = %d\n", nZero, n);
	int ret = 0, t = n % 10;

	while(nZero--)
		t *= 10;

	n/=10;
	if(!n)
		return t;
	int nnZero = 0;
	while(n % 10 == 0) {
		nnZero++;
		n /= 10;
	}
	while(n) {
		ret = ret*10 + n%10;
		n/=10;
	}
	n = ret;
	
	while(n) {
		t = t*10 + n % 10;
		n /= 10;
	}
	while(nnZero--)
		t*=10;
//	Pf("t = %d\n", t);
	return t;
}

int sset[sz];

int main()
{
/*
	int n = 20;
	cout << n << endl;
	cout << rotate(n) << endl;

	return 0;

	int q;
	cin >> q; 
	{
//	while(cin >> q) {
		int p = q;

		do {
			cout << p << " ";
		}while((p = rotate(p)) != q);
		cout << endl;
	}

	return 0;
*/
//	cout << "#1\n";
	CL(sset, -1);
	int s = 0;

//	cout << "#2\n";
	forab(i,11, sz-1) if(sset[i] == -1) {
		s++;
//		cout << "#2.1\n";

		int l = i;
//		cout << "#2.2\n";
//		cout << l << " ";
//		cout << "#2.3\n";
		do {
			sset [l] = s;
//			cout << l << endl;
		} while( (l = rotate(l)) != i);
//		cout << "#2.4\n";
	}

//	cout << "#3" << endl;
//	map <int, vi> m;
	map <int, int> mm;
	
	int test;
	cin >> test;
	forab(_test, 1, test) {
		int a = 1111, b = 2222;
		cin >> a >> b;
		if(a > b)
			swap(a, b);
		mm.clear();

		forab(i, max(11, a), b) {
			mm[sset[i]]++;
/*
			if(m.find(sset[i]) != m.end()) {
				m[sset[i]].pb(i);
			}
			else {
				m[sset[i]] = vi(1, i);
			}
*/
		}
		int64 ret = 0ll;

		tr(it, mm) {
			ret += (1ll * it->second * (it->second-1))/2;
		}
/*
		tr(it, m) if(it->second.size() > 1){ 
			ret += it->second.size() * 1ll* (it->second.size() - 1)/2;
			tr(jt, it->second)
				cout << *jt << " ";
			cout << endl;
		}
*/

		Pf("Test %d: %lld\n", _test, ret);
		//cout << ret << endl;
	}
	return 0;
}

