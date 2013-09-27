//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force
//#include <stdio.h>
//#include <string.h>

#include <stdio.h>
#include <string.h>
typedef long long 		int64;
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
int N, M, p, r, k, wait = 0, car[55], completed = 0;
int i, j;
int u, v;
#define miN(a, b) (a < b? a : b)

int readInt() {
	int ret = 0;
	char ch ;

	while( (ch = getchar_unlocked()) < '0' || ch > '9')
		;
	ret = ch - '0';
	while( (ch = getchar_unlocked()) >= '0' && ch <= '9') {
		ret = ret * 10 + ch - '0';
	}

	return ret;
}
int cnt;
void solve() {

	for(u = 0; u < 55; u++)
		car[u] = -1;
	wait = 0, completed = 0;
	//cin >> N >> M >> wait >> p >> r >> k;
	N = readInt();
	M = readInt();
	wait = readInt();
	p = readInt();
	r = readInt();
	k = readInt();
	//Sf("%d %d %d %d %d %d", &N, &M, &wait, &p, &r, &k);

	for(u = 0; u < miN(wait, N); u++) {
//	forn(i, miN(wait, N)) {
		car[u] = 0;
		wait--;
	}

	for(i = 1; i <= k; i++) {
		if(M > 0 && i % r == 0) {
			M--;
			wait++;
		}

		for(j = 0; j < N; j++) {
			if(car[j] > -1) {
				car[j]++;
			}
			if(car[j] == p) {
				car[j] = -1;
				completed++;
			}
			if(wait > 0 && car[j] == -1) {
				wait--;
				car[j] = 0;
			}
		}
/*
		for(j = 0; j < N; j++)	if(car[j] == p) {
//		forn(j, N)	if(car[j] == p) {
			car[j] = -1;
			completed++;
		}
*/
/*
		//forn(j, N)	if(wait > 0 && car[j] == -1) {
		for(j = 0; j< N; j++)	if(wait > 0 && car[j] == -1) {
			wait--;
			car[j] = 0;
		}
*/
	}
	cnt = 0;
	for(i = 0; i < N; i++)
//	forn(i, N)
		if(car[i] == -1)
			cnt++;
	Pf("%d %d %d %d\n", cnt, completed, M, wait);
}

int main()
{
	int T;
	read(T);

	while(T--) {
		solve();
	}

	return 0;
}

