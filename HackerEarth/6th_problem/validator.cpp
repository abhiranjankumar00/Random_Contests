/*
ID: nihcas700
LANG: C++
*/

# include <iostream>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cstdio>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <list>
# include <deque>
# include <new>
# include <stack>
# include <queue>
# include <iterator>
# include <functional>
# include <fstream>
#include <cassert>
using namespace std;

const int sz = 1e5;

int N, M, vis[sz];
int ans = -1;
set <int> U;
vector <vector <int> >G;

int dfs(int id) {
	assert(id >= 0 && id < N);
	assert(vis[id] == false);

	vis[id] = true;
	int ret = 0;
	if(U.find(id) != U.end())
		ret++;

	for(int i = 0; i < G[id].size(); i++)
		ret += dfs(G[id][i]);

	if(ret == M && ans == -1)
		ans = id;

	return ret;
}

int main() {
	cin >> N;
	G = vector <vector<int> >(N); 

	assert(N >= 1 && N <= 100000);

	for(int i = 1; i <= N-1; i++) {
		int p;
		cin >> p;
		assert(0 <= p && p < N);
		G[p].push_back(i);
	}

	for(int i = 0; i < N; i++)
		assert(0 <= G[i].size() && G[i].size() <= 10);

	cin >> M;
	assert(M >= 1 && M <= 100000);

	for(int i = 0; i < M; i++) {
		int u;
		cin >> u;
		assert(u >= 0 && u < N);
		U.insert(u);
	}
	assert(U.size() == M);

	dfs(0);

	for(int i = 0; i < N; i++)
		assert(vis[i]);

	assert(ans >= 0 && ans < N);

	cout << ans;

	return 0;
}

