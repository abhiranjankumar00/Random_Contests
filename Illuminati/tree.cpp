#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int par, int curDist, int &ans, int &ansLen, const vector <vector<int> > &G, vector <bool> &vis, const bool &flag) {
  if(vis[u]) {
    if(flag && curDist-1 > ansLen) {
      ansLen = curDist-1;
      ans = par;
    }
    return;
  }
  if(flag == false && curDist > ansLen) {
    ans = u;
    ansLen = curDist;
  }
  for(auto it = (G[u]).begin(); it != (G[u]).end(); ++it) if(*it != par) 
    dfs(*it, u, curDist+1, ans, ansLen, G, vis, flag);
}

bool tracePath(int u, int par, int v, const vector <vector<int> > &G, vector <bool> &vis) {
  if(u==v) {
//    printf("%d ", u+1);
    return vis[u] = true;
  }
  if(vis[u])
    return false;
  for(auto it = (G[u]).begin(); it != (G[u]).end(); ++it)
    if(*it != par) 
      if(tracePath(*it, u, v, G, vis)){
//        printf("%d ", u+1);
        return vis[u] = true;
      }
  return false;
}

int main()
{
  int N;
  cin >> N;
  vector <vector<int> > G(N);
  vector <bool> vis(N, false);
  set <int> leaves;
  
  for(int i = 0; i < (int)N-1; ++i) {
    int u, v;
    scanf("%d %d\n", &u, &v);
    u--; v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for(int i = 0; i < (int)N; ++i) 
    if(G[i].size() ==1)
      leaves.insert(i);

  int curAns = 1;
  printf("%d\n", curAns);

  if(N == 1) 
    return 0;

// dfs(u, par, curDist, &ans, &ansLen, &G, &vis) {
  
  int u, v=-1, dist = 0;
  bool flag = false;
  dfs(0, -1, 1, u, dist, G, vis, false);
  dist = 0;
  dfs(u, -1, 1, v, dist, G, vis, false);
  leaves.erase(u);
  leaves.erase(v);
  tracePath(u, -1, v, G, vis);
//  cout << "\n";
//  printf("Leaves removed: %d, %d\n", u, v);

  curAns = dist;
  printf("%d\n", curAns);

  flag = true;
  int mxDist;
  for(int i = (int)3; i <= (int)N; ++i) {
    if(leaves.empty() ){
      printf("%d\n", N);
    }
    else {
      v = mxDist= -1;
      int kill = -1;
      for(auto it = (leaves).begin(); it != (leaves).end(); ++it) {
        u = -1;
        dist = 0;
// dfs(u, par, curDist, &ans, &ansLen, &G, &vis) {
        dfs(*it, -1, 1, u, dist, G, vis, flag);
        if(dist > mxDist) {
          v = *it;
          kill = u;
          mxDist = dist;
        }
      }
      tracePath(v, -1, kill, G, vis);
//      cout << "\n";
      curAns += mxDist;
      leaves.erase(v);
      printf("%d\n", curAns);
    }
  }

  return 0;
}

