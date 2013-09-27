//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
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

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#ifdef __cplusplus
	#undef __cplusplus
	#define __cplusplus 199712L
#endif
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/

#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

char as[111][111] = {};
int N;
int len;

struct Node {
	Node *child[26];
	Node() {
		forn(i, 26)
			child[i] = NULL;
	}
} root;
/*
void insert(int idx, ST & st, Node *node = &root) {
	if(idx == st.size())
		return;

	assert(st[idx] >= 'a' && st[idx] <= 'z');

	int id = st[idx] - 'a';
	if(node->child[id] == NULL)
		node->child[id] = new Node();

	insert(idx+1, st, node->child[id]);
}
*/
void insert(int x = 0, int y = 0, int xadd = 1, int yadd = 1, Node *node = &root) {
	if(x == N || y == N)
		return ;

	int id = as[y][x] - 'a';

	if(node -> child[id] == NULL)
		node->child[id] = new Node();

	insert(x + xadd, y + yadd, xadd, yadd, node->child[id]);
}

bool find(int idx, ST &st, Node *node = &root) {
	if(idx == st.size())
		return true;

	int id = st[idx] - 'a';

	return node->child[id] == NULL ? false : find(idx+1, st, node->child[id]);
}
/*
void traverse(Node *node, string st = "") {
	if (st.length() > 0)
		cout << st << endl;

	forn(i, 26)
		if(node->child[i] != NULL)
			traverse(node->child[i], st + (char)(i + 'a'));
}
*/
int main()
{
	cin >> N;
	assert(N > 0 && N <= 50);

	forn(i, N)
		Sf("%s", as[i]);

	forn(i, N) {
		forn(j, N) {
			insert(i, j, 1, 0, &root);
			insert(i, j, 0, 1, &root);
			insert(i, j, 1, 1, &root);
		}
	}

	int T;
	cin >> T;
	assert(T > 0 && T <= 1000);

	while(T--) {
		int m;
		ST st ;
		cin >> m >> st;
		assert(st.size() > 0 && st.size() <= N);

		cout << (find(0, st, &root) ? "YES" : "NO") << endl;
	}
	
//	traverse(&root);

	return 0;
}

