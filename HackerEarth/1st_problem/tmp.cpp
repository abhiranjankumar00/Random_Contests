//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
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

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

const int mx = 1e5;
int inRange(int N) {
	return N >= 1 && N <= mx;
}

template <class T1, class T2> class Map: map <T1, T2>
{
public:
	void factorize(int N, int add) {
		assert(abs(add) == 1);
		for(int i = 2; i*i <= N && N > 1; i++) {
			while(N % i == 0) {
				(*this)[i] += add;
				assert((*this)[i] >= 0);
				N /= i;
			}
		}

		if(N > 1) {
			(*this)[N] += add;
			assert((*this)[N] >= 0);
		}
	}

	void print() {
		tr(it, *this)
			Pf("[%d: %d] ", it->first, it->second);
		cout << endl;
	}

	bool isSubsetOf(Map <T1, T2> & m) {
		tr(it, *this) {
			auto jt = m.find(it->first);
			if(jt == m.end() || jt->second < it->second)
				return false;
		}
		return true;
	}
};

int main()
{
	int N;
	cin >> N;
	vector <int> arr(N);
	assert(inRange(N));

	Map <int, int> req_fact, cur_fact;
	req_fact.factorize(N, +1);

	forn(i, N) {
		cin >> arr[i];
		assert(inRange(arr[i]));
	}

	int l = 0, r = 0;
	bool flag = false;
	pair <int, int> ans(-1, -1);

	while(l < N) {
		if(r == N || flag) 
			cur_fact.factorize(arr[l++], -1);
		else
			cur_fact.factorize(arr[r++], +1);

		flag = req_fact.isSubsetOf(cur_fact);
		if(flag) {
			if(ans.first == -1)
				ans = mp(l, r-1);
			else if(ans.second - ans.first + 1 > r-l+1)
				ans = mp(l, r-1);
			else if(ans.second - ans.first + 1 == r - l + 1 && l < ans.first)
				ans = mp(l, r-1);
		}
	}

	if(ans.first == -1)
		cout << -1 << endl;
	else
		cout << ans.first << " " << ans.second << endl;
	
	return 0;
}

