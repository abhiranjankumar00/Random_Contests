#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
using namespace std;

typedef long long int64;

int64 N, v[111], c[111];
int64 dp[111][111];

int solve(int l, int r) {
    if(l < 0 || r >= N)
        return 0;
    if(r < l)
        return 0;
    
    int64 &ans = dp[l][r];
    
    if(ans > -1)
        return ans;
    
    if(l == r)
        return ans = c[l];
    
    ans = LONG_LONG_MAX;
    
    for(int i = l; i <= r; i++)
        ans = min(ans, c[i] + solve(l, i-v[i]-1) + solve(i+v[i]+1, r));
    
    return ans;
}

int main() {
    for(int i = 0; i < 111; i++)
        for(int j = 0; j < 111; j++)
            dp[i][j] = -1;
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> v[i];
    for(int i = 0; i < N; i++)
        cin >> c[i];
    
    cout << solve(0, N-1) << endl;
    
    return 0;
}
