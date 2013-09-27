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

#define tr(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)

set <int> st;
int p;
const int mxChild = 10;

void dfs(int n, bool toConsider, const vector <vector <int> > &G) {
	if(toConsider)  {
		if(rand() % 100 >= 15)
			st.insert(n); }
	if(n == p)
		toConsider = true;
	for(int i = 0; i < G[n].size(); i++)
		dfs(G[n][i], toConsider, G);
}

int main() {
	int N = 10000, M;
	int par[N];
	vector <vector <int> > G(N);
	int cur = 0;
	par[0] = -1;
	queue <int> q;
	q.push(cur++);

	while(!q.empty()) {
		int u = q.front(), nChild;
		q.pop();

		if(u == 0)
			nChild = min(rand() % (mxChild-1) + 2, N-cur);
		else
			nChild = min(rand() % (mxChild + 1), N-cur);
		forn(i, nChild) {
			G[u].push_back(cur);
			par[cur] = u;
			q.push(cur++);
		}
	}

	cout << N << endl;
	forab(i, 1, N-1)
		cout << par[i] << " ";
	cout << endl;

	time_t tm;
	time(&tm);
	srand(tm);

//	p = 0;
	p = rand() % (N/100);

	dfs(0, false, G);

	M = st.size();
	cout << M << endl;

	for(set <int> :: iterator it = st.begin(); it != st.end() ; it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}

