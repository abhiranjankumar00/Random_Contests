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
#define	eps		1e-9

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

const int sz = 2e5 + 111;
int in[sz];

bool isLatin(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

struct Node {
	int idx;
	Node* child[26];
	Node() {
		idx = -1;
		forn(i, 26)
			child[i] = NULL;
	}
}root;

void insert(int jkl, const string &st, int idx = 0, Node *nd = &root) {
	if(idx == st.size()) {
		nd->idx = jkl;
		return;
	}

	int id = st[idx] - 'a';
	if(nd -> child[id] == NULL)
		nd->child[id] = new Node();

	insert(jkl, st, idx+1, nd->child[id]);
}

int find(const string &st, int idx = 0, Node *nd= &root) {
	if(idx == st.size())
		return nd->idx;
	int id = tolower(st[idx]) - 'a';
	if(nd->child[id] == NULL)
		return -1;
	return find(st, idx+1,  nd->child[id]);
}

int main()
{
	string st, fail = "NO SUBSEGMENT FOUND";
	vs words;
	getline(cin, st);

	forn(i, st.size()) 	if(isLatin(st[i])) {
		string tmp;
		tmp += st[i];
		i++;
		while(i < st.size() && isLatin(st[i])) {
			tmp += st[i];
			i++;
		}
		words.pb(tmp);
	}

	int K;
	cin >> K;

	set <string> wordSet;
	forn(i, K) {
		string tmp;
		cin >> tmp;
		forn(i, tmp.size())
			tmp[i] = tolower(tmp[i]);
		wordSet.insert(tmp);
	}

	K = 0;
	tr(it, wordSet)
		insert(K++, *it);

	int l = 0, r = 0, cnt = 0;
	int ans_l = -1, ans_r = -1;

	while( r < words.size()) {
		if(cnt < K) {
			int id = find(words[r]);
			if(id >= 0) {
				if(in[id] == 0)
					cnt++;
				in[id]++;
			}
			r++;
		}
		else {
			int id = find(words[l]);
			if(id >= 0) {
				in[id]--;
				if(in[id] == 0)
					cnt--;
			}
			l++;
		}
		if(cnt == K) {
			if(ans_l == -1 || r - l < ans_r - ans_l) {
				ans_l = l;
				ans_r = r;
			}
		}
	}

	if(ans_l == -1)
		cout << fail << endl;
	else
		forab(i, ans_l, ans_r-1) 
			cout << words[i] << " ";

	return 0;
}
