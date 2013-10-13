#include <bits/stdc++.h>
using namespace std;

map <string, int> idx;
vector<int> G[55];
int maxTime, oilCost;
int s, d;
int dist[55][55], cost[55][55];
double chance[55][55];
double ans;

int getIdx(const string &st) {
  auto it = idx.find(st);
  if(it != idx.end())
    return it->second;
  return idx[st] = idx.size()-1;
}


void dfs(int u, int par, int curTime, int value, double prob) {
  if(curTime > maxTime)
    return;
  if(u == d) {
    double tmpAns = value + oilCost*(1-prob);
    ans = min(ans, tmpAns);
    return;
  }
  for(auto it = (G[u]).begin(); it != (G[u]).end(); ++it) if(*it != par){
    dfs(*it, u, curTime + dist[u][*it], value + cost[u][*it], prob*(1.0-chance[u][*it]));
  }
}

int main()
{
  int N;
  cin >> N;

  for(int i = 0; i < (int)N; ++i) {
    string source, dest;
    int time, _cost;
    double _chance;
    cin >> source >> dest >> time >> _cost >> _chance;
    int id1 = getIdx(source);
    int id2 = getIdx(dest);
    dist[id1][id2] = time;
    cost[id1][id2] = _cost;
    chance[id1][id2] = _chance/100.0;
    G[id1].push_back(id2);
  }


  N = idx.size();
  string source, dest;
  cin >> source >> dest >> maxTime >> oilCost;
  s = getIdx(source);
  d = getIdx(dest);

  ans = 1e20;

  dfs(s, -1, 0, 0, 1);
  printf("%0.9lf\n", ans);

  return 0;
}

