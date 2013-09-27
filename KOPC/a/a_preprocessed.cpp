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

int64 mod;



int64 _pow(int a, int b) {

	if(b == 0)

		return 1LL;

	int64 tmp = _pow(a, b/2);

	tmp = (tmp*tmp)%mod;

	if(b&1)

		tmp = (tmp*a)%mod;

	return tmp;

}



int main()

{

	int T;

	scanf("%d", &T);



	while(T--) {

		int n, P, tmp;

		scanf("%d %d %lld", &n, &P, &mod);

		int64 sum = 0;



		for(int i = 0, lets_stop_here = (int)n; i < lets_stop_here; i++) {

			scanf("%d", &tmp);

			sum += tmp;

		}

		printf("%lld\n", _pow(sum, P));

	}



	return 0;

}
