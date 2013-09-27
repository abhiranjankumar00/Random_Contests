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


void Collapse(ST & st, const set<ST> & s) {
	int a[26] = {0}, idx;

	forn(i, st.length())
		idx = st[i] - 'A',	 a[idx]++;

	char c1, c2;
	int idx1, idx2;

	tr(it, s) {
		c1 = (*it)[0], 		c2 = (*it)[1];
		idx1 = c1- 'A', 	idx2 = c2 - 'A';

		if( c1 == c2 ){
			if(a[idx1] > 1) {
				st.clear();
				return;
			}
		}
		else if(a[idx1] && a[idx2]) {
			st.clear();
			return;
		}
	}
}


int main()
{
	int test;
	map<ST, char> m;
	set<ST> s;
	cin >> test;
	ST st, tmp;
	char ch;

	forab(_test, 1, test) {
		m.clear();
		s.clear();
		int c, d, n;

		cin >> c;

		forn(_c, c) {
			cin >> st;
			tmp = st.substr(0, 2);
			ch = st[2];
			m[tmp] = ch;
			reverse(all(tmp));
			m[tmp] = ch;
		}

		cin >> d;
		forn(_d, d) {
			cin >> st;
			s.insert(st);
			reverse(all(st));
			s.insert(st);
		}

		cin >> n >> st;
/*
		cout << "Test #" << _test << endl;

		cout << "mapping : \n";
		tr(it, m)
			cout << it->first << " : " << it->second << endl;

		cout << endl << "Set : \n";
		tr(it, s)
			cout << *it << endl;

		cout << "\nString : " << st << endl << endl;
*/
		tmp.clear();
	
		ST t;
		int len;

		forn(i, st.length()) {
			tmp += st[i];

			if( (len = tmp.length() ) >= 2) {
				t = tmp.substr(len-2);

				if( present(t, m) )
					tmp = tmp.substr(0, len-2) + m[t];
				Collapse(tmp, s);
			}
		}

		Pf("Case #%d: [", _test);

		if(tmp.length() == 0);
		else
		{
			forn(i, tmp.length()-1)
				cout << tmp[i] << ", ";
			cout << tmp[tmp.length()-1]; 
		}
		
		cout <<  "]\n";
		
	}

	return 0;
}
