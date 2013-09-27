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
using namespace std;

int dfs(int u, int &ans, const vector <vector <int> > &G, const set <int> &st) {
	int ret = st.find(u) == st.end() ? 0 : 1;
	for(int i = 0; i < G[u].size(); i++)
		ret += dfs(G[u][i], ans, G, st);
	if(ret == st.size() && ans == -1)
		ans = u;
	return ret;
}

int main() {
	int N;
	cin >> N;
	vector <vector<int> > G(N);
	for(int i = 1; i < N; i++) {
		int p ;
		cin >> p;
		G[p].push_back(i);
	}

	int M;
	cin >> M;
	set <int> st;
	for(int i = 0; i < M; i++) {
		int u;
		cin >> u;
		st.insert(u);
	}

	int ans = -1;
	dfs(0, ans, G, st);
	cout << ans << endl;

	return 0;
}

