#include <bits/stdc++.h>
using namespace std;

void solve() {
  map <char, vector <int> > pos;
  string st;
  cin >> st;

  for(int i = 0; i < (int)st.size(); ++i) {
    pos[st[i]].push_back(i);
  }

  int N;
  cin >> N;

  while(N--) {
    int l = -1, r = -1;
    string order;
    cin >> order;
    int M = order.size();

    for(int i = 0; i < (int)order.size(); ++i) {
      if(pos.find(order[i]) == pos.end()) {
        printf("-1\n");
        return;
      }       
    }
    vector <int> & ord = pos[order[0]];

    for(int i = 0; i < (int)ord.size(); ++i) {
      int lt = ord[i], rt = ord[i];
      int j;
      for( j = (int)1; j <= (int)M-1; ++j) {
        vector <int> &tmp = pos[order[j]];
        auto it = lower_bound(tmp.begin(), tmp.end(), rt+1);
        if(it == tmp.end())
          break;
        rt = *it;
      }

      if(j == M) {
        if(l == -1) {
          l = lt, r = rt;
        }
        else if( rt - lt < r - l) {
          l = lt, r = rt;
        }
      }

    }

    if(l == -1) {
      printf("-1\n");
    }
    else
      printf("%d,%d\n", l+1, r+1);
  }
}

int main()
{
  int test;
  cin >> test;

  while(test--) {
    solve();
  }

	return 0;
}

