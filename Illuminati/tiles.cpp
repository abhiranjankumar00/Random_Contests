#include <bits/stdc++.h>
using namespace std;

const int oo = 1e8;

int X[] = { 1, -1, 0,  0};
int Y[] = { 0,  0, 1, -1};

bool valid(int y, int x, int H, int W, vector <string> G) {
  return y >= 0 && y < H && x >= 0 && x < W && G[y][x] != 'x';
}

int main()
{
  int W, H;
  cin >> W >> H;

  vector <string> G(H);
  int sY, sX;
  vector <pair <int, int> > points; 
  int dist[22][22][22][22];

  for(int y = 0; y < (int)H; ++y) {
    cin >> G[y];
    for(int x = 0; x < (int)W; ++x) {
      if(G[y][x] == 'o') {
        sX = x, sY = y;
      }
      else if(G[y][x] == '*')
        points.push_back(make_pair(x, y));
    }
  }
  sort(points.begin(), points.end());

  for(int y1 = 0; y1 < (int)H; ++y1) {
    for(int x1 = 0; x1 < (int)W; ++x1) {
      for(int y2 = 0; y2 < (int)H; ++y2) {
        for(int x2 = 0; x2 < (int)W; ++x2) {
          if(y1 == y2 && x1 == x2 && G[y1][x1] != 'x') 
            dist[y1][x1][y2][x2] = 0;
          else
            dist[y1][x1][y2][x2] = oo;
        }
      }
    }
  }

  for(int y1 = 0; y1 < (int)H; ++y1) {
    for(int x1 = 0; x1 < (int)W; ++x1) {
      for(int add = 0; add < (int)4; ++add) {
        int x2 = x1 + X[add], y2 = y1 + Y[add];
        if(valid(y1, x1, H, W, G) && valid(y2, x2, H, W, G)) {
          dist[y1][x1][y2][x2] = 1;
          dist[y2][x2][y1][x1] = 1;
        }
      }
    }
  }

  for(int y2 = 0; y2 < (int)H; ++y2) {
    for(int x2 = 0; x2 < (int)W; ++x2) {
      for(int y1 = 0; y1 < (int)H; ++y1) {
        for(int x1 = 0; x1 < (int)W; ++x1) {
          for(int y3 = 0; y3 < (int)H; ++y3) {
            for(int x3 = 0; x3 < (int)W; ++x3) {
              int tmpDist = dist[y1][x1][y2][x2] + dist[y2][x2][y3][x3];
              dist[y1][x1][y3][x3] = min(dist[y1][x1][y3][x3], tmpDist);
            }
          }
        }
      }
    }
  }

  if(points.size() == 0) {
    cout << 0 << "\n";
    return 0;
  }

  for(int i = 0; i < (int)points.size(); ++i) {
    int x1 = points[i].first, y1 = points[i].second;

    if(dist[y1][x1][sY][sX] == oo) {
      cout << -1 << "\n";
      return 0;
    }

    for(int j = 0; j < (int)points.size(); ++j) {
      int x2 = points[j].first, y2 = points[j].second;
      if(dist[y1][x1][y2][x2] == oo) {
        cout << -1 << "\n";
        return 0;
      }
    }
  }

  int ans = oo;

  do{
    int y = sY, x = sX;
    int curDist = 0;
    for(int i = 0; i < (int)points.size(); ++i) {
      int xx = points[i].first, yy = points[i].second;
      curDist += dist[y][x][yy][xx];
      x = xx;
      y = yy;
    }
    ans = min(ans, curDist);
  }while(next_permutation(points.begin(), points.end()));

  cout << ans << "\n";

	return 0;
}

