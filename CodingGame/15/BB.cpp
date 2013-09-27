#include <bits/stdc++.h>
using namespace std;

const int sz = 1e4 + 111;

bool vis[sz] ;
int neigh[sz][2];
int money[sz];
int N;

class Node {
public:
  int cost, v, lvl;
  Node(int c, int u, int l) {
    cost = c; v = u; lvl = l;
  }

  bool operator <(const Node &ob) const {
    return 
  }
};

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


	return 0;
}

