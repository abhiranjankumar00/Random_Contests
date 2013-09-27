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
#include <fstream>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

const int sz = 2*(1e6+10);

const int64 mod = 1e9+7;



int64 fact[sz];



int64 _pow(int a, int b) {

	if(b == 0)

		return 1LL;

	int64 tmp = _pow(a, b/2);

	tmp = (tmp*tmp)%mod;

	if(b&1)

		tmp = (tmp*a)%mod;

	return tmp;

}



int64 inv(int a) {

	return _pow(a, mod-2);

}

int main()

{

	fact[0] = 1;

	for(int i = 1, lets_stop_here = (int)sz-1; i <= lets_stop_here; i++)

		fact[i] = (fact[i-1]*i)%mod;

	int T;

	scanf("%d", &T);



	while(T--) {

		int n;

		scanf("%d", &n);

		n--;

		int64 ans = fact[2*n+1];

		int64 t = inv((fact[n]*fact[n]) % mod);

		ans = (ans*t) % mod;

		printf("%lld\n", ans);

	}



	return 0;

}
