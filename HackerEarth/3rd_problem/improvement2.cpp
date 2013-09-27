//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

struct Item {
	int id, w;
	Item(int _id, int _w) {
		id = _id;
		w = _w;
	}
	bool operator < (const Item &item) const {
		if(this->w != item.w)
			return this->w < item.w;
		else
			return this->id < item.id;
	}
};

int main()
{
	int N, W;
	set <Item> st;
	vector <vector <Item> > ans;

	cin >> N >> W;
	for(int i = 0; i < N; i++) {
		int w;
		cin >> w;
		st.insert(Item(i, w));
	}

	long long curWeight = 0;

	while(st.empty() == false) {

		if(ans.empty()) {
			Item nd = *st.begin();
			ans.push_back(vector <Item>(1,nd));
			curWeight = nd.w;
			st.erase(st.begin());
			continue;
		}

		long long reqWeight = W - curWeight;
		auto it = st.lower_bound(Item(-1, reqWeight));

		if(it != st.end() && it->w <= reqWeight) {
			ans.back().push_back(*it);
			curWeight += it->w;
			st.erase(it);
			continue;
		}

		if(it != st.begin()) {
			auto jt = it;
			jt--;
			if(jt->w <= reqWeight) {
				ans.back().push_back(*jt);
				curWeight += jt->w;
				st.erase(jt);
				continue;
			}
		}
		Item nd = *st.begin();
		ans.push_back(vector <Item> (1, nd));
		curWeight = nd.w;
		st.erase(st.begin());
	}

	cout << ans.size() << endl;

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j].id << " ";
		cout << endl;
	}

	return 0;
}

