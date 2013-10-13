#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
  int u, v, w;
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
  bool operator <(const Edge &ob) const { return w < ob.w;}
};

int findSet(int u, vector <int> &par) {
  return par[u] = par[u] == u ? u : findSet(par[u], par);
}

void mergeSet(int u, int v, vector <int> &par) {
  int pu = findSet(u, par), pv = findSet(v, par);
  if(pu < pv)
    par[pv] = pu;
  else
    par[pu] = pv;
}

int main()
{
  int N, E;
  cin >> N >> E;
  vector <Edge> edges; 
  vector <int> par(N+1);

  for(int i = 0; i < (int)N+1; ++i) {
    par[i] = i;
  }

  for(int i = 0; i < (int)E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(Edge(u, v, w));
  }
  sort(edges.begin(), edges.end());

  int T1, T2;
  cin >> T1 >> T2;

  long long baseCost = 0;

  for(auto it = (edges).begin(); it != (edges).end(); ++it) {
    int u = it->u, v = it->v, w = it->w;
    if(findSet(u, par) != findSet(v, par)) {
      baseCost += w;
      mergeSet(u, v, par);
    }
  }

  if(baseCost <= 0)
    cout << T1 << "\n";
  else
    cout << T2 << "\n";

	return 0;
}

