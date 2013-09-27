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
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
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

// a^x  mod m
int64 pow(int64 a, int64 x, int64 m) {
	if(x == 0)
		return 1ll;
	int64 ret = pow(a, x/2, m);
	ret = (ret*ret)%m;

	if(x % 2 == 1)
		ret = (ret * a) % m;

	return ret;
}

/* 	h*(k^x) + m*y = d
 * => 	h*(k^x) = d	(mod m)
 * 	find x using discrete logarithm
*/
int64 solve(int64 h, int64 k, int64 m, int64 d) {
	int64 n = (int64)sqrt(m + 0.0) + 1;
	int64 ret = -1LL;
	map <int64, int64> vals;
	vals.clear();

	int64 kn = pow(k, n, m);	// kn = k^n
	int64 cur = (h*kn) % m;		// cur = h * (k^n)

	for(int64 p = 1; p <= n; p++) {
		if(vals.find(cur) == vals.end())
			vals[cur] = p;
		cur = (cur * kn) % m;		// cur = h * (k^n)^p
	}

	cur = d;				// cur = d
	for(int64 q = 0; q <= n; q++) {
		if(vals.find(cur) != vals.end()) {
			if(ret < 0)
				ret = vals[cur]*n - q;
			else
				ret = min(ret, vals[cur]*n-q);
		}

		cur = (cur * k) % m;		// cur = d * k^q
	}

	return ret;
}

int main()
{
	int64 h, k, m, d;
	
	int start, end;
	ifstream inf("masterout.txt");
	assert(inf != NULL);
	inf >> start >> end;
	inf.close();

	forab(i, start, end) {
		string file = "in";
		file += (char) (i/10+'0');
		file += (char) (i%10 + '0');
		file += ".txt";

		ifstream in(file.c_str());
		assert(in != NULL);

		in >> h >> k >> m >> d;
		in.close();
		Pf("%lld %lld %lld %lld\n", h, k, m, d );
		assert(h >= 1 && h <= 1e9);
		assert(k >= 1 && k <= 1e9);
		assert(m >= 1 && m <= 1e9);
		assert(d >= 1 && d <= 1e9);
		cout << file << ": ";
		cout << solve(h, k, m, d)  ;

		
		file = "out" + file.substr(2);
		ofstream offile(file);
		assert(offile != NULL);

		offile << solve(h, k, m, d) << endl;
		offile.close();
		cout << "Output file " << file << " created." << endl;
	}

	return 0;
}

