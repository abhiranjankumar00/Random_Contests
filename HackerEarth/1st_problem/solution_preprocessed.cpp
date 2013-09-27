//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

const int sz = 1e5 + 111;
int fact[sz];
int arr[sz];
int N;

void init() {
	for(int i = 0; i < sz; i++)
		fact[i] = i;

	for(int i = 2; i < sz; i++) 	if(fact[i] == i) {
		for(int j = i+i; j < sz; j+=i)
			fact[j] = i;
	}
}

void factorize(int N, int add, map <int, int> &m) {
	assert(abs(add) == 1);
	while(N != 1) {
		int p = fact[N];
		m[p] += add;
		assert(m[p] >= 0);
		N /= p;
	}
}

bool isSubset( const map <int, int> &req_fact, const map <int, int> &cur_fact) {
	for(auto it = req_fact.begin(); it != req_fact.end(); it++) {
		auto jt = cur_fact.find(it->first);
		if(jt == cur_fact.end() || jt->second < it->second)
			return false;
	}
	return true;
}

int main()
{
	init();

	cin >> N;
	assert(N >= 1 && N <= 1e5);

	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		assert(arr[i] >= 1 && arr[i] <= 1e5);
	}

	if(N == 1) {
		cout << 0 << " " << 0 << endl;
		return 0;
	}

	map <int, int> req_fact, cur_fact;

	factorize(N, +1, req_fact);

	bool flag = false;
	int l = 0, r = 0;
	pair <int, int> ans(-1, -1);

	while(l < N) {
		if(r == N || flag == true)
			factorize(arr[l++], -1, cur_fact);
		else
			factorize(arr[r++], +1, cur_fact);

		flag = isSubset(req_fact, cur_fact);
		if(flag) {
			if(ans.first == -1)
				ans = make_pair(l, r-1);
			else if(ans.second - ans.first + 1 > r - l + 1)
				ans = make_pair(l, r-1);
			else if(ans.second - ans.first + 1 == r-l+1 && l < ans.first)
				ans = make_pair(l, r-1);
		}
	}

	if(ans.first == -1)
		cout << -1 << ("\n");
	else
		cout << ans.first << " " << ans.second << ("\n");

	return 0;
}
