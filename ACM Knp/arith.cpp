//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define Pf		printf
#define	Sf		scanf

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back

#define	all(c)		(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int) b; i>=loop_ends_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#define Mod		10007

int64 fact[20];

void preprocess() {
	fact[0] = 1;
	forab(i, 1, 19)
		fact[i] = i*fact[i-1];
}

int64 gcd(int64 a, int64 b){
	return b == 0 ? a : gcd(b, a%b);
}

int count(int64 n) {
	int ans = 0;
	
	n *= n;

	for(int64 i = 1; i*i <= n; i++)	if(n % i == 0 && gcd(i, n/i) == 1) {
		Pf("%lld %lld = %lld\n", i,n/i, i);
		ans++;
	}

	return ans;
}

int main()
{
	preprocess();

//	forab(i, 1, 15)
//	cout << i << " " << fact[i] << " " << fact[i]*fact[i] << endl;

	Pf("n = 4,  ans = %d", count(fact[4]));
//	forab(i, 1, 9)
//	Pf("n = %d, count = %d\n", i, count(fact[i]));

//	cout << count(fact[9]);
/*
	int n;

	while(read(n) != EOF) {
		if(n & (-n) == 0) {
			writeln((n>>1) % Mod);
		}
		else {
			while(n & (-n) != 0)
				n = n&(-n);
			writeln(n);
		}
	}
*/

	return 0;
}

