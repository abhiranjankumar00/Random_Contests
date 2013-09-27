//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include "header.h"

int main()
{
	time_t tm; time(&tm); srand(tm);

	vector <int64> solution(createSolutionSet());

	assert(solution.size() == sz);

	cout << solution.size() << endl;
	tr(it, solution) 
		Pf("%lld ", *it);
	cout << endl;

	return 0;
}

