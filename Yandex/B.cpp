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

const int mx = 4e4+1;
bool isPrime[mx];
vector <int> prime;

long long getFactor(long long x) {
	for(auto it = (prime).begin(); it != (prime).end() && (*it)*(*it) <= x; ++it) {
		if(x % (*it) == 0)
			return *it;
	}
	return x;
}

int main()
{
	memset(isPrime, -1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; i < mx; i++)	if(isPrime[i]) {
		prime.push_back(i);
		for(int j = i+i; j < mx; j+=i)
			isPrime[j] = false;
	}

	long long  N;
	cin >> N;
	for(long long k = 2; k <= N; k++) {
		long long x = k*k-1;
		long long p1 = getFactor(x);

		x/=p1;
		if(x == 1)
			continue;
		long long p2 = getFactor(x);
		if(p2 == x) {
			cout << k << "\n";
		}
	}


	return 0;
}

