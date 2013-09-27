#include <bits/stdc++.h>
using namespace std;

const int sz = 1e3 + 11;

int a[sz][sz];
int mx[sz], mn[sz];
int b[sz];
int N, K;

int getInt() {
  int ret = 0;
  char ch;
  while((ch = getchar_unlocked()) < '0' || (ch > '9')); 
  ret = ch - '0';
  while((ch = getchar_unlocked()) >= '0' && ch <= '9')
    ret = ret *10 + ch - '0';
  return ret;
} 

void solve() {
  int ans = 0;

  for(int i = 0; i < (int)N; ++i) {
    for(int k = 0; k < b[i]; k++) {
      int val = a[i][k];
      int less=0, great = 0;

      for(int j = 0; j < (int)N; ++j) if(i != j) {
        if(mx[j] < val)
          less++;
        else if(mn[j] < val)
          great++;
      }

      if(less < K && less + great >= K-1) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
}

int main()
{
  int test;
  test = getInt();

  while(test--) {
    N = getInt();
    K = getInt();

    for(int i = 0; i < (int)N; ++i) {
      b[i] = getInt();
      for(int k = 0; k < b[i]; k++) {
        a[i][k] = getInt();

        mn[i] = min(mn[i], a[i][k]);
        if(k == 0) {
          mx[i] = mn[i] = a[i][k];
        }
        else
          mx[i] = max(mx[i], a[i][k]);
      }
    }
    solve();
  }

	return 0;
}

