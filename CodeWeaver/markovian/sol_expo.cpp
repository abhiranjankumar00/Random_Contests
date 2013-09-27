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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

long double A, B, C, D;

struct Matrix {
	long double a, b, c, d;
	Matrix(long double p, long double q) {
		a = p, b = 1-p;
		c = 1-q, d = q;
	}
	Matrix() { a = A, b = B, c = C, d = D;}
	Matrix operator *(const Matrix &m) {
		Matrix ret;
		ret.a = a*m.a + b*m.c;
		ret.b = a*m.b + b*m.d;

		ret.c = c*m.a + d*m.c;
		ret.d = c*m.b + d*m.d;
		return ret;
	}
};

Matrix operator^ (Matrix m, int64 N) {
	Matrix ret;
	if(N == 0) {
		ret.a =  ret.d = 1;
		ret.b = ret.c = 0;
		return ret;
	}

	ret = m^(N/2);
	ret = ret*ret;

	if(N%2 == 1) {
		ret = Matrix() * ret;
	}
	return ret;
}

int main()
{
	int test;
	read(test);
	while(test--) {
		int todaySun, probSunToSun, probRainToRain;
		Sf("%d %d %d", &todaySun, &probSunToSun, &probRainToRain);
		long double p = probSunToSun/ 100.0;
		long double q = probRainToRain / 100.0;

		A = p;
		B = 1-A;
		C = 1-q;
		D = q;

		Matrix ret = Matrix() ^ 1000000000000000ll;

		Pf("%0.10lf\n", 100.0*(double)ret.a);
	}

	return 0;
}

