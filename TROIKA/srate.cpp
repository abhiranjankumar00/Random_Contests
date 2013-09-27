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
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef string ST;
typedef stringstream SS;

#define Pf	printf
#define	Sf	scanf

#define PI	3.141592653589793
#define E	2.718281828459045
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

int Mod(int a, ST n,int k, int idx)
{
	if(idx < 0)	return 1;
	int ret;

	if(n[idx] == '0')
	{
		ret = Mod( (a*a)%k, n, k, idx - 1 );

//		return ret;
	}
	else if(n[idx] == '2')
	{
		n[idx] = '0';
		
		ret =  Mod( (a*a)%k, n, k, idx );
//		return ret;
	}
	else
	{
		int t = Mod((a*a)%k, n, k, idx-1);
		ret =  (a*t)%k;
//		return ret;
	}

	Pf("a = %d, n = %s, k = %d, ret = %d\n", a, n.substr(0, idx+1).c_str(), k, ret);

	return ret;
}

int MOD(int a, ST n, int k)
{
	int l = n.length();
	int ret;
	ST nn = n;

	if(n == "0" || l == 0)
	{
		Pf("a = %d , n = %s ,  k = %d , ret = 1\n", a, n.c_str(), k);
		return 1;
	}

	if(n[l-1] == '0')
	{
		ret = MOD((a*a)%k, n.substr(0, l-1), k );
	}
	else if(  n [l-1] == '2')
	{
		n [l-1]  = '0';
		ret = MOD( (a*a)%k, n, k );
	}
	else
	{
		ret = MOD( (a*a)%k, n.substr(0, l-1), k  );
		ret = (a*ret)%k;
	}

	Pf("a = %d , n = %s ,  k = %d , ret = %d\n", a, nn.c_str(), k, ret);
	return ret;

}

int main()
{
	int t, a, k;
	ST st, len, n;

	Sf("%d", &t);

	forn(_t, t)
	{
		cin >> a >> n >> k;
//		cout << Mod(a, n, k, n.length()-1) << endl;
		cout << MOD(a, n, k) << endl;
	}
	

	return 0;
}
