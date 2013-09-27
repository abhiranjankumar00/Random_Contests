#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int sz = 1000010 ;

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

int sum[sz];

int main()
{
	memset(sum, -1, sizeof(sum));
	int s = 0;

	for(int i = 11, lets_stop_here = (int)sz-10; i <= lets_stop_here; i++) 
		if(sum[i] == -1) {
			s++;

			int l = i;

			do {
				sum [l] = s;

			} while( (l = cycleLeft(l)) != i);

		}

	

	int test;
	scanf("%d", &test);
	for(int testCnt = 1, lets_stop_here = (int)test; testCnt <= lets_stop_here; testCnt++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map <int, int> cnt;
		
		for(int i = max(11, a), lets_stop_here = (int)b; i <= lets_stop_here; i++) {
			cnt[sum[i]]++;
		}
		long long ans = 0;

		for(__typeof((cnt).begin()) iter = (cnt).begin(); iter != (cnt).end(); iter++) {
			long long tmp = iter->second;
			ans = ans + tmp*(tmp-1)/2;
		}
		printf("Test %d: %lld\n", testCnt, ans);

	}
	return 0;
}
