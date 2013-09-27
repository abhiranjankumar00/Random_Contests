//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int N, W;
	cin >> N >> W;

	vector <int> weights(N);
	for(int i = 0; i < N; i++)
		cin >> weights[i];

	vector <vector <int> > ans;

	long long curWeight = 0;

	for(int i = 0; i < N; i++) {
		if(ans.empty() || curWeight + weights[i] > W) {
			ans.push_back(vector <int> (1, i));
			curWeight = weights[i];
		}
		else {
			curWeight += weights[i];
			ans.back().push_back(i);
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

