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

int64 cnt[12];
int64 ten[12], five[12], six[12];

void init() {
	ten[0] = five[0] = six[0] = 1;
	forab(i, 1, 11) {
		ten[i] = 10*ten[i-1];
		five[i] = 5*five[i-1];
		six[i] = 6*six[i-1];
	}
	cnt[0] = 0;
	cnt[1] = 5;
	int64 fiveTen[12] = {};

	forab(n, 2, 11) {
		int64 tmp = 0;
		forab(r, 2, n)
			tmp += five[r]*ten[n-r];
		fiveTen[n] = tmp;
//		cnt[n] = 4*ten[n-1] + tmp + cnt[n-1];
		cnt[n] = 4*ten[n-1] + tmp;
	}
}

string st;

int64 solve(int id = st.size()-1) {
	if(id < 0)
		return 0;

	int64 ret = 0;
	if(id == 0) {
		forab(i, 0, st[id]-'0')
			if(i % 2 == 0)
				ret++;
/*
		string tmp = st.substr(0, id+1);
		reverse(all(tmp));
		cout << tmp << ": " << ret << endl;;
*/
		return ret;
	}

	forn(i, st[id] - '0') {
		if(i == 0) {
			forab(r, 1, id)
				ret += cnt[r];
		}
		else if(i % 2 == 0 )
			ret += ten[id];
		else { 
			int n = id;
			forab(r, 1, n)
				ret += five[r]*ten[n-r];
		}
	}
	if((st[id] - '0') % 2 == 0) {
		string tmp = st.substr(0, id);
		reverse(all(tmp));
		ret += atoi(tmp.c_str());
		ret++;
	}
	else
		ret += solve(id-1);
/*	
	string tmp = st.substr(0, id+1);
	reverse(all(tmp));
	cout << tmp << ": " << ret << endl;;
*/
	return ret;
}

int doit(string str) {
	::st = str;
//	DEBUG(st);
	reverse(all(st));
	return solve();
}

int main()
{
	init();
	int T;
	cin >> T;

	while(T--) {
		int L, R;
		cin >> L >> R ;
		L--;
		stringstream ss;
		ss << L << " " << R;
		string ll, rr;
		ss >> ll >> rr ;
		cout << doit(rr) - doit(ll) << endl;
	}

	return 0;
}

