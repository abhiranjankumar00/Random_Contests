#include <bits/stdc++.h>
using namespace std;

const int sz = 1111;

bool vis[sz][sz];
char g[sz][sz];

bool beerMode = false;
bool inverseMode = false;

bool valid(int x, int y) {/*{{{*/
  if(g[y][x] == '#' || (g[y][x] == 'X' && beerMode == false))
    return false;
  return true;
}/*}}}*/

//map <char, int> turn;
char tmpTurn[4];
vector <pair <int, int> > tele;
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

int main()
{
//  turn['S']=0; turn['E']=1; turn['N'] = 2; turn['W']=3;
  tmpTurn[0]='S', tmpTurn[1]='E', tmpTurn[2]='N', tmpTurn[3]='W';
  memset(vis, 0, sizeof(vis));

  int L, C;/*{{{*/
  scanf("%d %d\n", &L, &C);
//  cout << "L = " << L << "\n";
 // cout << "C = " << C << "\n";

  int curX=-1, curY=-1;
  int finX = -1, finY = -1;
  for(int i = 0; i < (int)L; ++i) {
    scanf("%[^\n]\n", g[i]);
    printf("%2d: %s\n",i, g[i]);

    for(int j = 0; j < (int)C; ++j) {
      if(g[i][j] == '@') {
        //curX = i, curY = j;
        curX = j, curY = i;
      }
      if(g[i][j] == '$') {
        //finX = i, finY = j;
        finX = j, finY = i;
      }
      if(g[i][j] == 'T') {
        //tele.push_back(make_pair(i, j));
        tele.push_back(make_pair(j, i));
      }
    }
  }
/*}}}*/
  vector<char> ans;
  int idAdd = 0;
  int xAdd = X[idAdd], yAdd = Y[idAdd];
  vis[curY][curX] = true;

  while(curX != finX || curY != finY) {
    printf("(beer=%d: %d, %d), ", beerMode?1:0, curX, curY);

    if(g[curY][curX] == 'B')
      beerMode = !beerMode;
    if(g[curY][curX] == 'I')
      inverseMode = !inverseMode;

    if(g[curY][curX] == 'S')
      idAdd = 0;
    if(g[curY][curX] == 'E')
      idAdd = 1;
    if(g[curY][curX] == 'N')
      idAdd = 2;
    if(g[curY][curX] == 'W') 
      idAdd = 3;

    xAdd = X[idAdd], yAdd = Y[idAdd];
    int tmpX = curX + xAdd, tmpY = curY + yAdd; 
    printf("%d: (%d, %d)",idAdd, tmpX, tmpY);

    if(valid(tmpX, tmpY)) {
      printf("Valid\n\n");

      if(g[tmpY][tmpX] == 'X') {
        g[tmpY][tmpX] = ' ';
        memset(vis, 0, sizeof(vis));
      }

      if(vis[tmpY][tmpX]) {
        ans.clear();
        break;
      }
      ans.push_back(tmpTurn[idAdd]);
      curX = tmpX, curY = tmpY;

      for(int i = 0; i < (int)tele.size(); ++i) {
        if(curX==tele[i].first && curY==tele[i].second) {
          curX = tele[1-i].first;
          curY = tele[1-i].second;
          break;
        }
      }

      vis[curY][curX] = true;
      continue;
    }

    printf("Invalid\n\n");
    bool isvalid = false;
    if(inverseMode) {
      for(int i = (int)3; i >= (int)0; --i) {
        int tmpX = curX + X[i], tmpY = curY + Y[i];
//        printf("(%d, %d), ", tmpX, tmpY);
        if(valid(tmpX, tmpY)) {
          curX = tmpX, curY=tmpY;
          if(g[curY][curX] == 'X') {
            g[curY][curX] = ' ';
            memset(vis, 0, sizeof(vis));
          }

//          cout << "\n";
          idAdd = i;
          vis[curY][curX]=true;
          isvalid = true;
          ans.push_back(tmpTurn[idAdd]);
          break;
        }
      }
      if(!isvalid) {
        ans.clear();
        break;
      }
    }
    else {
      for(int i = (int)0; i < (int)4; ++i) {
        int tmpX = curX + X[i], tmpY = curY + Y[i];
//        printf("(%d, %d), ", tmpX, tmpY);
        if(valid(tmpX, tmpY)) {
          curX = tmpX, curY=tmpY;
          if(g[curY][curX] == 'X') {
            g[curY][curX] = ' ';
            memset(vis, 0, sizeof(vis));
          }

//          cout << "\n";
          idAdd = i;
          vis[curY][curX]=true;
          isvalid = true;
          ans.push_back(tmpTurn[idAdd]);
          break;
        }
      }
      if(!isvalid) {
        ans.clear();
        break;
      }
    }
  }

  if(ans.empty())
    cout << "LOOP\n";
  else for(auto it = (ans).begin(); it != (ans).end(); ++it) {
    char ch = *it;
    if(ch == 'W')
      cout << "WEST" ;
    else if(ch == 'E')
      cout << "EAST";
    else if(ch == 'S')
      cout << "SOUTH";
    else
      cout << "NORTH";
    cout << "\n";
  }

	return 0;
}

