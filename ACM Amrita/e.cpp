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

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int) b; i>=loop_ends_here; i--)

#define _mod(a, b)	(a- a/b*b)
#define read(n)		scanf("%d", &n)
const int MOD = 1000000007;

int Mod(ST & st, int n) {
	int ret = 0;
	forn(i, st.length()) 
		ret = (ret*10 + st[i] - '0') % n;
	return ret;
}

int64 _Mod(ST & st, int64 n) {
	int64 ret = 0;
	forn(i, st.length()) 
		ret = (ret*10 + st[i] - '0') % n;
	return ret;
}


ST bfs(string a, int n){
	queue <pair<ST, int> > q;

	int mod = Mod(a, n), tmp;
	char i;

	for( i = '0' ; i<='9'; i++) {
//		tmp = ( mod *10 + i - '0') % n;
		tmp = mod*10 + i - '0';
		tmp = _mod(tmp, n);
		if(tmp == 0)	return (a + i);
		q.push(mp(a+i, tmp));
	}

	while(!q.empty()) {
		ST b = q.front().first;
		int m = q.front().second;
		q.pop();


		for(i = '0'; i<= '9'; i++) {
			tmp =  (m*10 + i - '0' ) ;
			tmp = _mod(tmp, n);
			if(tmp == 0)
				return (b + i);
			q.push(mp(b+i, tmp));
		}
	}

}

bool vis[1000100];
int64 bfs_new(int64 a, int64 n) {
	queue <int64> q;
	int64 tmp;
	a %= MOD;
	CL(vis, 0);

	forn(i, 10) {
		tmp = (a*10 + i) % MOD;
		if(tmp == 0)
			return tmp;
		q.push(tmp);
		vis[tmp] = true;
	}

	while(1) {
		int b = q.front();
		q.pop();
		tmp = b;

		forn(i, 10) {
			tmp = (tmp*10 + i ) % MOD;
				tmp %= n;
			if(vis[tmp])	continue;
			vis[tmp] = true;
			if(tmp == 0)
				return tmp;
			q.push(tmp);
		}
	}

}

int main()
{
	int test;
	read(test);
	int n;
	ST b ;
	
	while(test--) {
		b = "1";
		read(n);
		int tmp;
		int64 lstMod = 1;
		int64 bb= 1;

		forab(i, 1, n) {
			read(tmp);
			b = bfs(b, tmp);
			bb= bfs_new(bb, tmp);
//			Pf("b = %s, a = %d,  mod = %d\n", b.c_str(), tmp, Mod(b, tmp));
//			Pf("MOD = %lld\n", _Mod(b, MOD));
			lstMod = (lstMod*tmp)% MOD;
			cout << lstMod << endl;
		}
		cout << bb << endl;
		Pf("%lld\n",_Mod(b, MOD) );
//		cout << _Mod(b, MOD) << endl;
		cout << endl;
	}


	return 0;
}

