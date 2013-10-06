#include <bits/stdc++.h>
using namespace std;

const int sz = 1e4 + 111;
bool isPrime[sz];
vector <int> primes;

int main()
{
  memset(isPrime, -1, sizeof(isPrime));
  isPrime[0] = isPrime[1] = false;
  for(int i = 0; i < (int)sz; ++i) if(isPrime[i]) {
    primes.push_back(i);
    for(int j = i+i; j < sz; j+=i)
      isPrime[j] = false;
  }
  while(primes.back() > 1000) {
    primes.pop_back();
  }
  int n = primes.size();

  printf("%d %d", primes[n-2], primes[n-1]);


	return 0;
}

