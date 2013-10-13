#include <bits/stdc++.h>
using namespace std;

int R, k, N;
long long g[1111], dp[1111];
int fin[1111];

long long cost;
int nextIdx;

long long solve(int &idx) {
  if(dp[idx] != -1){
    idx = fin[idx];
    return dp[idx];
  } 
  int st = idx;
  long long tmpAns = g[idx];
  idx = (idx+1)%N;

  while(idx != st && tmpAns + g[idx] <= k) {
    tmpAns += g[idx];
    idx = (idx+1)%N;
  }
  dp[st] = tmpAns;
  return tmpAns;
}

int main()
{
  memset(dp, -1, sizeof(dp));
  memset(fin, -1, sizeof(fin));
  
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

