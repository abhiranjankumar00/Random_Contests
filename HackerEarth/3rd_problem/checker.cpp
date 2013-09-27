//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <fstream>
#include <cassert>
using namespace std;

#define DEBUG(x) cout << #x << " = " << x << endl;

int main(int argc, char **argv)
{
	int maxScore = 200;

	assert(argc == 3);

	ifstream fin(argv[1]);
	ifstream fout(argv[2]);

	assert(fin != NULL);
	assert(fout != NULL);

	int N;
	long long W;

	fin >> N >> W;
	assert(N >= 1 && N <= 1e5);
	assert(W >= 1 && W <= 1e5);

	vector <int> weight(N);
	for(int i = 0; i < N; i++) {
		fin >> weight[i];
		assert(weight[i] >= 1 && weight[i] <= W);
	}
	fin.close();

	double score = 0;

	set <int> idx;
	int K;
	fout >> K;

	if(K <= 0 || K > N) {
		cerr << "K must be in [1, N]" << endl;;
		assert(K > 0 && K <= N);
	}

	int totalItem = 0;
	
	for(int k = 0; k < K; k++) {
		int M;
		fout >> M;
		totalItem += M;

		if(M < 1 || M > N) {
			cerr << "M must be in [1, N]" << endl;
			assert(M >= 1 && M <= N);
		}

		long long curWeight = 0;

		for(int i = 0; i < M; i++) {
			int item_id;
			fout >> item_id;

			if(item_id < 0 || item_id >= N) {
				cerr << "item_id must be in [0, N-1]" << endl;
				assert(item_id >= 0 && item_id < N);
			}

			curWeight += weight[item_id];
			idx.insert(item_id);
		}

		if(curWeight <= 0 || curWeight > W)  {
			cerr << "Total weight of items put in a single tiffin must lie between [1,W]" << endl;
			assert(curWeight > 0 && curWeight <= W);
		}
	}
	fout.close();

	if(totalItem != N) {
		cerr << "N items had not been considered while packing." << endl;
		assert(totalItem == N);
	}

	if(idx.size() != N) {
		cerr << "Food items have been repeated while packing.";
		assert(idx.size() == N);
	}

	score = 1.0*(N-K)/N*maxScore;
	printf("%0.2lf\n", score);

	return 0;
}

