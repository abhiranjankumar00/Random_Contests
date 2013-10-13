#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, S, x1, y1, x2, y2, N;
  map <pair <int, int> , pair <int, int> > mp;
  cin >> A >> S;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> N;

  for(int i = 0; i < (int)N; ++i) {
    int x, y, p, d;
    string tmp;
    cin >> tmp >> x >> y >> p >> d;
    mp[make_pair(x, y)] = make_pair(p, d);
  }

  auto valid = [&mp, &x1, &x2, &y1, &y2](int xx, int yy) -> bool{
    if(mp.find(make_pair(xx, yy)) != mp.end())
      return false;
    if(xx == x1 && yy == y1)
      return false;
    if(xx == x2 && yy == y2)
      return false;
    return true;
  };

  auto cost = [&mp](int x, int y) -> int {
    int ret = 0;
    for(auto it = (mp).begin(); it != (mp).end(); ++it) {
      int dist = abs(it->first.first - x) + abs(it->first.second - y);
      ret += max(0, it->second.first - dist*it->second.second);
    }
    return ret;
  };

  int xAns = -1, yAns = -1;
  int minDiff = 1e9, minCost = 1e9;

  for(int x = 0; x < (int)S; ++x) {
    for(int y = 0; y < (int)S; ++y) {
      if(valid(x, y)) {
        int value = cost(x, y);
        if(value > A)
          continue;
        int dist1 = abs(x - x1) + abs(y - y1);
        int dist2 = abs(x - x2) + abs(y - y2);
        int diff = abs(dist1 - dist2);
        if(diff<minDiff || (diff==minDiff && value<minCost) || (diff==minDiff && value==minCost && (x<xAns || (x==xAns && y<yAns)))){
          minDiff = diff;
          xAns = x;
          yAns = y;
          minCost = value;
        }
      }
    }
  }

  if(xAns == -1) {
    cout << "NO" << "\n";
  }
  else  {
    printf("(%d,%d) : %d\n", xAns, yAns, minCost);
  }
	return 0;
}

