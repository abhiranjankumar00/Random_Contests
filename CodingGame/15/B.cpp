#include <bits/stdc++.h>
using namespace std;

const int sz = 1e4  + 111;

bool vis[sz] ;
int neigh[sz][2];
int money[sz];
int N;

int main()
{
  scanf("%d", &N);
  int idx;
  char str1[30], str2[30];

  for(int i = 0; i < (int)N; ++i) {
    scanf("%d", &idx);
    scanf("%d", &money[idx]);
    money[idx]*=-1;
    scanf("%s %s\n", str1, str2);

    if(str1[0] =='E') 
      neigh[idx][0] = -1;
    else
      neigh[idx][0] = atoi(str1);

    if(str2[0] == 'E')
      neigh[idx][1] = -1;
    else
      neigh[idx][1] = atoi(str2);
  }

  /*
  for(int i = 0; i < (int)N; ++i) {
    printf("%d: cost = %d, neigh = (%d, %d)\n", i, money[i], neigh[i][0], neigh[i][1]);
  }
  */

  //priority_queue < pair <int, int>, vector <pair <int, int> > , greater<pair <int, int> > > pq;
  priority_queue < pair <int, int> > pq;
  pq.push(make_pair(money[0], 0));
  int ans = -1;

  while(pq.empty() == false) {
    pair <int, int> nd = pq.top();
    pq.pop();
    int c = nd.first, u = nd.second;

    if(vis[u])
      continue;

    vis[u] = true;

    if(neigh[u][0] == -1 || neigh[u][1] == -1)
      ans = max(ans, -c);

    for(int i = 0; i < (int)2; ++i)  if(neigh[u][i] != -1){
      pq.push(make_pair(c + money[neigh[u][i]], neigh[u][i]));
    }
  }
  if(ans == -1)
    cout << "O\n";
  else
    cout << ans << "\n";

	return 0;
}

