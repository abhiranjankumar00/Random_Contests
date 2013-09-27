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
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;
typedef long long int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
const int mx = 1e5;
int inRange(int N) {
	return N >= 1 && N <= mx;
}

template <class T1, class T2> class Map: map <T1, T2>
{
public:
	void factorize(int N, int add) {
		assert(abs(add) == 1);
		for(int i = 2; i*i <= N && N > 1; i++) {
			while(N % i == 0) {
				(*this)[i] += add;
				assert((*this)[i] >= 0);
				N /= i;
			}
		}

		if(N > 1) {
			(*this)[N] += add;
			assert((*this)[N] >= 0);
		}
	}

	void print() {
		for(__typeof((*this).begin()) it = (*this).begin(); it != (*this).end(); it++)
			printf("[%d: %d] ", it->first, it->second);
		cout << ("\n");
	}

	bool isSubsetOf(Map <T1, T2> & m) {
		for(__typeof((*this).begin()) it = (*this).begin(); it != (*this).end(); it++) {
			auto jt = m.find(it->first);
			if(jt == m.end() || jt->second < it->second)
				return false;
		}
		return true;
	}
};

int main()
{
	int N;
	cin >> N;
	vector <int> arr(N);
	assert(inRange(N));

	Map <int, int> req_fact, cur_fact;
	req_fact.factorize(N, +1);

	for(int i = 0, lets_stop_here = (int)N; i < lets_stop_here; i++) {
		cin >> arr[i];
		assert(inRange(arr[i]));
	}

	int l = 0, r = 0;
	bool flag = false;
	pair <int, int> ans(-1, -1);

	while(l < N) {
		if(r == N || flag)
			cur_fact.factorize(arr[l++], -1);
		else
			cur_fact.factorize(arr[r++], +1);

		flag = req_fact.isSubsetOf(cur_fact);
		if(flag) {
			if(ans.first == -1)
				ans = make_pair(l, r-1);
			else if(ans.second - ans.first + 1 > r-l+1)
				ans = make_pair(l, r-1);
			else if(ans.second - ans.first + 1 == r - l + 1 && l < ans.first)
				ans = make_pair(l, r-1);
		}
	}

	if(ans.first == -1)
		cout << -1 << ("\n");
	else
		cout << ans.first << " " << ans.second << ("\n");

	return 0;
}
