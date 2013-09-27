//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Item {
	int id, w;
	Item(int _id, int _w) {
		id = _id;
		w = _w;
	}
	bool operator < (const Item &a) const {
		return w < a.w;
	}
};

int main()
{
	int N, W;
	vector <Item> items;

	cin >> N >> W;
	
	for(int i = 0; i < N; i++){
		int w;
		cin >> w;
		items.push_back(Item(i, w));
	}
	sort(items.begin(), items.end());

	long long curWeight = 0;
	vector <vector <int> > ans;

	for(int i = 0; i < N; i++) {
		if(ans.empty() || curWeight + items[i].w > W) {
			ans.push_back(vector<int>(1, items[i].id));
			curWeight = items[i].w;
		}
		else {
			ans.back().push_back(items[i].id);
			curWeight += items[i].w;
		}
	}

	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}

	return 0;
}

