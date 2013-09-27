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

const int sz = 1e3 + 111;

int Ans[sz];
int K;

int grundy(int N) {
	assert(N >= 0 && N < sz);

	int &ret = Ans[N];

	if(ret > -1)
		return ret;

	if(K > N)
		return ret = 0;

	ret = 0;
	set <int> mex;
	N -= K;
	forab(N1, 0, N) {
		int N2 = N - N1;
		mex.insert(grundy(N1) ^ grundy(N2));
	}

	tr(it, mex) {
		if(*it != ret)
			break;
		ret++;
	}
	return ret;
}

void solve(string num = "") {
	CL(Ans, -1);
	int test = 1000;
	K = 1;
//	DEBUG(K);

	ifstream in("in" + num + ".in");;
	ofstream out("out" + num + ".out");
	if(num == "")
		cin >> test >> K;
	else
		in >> test >> K;

	forab(_test, 1, test) {
		int N;
//		N = _test;
		if(num == "")
			cin >> N;
		else
			in >> N;

		if(num == "")
			cout << (grundy(N) > 0 ? "Jack" : "Jill") << endl;
		else
			out << (grundy(N) > 0 ? "Jack" : "Jill") << endl;
		
//		if(grundy(N) == 0)
//			Pf("%d: Jill\n", N);
//		cout << N << ": " <<  (grundy(N) > 0 ? "Jack" : "Jill") << endl;
	}

}
int main()
{
	forn(i, 33) {
		string s = "";
		int N = i;
		while(N) {
			s += char((N %10) + '0');
			N /= 10;
		}
		reverse(all(s));
		if(s == "")
			s += '0';
		solve(s);
	}
	return 0;
	solve();
	return 0;
}
