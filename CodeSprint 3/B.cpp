#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    int test;
    cin >> test; 
    
    while(test--) {
        long long A, B, C, ans = 0, d, total;
        cin >> A >> B >> C;
	printf("A = %lld, B = %lld, C = %lld\n", A, B, C);

	total = A*B;

	A = min(A, C);
	B = min(B, C);

	ans = (A*B);
	total *= 2;

	printf("total = %lld, ans = %lld\n", total, ans);
       
	d = __gcd(total, ans);
        
        cout << ans/d << "/" << total/d << endl;
	cout << endl;
    }
    
    return 0;
}
