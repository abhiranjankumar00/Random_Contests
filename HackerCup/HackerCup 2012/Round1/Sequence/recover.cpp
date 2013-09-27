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
*/

#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif

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

int arr[11111], tmp[11111], n;
const int mod = 1000003;
ST st;
int stidx;

int checksum() {
	int ans = 1;
	forn(i, n)
		ans = (31*ans + tmp[i]) % mod;
//		ans = (31*ans + arr[i]) % mod;
	return ans;
}

void merge(int lb, int le, int rb, int re) {
	int idx = 0;

	int li = lb, ri = rb;

	while(li <= le && ri <= re) {
		if(st[stidx++] == '1')
			tmp[idx++] = arr[li++];
		else
			tmp[idx++] = arr[ri++];
	}
/*

	while(li <= le && ri <= re) {
		if(arr[li] < arr[ri]) {
			tmp[idx++] = arr[li++];
			Pf("1");
		}
		else {
			tmp[idx++] = arr[ri++];
			Pf("2");
		}
	}
*/
	while(li <= le)
		tmp[idx++] = arr[li++];
	while(ri <= re)
		tmp[idx++] = arr[ri++];

	forn(i, idx)
		arr[lb + i] = tmp[i];
}

void mergeSort(int l, int r) {
	if(r -l <= 0) {
		return;
	}

	int mid = (l+r+1)/2;
	mergeSort(l, mid-1);
	mergeSort(mid, r);
	merge(l, mid-1, mid, r);
}

int main()
{
	int T;
	read(T);
	forab(t, 1, T) {
		read(n);
		cin >> st;
		stidx = 0;
		forn(i, n)
			arr[i] = i;
		mergeSort(0, n-1);
		forn(i, n)
			tmp[arr[i]] = i+1;
/*		forn(i, n)
			write(tmp[i]);
		cout << endl;
*/		Pf("Case #%d: %d\n",t, checksum());
	}
/*
	n = 5;
	st = "2121121";
	stidx = 0;
	forn(i, n)
		arr[i] = i;
	mergeSort(0, n-1);
	forn(i, n)
		tmp[arr[i]] = i;
	forn(i, n)
		cout << tmp[i]+1 << " ";
	cout << endl;
*/
/*
	n = 4;

	while(read(n) != EOF) {
		forn(i, n)
			cin >> arr[i];
		mergeSort(0, n-1);
		cout << endl;
	}
*/
	return 0;
}

