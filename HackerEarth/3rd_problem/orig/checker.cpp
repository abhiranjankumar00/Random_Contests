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

int main(int argc, char **argv)
{
	assert(argc == 3);

	fstream fin(argv[1]);
	fstream fout(argv[2]);

	assert(fin != NULL);
	assert(fout != NULL);

	int N;
	int64 W;

	fin >> N >> W;
/*
	DEBUG(N);
	DEBUG(W);
*/
	vector <int> weight(N);
	forn(i, N)
		fin >> weight[i];
/*
	tr(it, weight)
		write(*it);
	cout << endl;
*/
	int maxScore = 200;
	double score = 0;

	set <int> idx;
	int K;
	fout >> K;
	assert(K > 0 && K <= N);
	idx.clear();

	forn(k, K) {
		int element_in_current_box;
		fout >> element_in_current_box;
		assert(element_in_current_box >= 1 && element_in_current_box <= N);

		int64 curWeight = 0;

		forn(i, element_in_current_box) {
			int item_id;
			fout >> item_id;
			assert(item_id >= 0 && item_id < N);
			curWeight += weight[item_id];
			if(idx.find(item_id) != idx.end()) {
				DEBUG(k);
				DEBUG(item_id);
			}
			idx.insert(item_id);
		}
		assert(curWeight > 0 && curWeight <= W);
	}

//	DEBUG(idx.size());
	assert(idx.size() == N);

	score = 1.0*(N-K)/N*maxScore;
	printf("%0.2lf\n", score);

	return 0;
}

