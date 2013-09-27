//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include "header.h"

int getBit(int idx, int64 n) {
	return (n & (1<<idx)) == 0 ? 0 : 1;
}

int64 resetBit(int idx, int64 n) {
	return n & ~(1<<idx);
}

int64 setBit(int idx, int64 n) {
	return n | (1<<idx);
}

int64 flipBit(int idx, int64 n) {
	if(getBit(idx, n))
		return resetBit(idx, n);
	else
		return setBit(idx, n);
}

void printBinary(int64 n) {
	rep(i, bitLength-1, 0)
		Pf("%d", getBit(i, n));
	Pf(" ");
}

int64 pow(int64 a, int64 b, int64 m) {
	if(b == 0)
		return 1ll;
	int64 ret = pow(a, b/2, m);
	ret = (ret*ret) % m;
	if(b % 2 == 1)
			ret = (ret*a) % m;
	return ret;
}


