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
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

bool solve(long long days, vector <long long> A, long long N, long long G, long long K) {
	long long d = days;
	sort(A.begin(), A.end(), greater<long long>());

	if(G > 0)for(int i = 0; i < N && d > 0; i++) {
		long long q = min(A[i]/G*1ll, d);
		A[i] -= q*G;
		d -= q;
	}

	sort(A.begin(), A.end(), greater<long long>());
	if(G > 0)for(int i = 0; i < N && d > 0;++i ) {
		if(A[i] != 0) {
			A[i] = 0;
			d--;
		}
	}

	long long sum = accumulate(A.begin(), A.end(), 0ll);

	if(sum == 0)
		return true;
//	if(days*K >= sum)
	if(K > 0 && days >= sum/K + (sum % K ==0 ? 0 : 1))
		return true;
	else
	   	return false;
}

int main()
{
	long long  N, G, K;
	cin >> N >> G >> K;
	vector <long long> A(N);

	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	long long l = 1, r = 1e18;

	while(l < r) {
		long long mid = (l+r)/2;
		if(solve(mid, A, N, G, K))
			r = mid;
		else
			l = mid+1; 
	}
	cout << l << endl;


	return 0;
}

