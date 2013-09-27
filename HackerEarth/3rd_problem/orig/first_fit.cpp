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

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater than 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
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

#if (0 or defined ONLINE_JUDGE)
	#define DEBUG
#else 
	#define DEBUG(x)	cout << #x << " = " << x << "\n"
#endif

struct Item {
	int id, w;
	Item(int _id, int _w) {
		id = _id;
		w = _w;
	}
	bool operator < (const Item &item) const {
		if(this->w != item.w)
			return this->w < item.w;
		return this->id < item.id;
	}
};

int main()
{
	int N, W;
	set <Item> st;
	vector <vector <Item> > ans;

	cin >> N >> W;
	forn(i, N) {
		int w;
		cin >> w;
		auto it = st.find(Item(i, w));
		if(it != st.end()) {
			Pf("This item (%d, %d) already found as (%d, %d)\n", i, w, it->id, it->w);
			assert(it != st.end());
		}
		st.insert(Item(i, w));
	}
	//DEBUG(st.size());
	//assert(st.size() == N);
/*
	tr(it, st)
		Pf("%d %d\n", it->id, it->w);
	cout << endl;
*/
	int64 curWeight = 0;

	while(st.empty() == false) {
		Item nd = *st.begin();
		if(ans.empty() || curWeight + nd.w > W) {
			ans.pb(vector <Item>(1,nd));
			curWeight = nd.w;
		}
		else {
			ans.back().pb(nd);
			curWeight += nd.w;
		}
		st.erase(st.begin());
	}

	cout << ans.size() << endl;
	tr(it, ans) {
		cout << it->size() << " ";
		tr(jt, *it)
			write(jt->id);
//			Pf("(%d: %d) ", jt->id, jt->w);
		cout << endl;
	}

	return 0;
}

