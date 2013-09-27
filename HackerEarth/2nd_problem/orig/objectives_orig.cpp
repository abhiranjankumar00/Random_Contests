//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include "header.h"

int64 f(int id, int64 a) {
	//return pow(a, id+4, mod);

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

/*int64 f(int id, int64 a) {
	int64 ret = 0;
	int64 p;
	if(id == 0)
			p = 12345;
	else if(id == 1)
			p = 14543;
	else if(id == 2)
//			p = 1e8 + 7;
			p = 12789ll;
	else
			assert(p < 0 || p > 2);

	while(a > 0) {
			ret = (ret + pow(a, p, mod)) % mod;
			a >>= 1;
	}
	return (ret + p/2) % mod;
}
*/
