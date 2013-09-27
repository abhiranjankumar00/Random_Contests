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

int main()
{
	const int64 mmod = 1e9 ;
	int start, end;
	ifstream inf("masterin.txt");
	assert(inf != NULL);
	inf >> start >> end;
	inf.close();

/*
	ifstream inff("primes.txt");
	assert(inff != NULL);
	vector <int> prime(10);
	forn(i, 10)
		inff >> prime[i];
		
	set <vi > st;
*/
	forab(i, start, end) {
		string file = "in";
		file += (char) (i/10 + '0');
		file += (char)(i%10+ '0');
		file += ".txt";
		ofstream offile(file.c_str());
		assert(offile != NULL);
/*
		vi out;
		set <int> sin;

		while(out.size() < 4) {
			int idx = rand () % 10;
			if(sin.find(idx) != sin.end())
				continue;
			out.pb(idx);
			if(out.size() == 5) {
				if(st.find(out) == st.end())
					st.insert(out);
				else
					out.clear();
			}
		}
		tr(it, out)
			offile << prime[*it] << " ";
		cout << endl;
*/
// /*
		int64 h = 1 + rand()% mmod;
		int64 k = 1 + rand()% mmod;
		int64 d = 1 + rand()% mmod;
		int64 m = 1 + rand()% mmod;

		offile << h << " " << k << " " << m << " " << d << endl;
// */
		offile.close();	
		cout << "file " << file << " created." << endl;
	}

	return 0;
}

