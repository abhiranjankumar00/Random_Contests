#include <bits/stdc++.h>
using namespace std;

int R, k, N;
long long g[1111];

long long solve(int &st) {
  int l = st;
  long long ret = 0;
  st = (st+1)%N;
  while(st != l && ret + g[st] <= k) {
    ret += g[st];
    st = (st+1)%N;
  }
  return ret;
}

int main()
{
  
  scanf("%d %d %d", &R, &k, &N);
  for(int i = 0; i < (int)N; ++i) {
    scanf("%lld ", &g[i]);
  }

  int curIdx = 0;
  long long ans= 0;

  for(int i = 0; i < (int)R; ++i) {
    ans += solve(curIdx);
  }
  cout << ans << "\n";

	return 0;
}

