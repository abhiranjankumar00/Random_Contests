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

int countVariety[555][1111];
int sum[555][1111];
int S[555];
int V, M;

int solve(int n, int k) {
	assert(n >= 0 && n <= V);
	assert(k >= 0 && k < M);

	if(n == 0)
		return k == 0 ? 0 : -2;		// -2 = -infinity

	int &ret = countVariety[n][k];

	if(ret != -1)				// -1 = undefined
		return ret;

	ret = solve(n-1, k);
	sum[n][k] = sum[n-1][k];

	int preIdx = (k - S[n]) % M;
	preIdx = (preIdx + M)%M;

	int tmpAns = solve(n-1, preIdx);
	if(tmpAns == -2 )		// tmpAns = -infinity
		return ret;

	if(tmpAns + 1 > ret) {
		ret = tmpAns + 1;
		sum[n][k] = sum[n-1][preIdx] + S[n];
	}
	else if(tmpAns + 1 == ret) {
		sum[n][k] = max(sum[n][k], sum[n-1][preIdx] + S[n]);
	}
//	ret = max(ret, tmpAns + 1);
//	Pf("n = %d, k = %d, cnt = %d, sum = %d\n", n, k, ret, sum[n][k]);
	return ret;
}

int main()
{
	int test;
	read(test);

	while(test--) {
		CL(countVariety, -1);
		CL(sum, 0);
		cin >> V >> M;
		forab(i, 1, V)
			cin >> S[i];

		int ans = solve(V, 0);
		cout << ans << " " << sum[V][0]/M << endl;
	}

	return 0;
}

