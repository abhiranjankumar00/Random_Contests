//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
#include <functional>	// Don't know why it is here.
#include <numeric>		// +1
#include <cassert>
#include <utility>		// +1
#include <sstream>
#include <iomanip>
#include <climits>
#include <ctime>
#include <iterator>
#include <fstream>
using namespace std;

class Trie {

	class Node {
		public:
		int cnt;
		Node *child[52];
		Node() {
			cnt = 0;
			memset(child, 0, sizeof(child));
		}
	} *root;

	int getIndex(char ch) {
		return (ch>='A' && ch<='Z')?ch-'A':26+ch-'a';
	}

	void _insert(int idx, const string &st, Node *nd) {
		if(idx == st.size()) {
			nd->cnt++;
			return;
		}
		int id = getIndex(st[idx]);
		if(nd->child[id] == nullptr) 
			nd->child[id] = new Node();

		_insert(idx+1, st, nd->child[id]);
	}

	void dfs(Node *nd, vector <char> &str, vector <int> &freq) {
		if(nd->cnt> 0) {
			/*
			for(auto it = (str).begin(); it != (str).end(); ++it) {
				cout << *it ;
			}
			*/
			freq.push_back(nd->cnt);
			//cout << ": " << nd->cnt << "\n";
		}
		for(int i = 0; i < 52; ++i) if(nd->child[i] != nullptr) {
			char ch = i<26?'A'+i:i-26+'a';
			str.push_back(ch);
			dfs(nd->child[i], str, freq);
			str.pop_back();
		}
	}

	void dfsSolve(Node *nd,vector<char> &str, map<int,int>&cnt, map<int,vector<string>>&ans) {
		if(cnt[nd->cnt] > 0) {
			string tmp;
			for(auto it = (str).begin(); it != (str).end(); ++it) 
				tmp += *it;
			cnt[nd->cnt]--;
			ans[nd->cnt].push_back(tmp);
		}

		for(int i = 0; i < 52; ++i) if(nd->child[i] != nullptr) {
			char ch = i<26?'A'+i:i-26+'a';
			str.push_back(ch);
			dfsSolve(nd->child[i], str, cnt, ans);
			str.pop_back();
		}
	}

	public:
	Trie() {
		root = new Node();
	}

	void insert(const string &st) {
		_insert(0, st, root);
	}
	vector <int> getFrequency() {
		vector <int> ret;
		vector <char> str;
		dfs(root, str, ret);
		return ret;
	}

	void solve(map <int, int> &cnt, map <int, vector <string> > &ans) {
		vector <char> str;
		dfsSolve(root, str, cnt, ans);
	}
};


int main()
{
	Trie trie;
	int N, K;
	cin >> N;
	for(int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for(auto it = (tmp).begin(); it != (tmp).end(); ++it) {
			assert((*it >= 'A' && *it <= 'Z') || (*it>='a' && *it<='z'));
		}
		trie.insert(tmp);
	}
	cin >> K;

	vector <int> freq = trie.getFrequency();

	sort(freq.begin(), freq.end(), greater<int>());
/*
	for(auto it = (freq).begin(); it != (freq).end(); ++it) {
		printf("%d ", *it);
	}
	cout << "\n";
*/
	map <int, int> cnt;
	map <int, vector<string> > ans;
	for(int i = 0; i < K; ++i) {
		cnt[freq[i]]++;
//		printf("%d ", i);
	}
//	cout << "\n";
	/*
	for(int i = 0; K>0; ++i) {
		cnt[freq[i]]++;
		K-=freq[i];;
	}
	*/
	
	trie.solve(cnt, ans);

	for(auto it = (ans).rbegin(); it != (ans).rend(); ++it) {
//		cout << it->first << ": ";
		for(auto jt = (it->second).begin(); jt != (it->second).end(); ++jt) {
			cout << *jt << "\n";
//			cout << *jt << ", ";
		}
//		cout << "\n";
	}

	return 0;
}

