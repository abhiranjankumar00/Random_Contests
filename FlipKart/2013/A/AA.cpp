#include <bits/stdc++.h>
using namespace std;


void process_seq(const string& seq,map<char,set<int>>& loc)
{
  for (int i = 0; i < seq.length(); ++i)
  {
    loc[seq[i]].insert(i);
  }
}

int find_idx(char curr, char nxt, int idx,map < char, set < int >> &loc)
{
  auto itr=loc[nxt].lower_bound(idx + 1);

  if (itr == loc[nxt].end())return -1;

  return *itr;
}

pair<int, int> find_q(const string& seq, const string& q, map < char, set < int >> &loc)
{
  char start = q[0];
  pair<int, int> tmp(-1,-1);

  for (auto itr = loc[start].begin(); itr != loc[start].end(); ++itr)
  {
    int first = *itr;
    int till_now = first;
    char curr = q[0];

    for (int i = 1; i < q.length(); ++i)
    {
      char ch = q[i];

      int r=find_idx(curr, ch, till_now, loc);

      if (r == -1)
      {
        till_now = -1;
        break;
      }

      till_now = r;
    }

    if (till_now == -1)continue;

    if (till_now - first < tmp.second - tmp.first || tmp.first==-1)
    {
      tmp = make_pair(first, till_now);
    }
  }

  return tmp;
}

int main()
{
  int n; cin >> n;

  for (int i = 0; i < n; ++i)
  {
    string seq;
    while (seq.length() == 0){ getline(cin, seq); }

    map<char, set<int>> mp;
    process_seq(seq, mp);

    int n2; cin >> n2;

    for (int j = 0; j < n2; ++j)
    {
      string q;
      while (q.length() == 0){ getline(cin, q); }

      pair<int, int> p = find_q(seq, q, mp);

      if (p.first == -1)
        cout << -1 << endl;
      else cout << p.first +1<< "," << p.second +1<< endl;
    }
  }
  return 0;
}
