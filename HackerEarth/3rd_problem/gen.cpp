//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	time_t tm; time(&tm); srand(tm);

	int N = 1e5, W = 1e5;

	cout << N << " " << W << endl;

	for(int n = 0; n < N; n++)
		cout << rand() % W + 1 << " ";
	cout << endl;

	return 0;
}

