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

const int sz = 100000;

int arr[sz];

int cnt[11];



int main()

{

	int T;

	scanf("%d", &T);



	while(T--) {

		memset(arr, 0, sizeof(arr));

		for(int i = 1, lets_stop_here = (int)9; i <= lets_stop_here; i++)

			scanf("%d", &cnt[i]);

		for(int n = 9, lets_stop_here = (int)1; n >= lets_stop_here; n--) {

			int idx = n;



			while(cnt[n]--) {

				while( arr[idx] != 0) {

					idx += n;

				}

				arr[idx] = n;

			}

		}

		int idx;

		for(idx = sz-1; idx > 0 && arr[idx] == 0; idx--);

		for(; idx > 0; idx--)

			printf("%d", arr[idx]);

		printf("\n");

	}



	return 0;

}
