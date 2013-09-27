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
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

int main()
{
	int n, L;
	cin >> n >> L;
	int p[2] = {0, 0};

	for(int i = 0; i < n; ++i) {
		int t, d;
		cin >> t >> d;
		t--;
		if(d==-1)
			p[t]++;
		else if(d <= L)
			p[t]+=2;
		else
			p[t]+=3;
	}
	cout << p[0] << ":" << p[1];

	return 0;
}

