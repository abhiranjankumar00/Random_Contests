//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include "header.h"

int main()
{
	{ time_t tm; time(&tm); srand(tm); }

	vector <int64> solution(createSolutionSet());
	DEBUG(solution.size());
	tr(it, solution) {
		Pf("%lld: (%lld, %lld, %lld)\n", *it, f(0, *it), f(1, *it), f(2, *it));
	}
	cout << endl;


	return 0;
}

