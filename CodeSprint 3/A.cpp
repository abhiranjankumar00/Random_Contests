#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define forab(i, a, b) for(int i = a ; i <= (int)b; i++)
#define forn(i, n)     forab(i, 0, n-1)

int main() {
	int K;
	char tmpG[111][111];
	bool G[111][111];
	int arr[111], idx[111];

	cin >> K;
	forn(i, K) {
		cin >> arr[i];
		arr[i]--;
		idx[arr[i]] = i;
	}
	forn(i, K)
		cin >> tmpG[i];

	forn(i, K)
		forn(j, K)
			if(i == j ||  tmpG[i][j] == 'Y')
				G[i][j] = true;

	forn(l, K)
		forn(i, K)
			forn(j, K)
				G[i][j] |= (G[i][l] && G[l][j]);
/*
	forn(i, K) {
		forn(j, K)
			if(G[i][j])
				printf("(%d - %d),  ", i, j);
	}
	cout << endl << endl;
*/
	bool used[111] = {};
	for(int next = 0; next < K; next++) {
		int id = -1;
		for( id = 0; next != arr[id]; id++);
//		printf("arr = ");
//		forn(j, K)
//			cout << arr[j]+1 << " ";
//		cout << endl;
		int lst = -1;
		forn(j, K)	if(G[id][j] && !used[j]) {
			used[j] = true;
			swap(arr[j], arr[id]);
			idx[arr[id]] = id;
			idx[arr[j]] = j;
			break;
		}
	}
/*
	forn(ijk, K) {
		int i = idx[ijk];
		forn(j, K)
			if(G[i][j] && used[j] == false) {
				used[j] = true;
//				printf("%d <-> %d\n", arr[i]+1, arr[j]+1);
				swap(arr[j], arr[i]);
				idx[arr[j]] = j;
				idx[arr[i]] = i;
				break;
			}
	}
*/
	forn(i, K)
		cout << arr[i]+1 << " ";

	return 0;
}
