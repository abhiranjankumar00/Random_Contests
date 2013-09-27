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

typedef long long int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

int main()

{

	int n;

	cin >> n;

	int64 cnt[2000];

	const int64 mod = 4207849484LL;



	for(int loop = 1, lets_stop_here = (int)n; loop <= lets_stop_here; loop++) {

		int m;

		ST st;

		cin >> m >> st;

		st = " " + st;

		fill(cnt, cnt+2000, 0);



		cnt[0] = 1;



		for(int i = 1, lets_stop_here = (int)st.size() - 0; i <= lets_stop_here; i++) {



			int j = 1;

			while(i+j <= st.size()) {

				int t = atoi(st.substr(i, j).c_str());

				if (t < 1 || t > m)

					break;

				cnt[i+j-1] = (cnt[i+j-1] + cnt[i-1]) % mod;



				j++;

			}



		}



		printf("Case #%d: %lld\n", loop, cnt[st.size()-1]);



	}



	return 0;

}
