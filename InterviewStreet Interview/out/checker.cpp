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

// a^x mod m
int64 pow(int64 a, int64 x, int64 m) {
	if(x == 0)
		return 1ll;

	int64 ret = pow(a, x/2, m);
	ret = (ret * ret) % m;
	if(x % 2 == 1)
		ret = (a*ret)%m;
	return ret;
}

bool check(int64 h, int64 k, int64 m, int64 d, int64 x) {
	assert(x == -1 || (x >= 0 && x < m));
	assert(h >= 1 && h <= 1e9);
	assert(k >= 1 && k <= 1e9);
	assert(m >= 1 && m <= 1e9);
	assert(d >= 1 && d <= 1e9);
	if(x == -1)
		return true;
	return (h*pow(k, x, m)) % m == d % m;
}

int main()
{
	int64 h, k, m, d, x;

	forab(i, 0, 99) {
		string sin = "in";
		sin += (char)(i/10 + '0');
		sin += (char)(i%10 + '0');
		sin += ".txt";

		string sout = "out";
		sout += (char)(i/10 + '0');
		sout += (char)(i%10 + '0');
		sout += ".txt";

		ifstream in1(sin), in2(sout);
		cout << sin << ": " << sout << endl;
		assert(in1 != NULL);
		assert(in2 != NULL);
		in1 >> h >> k >> m >> d;
		in2 >> x;

		cout << h << " " << k << " " << m << " " << d << " = " <<  x << endl;
		cout << "check = " << (check(h, k, m, d, x) ? 1 : 0) << endl;
		assert(check);
		cout << endl;
	}


	return 0;
}

