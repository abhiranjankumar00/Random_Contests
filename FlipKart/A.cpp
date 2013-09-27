//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

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
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")
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
/*
#ifdef DEBUG
	#undef DEBUG
#endif
#define DEBUG
*/

vs st;
ST toFind;
int N;
struct Node {
	Node *child[26];
	Node() {
		forn(i, 26)
			child[i] = NULL;
	}
}root;

void insert(int r = 0, int c = 0, int radd = 0, int cadd = 1, Node *nd = &root) {
	if(r == N || c == N)
		return;
	if(r < 0 || c < 0)
		return;
	
	int id = st[r][c] - 'a';

	if(nd->child[id] == NULL)
		nd->child[id] = new Node();

	insert(r+radd, c+cadd, radd, cadd, nd->child[id]);
}

bool find(int idx = 0, Node *nd = &root) {
	if(idx == toFind.size())
		return true;
	int id = toFind[idx] - 'a';

	return nd->child[id] == NULL ? false : find(idx+1, nd->child[id]);
}

void traverse(Node *nd = &root, string st = "") {
	DEBUG(st);

	forn(i, 26) {
		if(nd->child[i] != NULL) {
			traverse(nd->child[i], st + (char)('a' + i));
		}
	}

}

int main()
{
	int K;
	Sf("%d %d", &N, &K);

	st = vs(N);

	forn(i, N)
		cin >> st[i];

	forn(i, N) {
		forn(j, N) {
			insert(i, j, 0, 1, &root);
			insert(i, j, 1, 1, &root);
			insert(i, j, 1, 0, &root);
			insert(i, j, 1, -1, &root);
			insert(i, j, 0, -1, &root);
			insert(i, j, -1, -1, &root);
			insert(i, j, -1, 0, &root);
			insert(i, j, -1, 1, &root);
		}
	}
//	traverse();

	while(K--) {
		cin >> toFind;
		if(find())
			cout << toFind << endl;
	}

	return 0;
}

