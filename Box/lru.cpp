#include <bits/stdc++.h>
using namespace std;

//ostringstream ss;

class LRU {
  //static const int SZ = 26+26+10;
  static const int SZ = 26;

  inline int getIdx(char ch) {/*{{{*/
    return ch - 'a';
  }/*}}}*/

  class Node {/*{{{*/
  public:
    Node *child[SZ];
    string *value;
    bool isWord;
    int accessTime, prefixCnt;
    Node() {
      memset(child, 0, sizeof(child));
      isWord = false;
      accessTime = -1;
      value = nullptr;
      prefixCnt=0;
    }
  };
/*}}}*/

  Node *root;/*{{{*/
  int curTime;
  int lruSize;
  map <int, string> timeLine;
  string tmpString;
  char output[55];/*}}}*/

  int insert(int id, const string &key, const string &value, Node *nd) {/*{{{*/
    if(id == (int)key.size()) {
      nd->value = new string(value);
      if(nd->isWord) {
        updateTimeline(nd->accessTime);
        nd->accessTime = curTime-1;
        return 0;
      }
      else {
        nd->prefixCnt++;
        nd->isWord = true;
        addToTimeline(key);
        nd->accessTime = curTime-1;
        return 1;
      }
      //resizeLRU();
    }
    int idx = getIdx(key[id]);
    if(nd->child[idx] == nullptr)
      nd->child[idx] = new Node();
    int ret = insert(id+1, key, value, nd->child[idx]);
    nd->prefixCnt+=ret;
    return ret;
  }/*}}}*/

  void remove(int id, const string &key, Node *nd) {/*{{{*/
    nd->prefixCnt--;
    if(id == (int)key.size()) {
      nd->isWord = false;
      nd->accessTime = -1;
      return;
    }
    int idx = getIdx(key[id]);
    assert(nd->child[idx] != nullptr);
    remove(id+1, key, nd->child[idx]);
  }/*}}}*/

  void getValue(int id, const string &key, Node *nd, const bool modifyTimeline) {/*{{{*/
    if(id == (int) key.size()) {
      if(nd->isWord) {
        if(modifyTimeline) {
          updateTimeline(nd->accessTime);
          nd->accessTime = curTime-1;
        }
        tmpString = *(nd->value);
        return;
      }
      else
        tmpString = "NULL";
        return;
    }

    int idx = getIdx(key[id]);

    if(nd->child[idx] == nullptr) {
      tmpString = "NULL";
      return;
     }
    getValue(id+1, key, nd->child[idx], modifyTimeline);
  }/*}}}*/

  void updateTimeline(int tm) {/*{{{*/
    auto it = timeLine.find(tm);
    assert(it != timeLine.end());
    string tmp = it->second;
    timeLine.erase(it);
    timeLine[curTime++] = tmp;
  }/*}}}*/

  void addToTimeline(const string &key) {/*{{{*/
    timeLine[curTime++] = key;
  }/*}}}*/

  void resize() {/*{{{*/
    while((int)timeLine.size() > lruSize) {
      remove(0, timeLine.begin()->second, root);
      timeLine.erase(timeLine.begin());
    }
  }/*}}}*/

  void display(int len, Node *nd) {/*{{{*/
    assert(nd->prefixCnt >= 0);
    if(nd->prefixCnt == 0)
      return;
    if(nd->isWord) {
      //cout << output << " " << *(nd->value) << " : " << nd->accessTime <<  "\n";
      cout << output << " " << *(nd->value) << "\n";
      //ss << output << " " << *(nd->value) << "\n";
    }
//    printf("|%s|, ", output);
    for(int i = 0; i < (int)SZ; ++i) {
      if(nd->child[i] != nullptr) {
        output[len] = (char)(i+'a');
        display(len+1, nd->child[i]);
        output[len] = 0;
      }
    }
  }/*}}}*/
public:
  LRU() {/*{{{*/
    root = new Node();
    curTime = 0;
    lruSize = 1e7;
    timeLine.clear();
    memset(output, 0, sizeof(output));
  }/*}}}*/

  string peek(const string &key) {/*{{{*/
    getValue(0, key, root, false);
    return tmpString;
  }/*}}}*/

  string get(const string &key) {/*{{{*/
    getValue(0, key, root, true);
    return tmpString;
  }/*}}}*/

  void set(const string &key, const string &value) {/*{{{*/
    insert(0, key, value, root);
    resize();
  }/*}}}*/

  void setLruSize(int size) {/*{{{*/
    lruSize = size;
    resize();
  }/*}}}*/

  void dump() {/*{{{*/
    display(0, root);
  }/*}}}*/

  void getTimeline() {/*{{{*/
    for(auto it = (timeLine).begin(); it != (timeLine).end(); ++it) {
      printf("%d: %s\n", it->first, it->second.c_str());
    }
    cout << "\n";
    dump();
    cout << "\n";
  }/*}}}*/
};

int main()
{
  ios::sync_with_stdio(false);
  int iteration;
  int sz;
  LRU lru;
  string action, key, val;
  //scanf("%d", &iteration);
  cin >> iteration;
  
  while(iteration--) {/*{{{*/
    cin >> action;
    if(action[0] == 'B') {
      cin >> sz;
      //scanf("%d", &sz);
      lru.setLruSize(sz);
    }
    else if(action[0] == 'S'){
      cin >> key >> val;
      lru.set(key, val);
    }
    else if(action[0]=='P') {
      cin >> key ;
      val = lru.peek(key);
      cout << val << "\n";
      //ss << val << "\n";
    }
    else if(action[0] == 'G') {
      cin >> key;
      val = lru.get(key);
      cout << val << "\n";
      //ss << val << "\n";
    }
    else if(action[0] == 'D') {
      lru.dump();
      //cout << "\n";
      //cout << "\n";
    }
    else
      assert(0);
    //lru.getTimeline();
  }/*}}}*/

  //cout << ss.str() ;

	return 0;
}

