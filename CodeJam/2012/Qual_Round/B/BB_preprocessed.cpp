//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;


int cycleLeft(int n) {



	int nZero = 0;

	while(n % 10 == 0) {

		nZero ++;

		n /= 10;

	}



	int ret = 0, t = n % 10;



	while(nZero--)

		t *= 10;



	n/=10;

	if(!n)

		return t;

	int nnZero = 0;

	while(n % 10 == 0) {

		nnZero++;

		n /= 10;

	}

	while(n) {

		ret = ret*10 + n%10;

		n/=10;

	}

	n = ret;



	while(n) {

		t = t*10 + n % 10;

		n /= 10;

	}

	while(nnZero--)

		t*=10;



	return t;

}



int sset[2000100];



int main()

{

	memset(sset, -1, sizeof(sset));

	int s = 0;



	for(int i = 11, lets_stop_here = (int)2000100 -10; i <= lets_stop_here; i++) if(sset[i] == -1) {



		s++;



		int l = i;



		do {

			if(l < 2000100)

				sset [l] = s;



		} while( (l = cycleLeft(l)) != i);



	}





	int test;

	cin >> test;

	for(int _test = 1, lets_stop_here = (int)test; _test <= lets_stop_here; _test++) {

		map <int, int> cnt;
		int a , b;

		cin >> a >> b;




		for(int i = max(11, a), lets_stop_here = (int)b; i <= lets_stop_here; i++) {
			cnt[sset[i]]++;
//			mm[sset[i]]++;

		}

		long long ans = 0ll;



		for(__typeof((cnt).begin()) it = (cnt).begin(); it != (cnt).end(); it++) {
			long long tmp = it->second;
			ans += tmp * (tmp-1)/2;
//			ret += (1ll * it->second * (it->second-1))/2;

		}

		printf("Case #%d: %lld\n", _test, ans);



	}

	return 0;

}
