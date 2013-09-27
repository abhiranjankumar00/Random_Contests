//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

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
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define Pf		printf
#define	Sf		scanf

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back

#define	all(c)		(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int) b; i>=loop_ends_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#define isLeap(y)	(int)((y % 400 == 0 ) || ( y % 4 == 0) && (y % 100 != 0)) 

int main()
{
	int test, d, y;
	string Months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	int months[12] =    {31,     28,     31,    30,   31,    30,     31,    31,    30,    31,    30,  31};
	read(test);
	char mm[10];
	int days, i;

	forab(_test, 1, test) {
		Sf("%d-%[^-]-%d", &d, mm, &y);
		ST m(mm);

//		cout << d << " " << m << " " << y << endl;
		
		months[1] = 28 + isLeap(y);
		days = 0;
		for(i = 0; m != Months[i]; i++)
			days += months[i];
		
		days += d;
		
//		cout << days << endl;

		Pf("Case %d: ", _test);
		if(days <= 300) {
			Pf("%d Hundreds\n", days);
			continue;
		}
		days -= 300;
		if(days <= 60) {
			Pf("%d Tens\n", days);
			continue;
		}
		days -= 60;
		Pf("%d Ones\n", days);
	}
	return 0;
}

