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

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;
/*
#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)
*/

int main()
{
	int test, m, x, y;
	string st, tmp;
	cin >> test;
	int arr[26];

	while(test--)
	{
		cin >> st >> m;
		memset(arr, 0, sizeof(arr));

		for(int i = 0; i<st.length() ;i++)
			arr[st[i] - 'A'] = 1;

		for(int _m = 0; _m < m ; _m++)
		{
			x = y = 0;
			cin >> tmp;

			for(int i = 0; i<st.length(); i++)
			{
				if(st[i] == tmp[i])
					y++;
				if(arr[tmp[i] - 'A'])
					x++;
			}

			cout << x << " " << y << endl;
		}
	}

	return 0;
}
