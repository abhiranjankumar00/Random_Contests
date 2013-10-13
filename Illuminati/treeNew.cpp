#include <bits/stdc++.h>
using namespace std;

const int sz = 2e5 + 111;
int N;
vector <int> G[sz];
bool vis[sz];
bool in[sz];
int par[sz], ht[sz];
bool flag;
set < pair <int, int>, greater<pair <int, int> > > leaves;

void dfs1(int u, int p, int curNodes, int &maxNodes, int &repNode) {
  par[u] = p;
  if(curNodes > maxNodes) {
    repNode = u;
    maxNodes = curNodes;
  }
  for(auto it = (G[u]).begin(); it != (G[u]).end(); ++it) if(*it != p) {
    dfs1(*it, u, curNodes+1, maxNodes, repNode);
  }
}

void tracePath(int from, int to) {
  while(from != to && in[from] == false) {
    in[from] = true;
    from = par[from];
  }
  if(from == to) {
    in[from] = true;
  }
}

int getHeightUpward(int u) {
  int &ret = ht[u];
  if(ret != -1)
    return ret;
  if(in[u])
    return ret = 0;
  ret = getHeightUpward(par[u]) + 1;
  if(G[u].size() ==1)
    leaves.insert(make_pair(ret, u));
  return ret;
}

void updateHeightDownward(int u, int h) {
  if(G[u].size() == 1) {
    leaves.erase(make_pair(ht[u], u));
    ht[u] = h;
    leaves.insert(make_pair(h, u));
  }
  for(auto it = (G[u]).begin(); it != (G[u]).end(); ++it) if(*it != par[u]){
    updateHeightDownward(*it, h+1);
  }
}

int main()
{
  int u, v;
  cin >> N;

  for(int i = 0; i < (int)N-1; ++i) {
    cin >> u >> v;
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int curAns = 1;
  printf("%d\n", curAns);

  if(N == 1)
    return 0;

  int p1 = -1, p2 = -1, maxNodes = 0;
  maxNodes = 0;
  dfs1(0, -1, 1, maxNodes, p1);
  maxNodes = 0;
  dfs1(p1, -1, 1, maxNodes, p2);

  tracePath(p2, p1);
  leaves.erase(make_pair(ht[p1], p1));
  leaves.erase(make_pair(ht[p2], p2));

  curAns = maxNodes;

  printf("%d\n", curAns);

  if(N == 2)
    return 0;

  memset(ht, -1, sizeof(ht));
  for(int i = 0; i < (int)N; ++i) {
    getHeightUpward(i);
  }

  for(int i = (int)3; i <= (int)N; ++i) {
    if(leaves.empty()) 
      printf("%d\n", N);
    else {
      curAns += leaves.begin()->first;
      printf("%d\n", curAns);
      u = leaves.begin()->second;
      in[u] = true;
      u = par[u];
      leaves.erase(leaves.begin());

      while(in[u]==false) {
        in[u] = true;
        for(auto it = (G[u]).begin(); it != (G[u]).end(); ++it) if(*it!=par[u] && !in[*it]){
          updateHeightDownward(*it, 1);
        }
        u = par[u];
      }
    }
  }


  return 0;
}

