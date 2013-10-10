#include <bits/stdc++.h>
using namespace std;


int main()
{
  int R, K, N;
  cin >> R >> K >> N;
  int G[1001], i, j;

  for(i = 0; i < N; i++)
    cin >> G[i];

  long long mxSum = 0;
  int id = 0;

  for(i = 0; i < R; ++i) {
    int start = id;
    int tmpAns = G[curIdx];
    curIdx = (curIdx+1)%N;

    while(curIdx != st && tmpAns + g[curIdx] <= k) {
      tmpAns += g[curIdx];
      curIdx = (curIdx+1)%N;
    }
    ans += tmpAns;
  }
  cout << ans << "\n";

	return 0;
}

