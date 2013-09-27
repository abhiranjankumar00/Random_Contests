#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include <cassert>
using namespace std;

#define MAXN 500
#define MAXM 100000
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int s[MAXN];
int mem[2][MAXM];
int sum[2][MAXM];

void testcase() {
	int n, m, i, j, k;
	cin >> n >> m;
//	scanf("%d %d\n", &n, &m);
	assert(n >= 1 && n <= 500);
	assert(m >= 1 && m <= 1000);

	for(i=0;i<n;i++) {
//		scanf("%d", &s[i]);
		cin >> s[i];
		assert(s[i] >= 1 && s[i] <= 1000000);
	}

	memset(mem, 0, sizeof(mem));
	memset(sum, 0, sizeof(sum));

	k = 0;
	for(i=0;i<n;i++) {

		for(j=0;j<m;j++) {
			mem[k][j] = mem[1-k][j];
			sum[k][j]=sum[1-k][j];
		}

		for(j=0;j<m;j++) {
			if(mem[1-k][j]>0 || j==0) {
				//mem[k][(j+s[i])%m] = MAX(mem[k][(j+s[i])%m], mem[1-k][j]+1);
				if(mem[1-k][j]+1>=mem[k][(j+s[i])%m]) //priority 1 
				{
					mem[k][(j+s[i])%m] = mem[1-k][j]+1;                
					if( sum[1-k][j]+s[i] > sum[k][(j+s[i])%m]) //priority 2
						sum[k][(j+s[i])%m] = sum[1-k][j]+s[i];
				}
			}
		}
				
		k = 1-k;
	    
	}
	cout << mem[1-k][0] << " " << sum[1-k][0]/m << endl;
//	printf("%d %d\n", mem[1-k][0],sum[1-k][0]/m);
}

int main() {
    int t;
    scanf("%d\n", &t);
    while(t--) 
	    testcase();
    return 0;
}
