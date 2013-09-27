//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include "header.h"

int64 f(int id, int64 a) {
	int64 ret;
	if(id == 0)
		ret = pow(a, 34, mod) - pow(a, 24, mod) ;
	else if(id == 1)
		ret = pow(a, 123, mod) + pow(a, 523, mod);
	else if(id == 2)
		ret = pow(a, 535, mod) - pow(a, 1234, mod);
	else
		assert(id < 0 || id > 2);
	ret = (ret % mod + mod) % mod;
	return (ret+mod/2) % mod;
}
