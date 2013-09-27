#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin >> a[i][j];
	vector<int>tour;
	int tmp;
	while(cin >> tmp) tour.push_back(tmp);
	double score = 0;
	int nn = tour.size();
	if(nn != n) { 
		score = 0; 
		return 0;
	}
	for(int i=0;i<nn;i++) 
		if(tour[i] < 0 || tour[i] >= n){ 
			score = 0; 
			return 0;
		}
	int tourLength = 0;
	for(int i=1;i<n;i++){
		int x = tour[i], y = tour[i-1];
		if(a[x][y] == 0) {score = 0; return 0;}
		else tourLength += a[x][y];
	}
	score = 10*(n-1) - tourLength; // 10*(n-1) can be the maximum length of any tour, so small tourLength means better score.

	score = (score/(10.0*(n-1)))*100.0; //score will be between 0 and 100
	return 0;
	
}
