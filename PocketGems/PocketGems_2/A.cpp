#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

const int sz = 2e4 + 111;
/*
struct Node {
    int a, w;
    Node () {};
        Node (int _a, int _w) {
            a = _a;
            w = _w;
        }
    bool operator < (const Node &ob) const {
        return this->a < ob.a;
    }
};
*/
int tree[4*sz];
int id[sz], w[sz], N;

void update(int idx, int val, int node = 1, int l = 0, int r = 10001) {
//	printf("idx = %d, val = %d, node = %d, l = %d, r = %d\n", idx, val, node, l, r);
    if(l == r) {
        assert(l == idx);
        tree[node] = max(tree[node], val );
	return;
    }
    int mid = (l+r)/2;
    if(idx <= mid)
    	update(idx, val, 2*node, l, mid);
  else
    	update(idx, val, 2*node+1, mid+1, r);
    tree[node] = max(tree[2*node], tree[2*node + 1]);
}

int get(int i, int j, int node = 1, int l = 0, int r = 10001){
   if(l >= i && r <= j)
       return tree[node];
    
   int mid = (l+r)/2;
   if(j <= mid)
       return get(i, j, 2*node, l, mid);
   
    if(i > mid)
        return get(i, j, 2*node+1, mid+1, r);
    
    return max(get(i, j, 2*node, l, mid), get(i, j, 2*node+1, mid+1, r));
}
    
int main() {
        
    for(scanf("%d", &N); N > 0; scanf("%d", &N)) {
        memset(tree, 0, sizeof(tree));
        int ans = 0;
        
        for(int i = 0; i< N; i++)
            scanf("%d ", &id[i]);
        
        for(int i = 0; i< N; i++)
            scanf("%d ", &w[i]);
        
        for(int i = 0; i < N; i++) {
            int tmpAns = 0;
            
            if(id[i] == 0) {
                ans = max(ans, w[i]);
                update(0, w[i]);
            }
            else {
                tmpAns = get(0, id[i]-1);
                tmpAns += w[i];
                ans = max(ans, tmpAns);
                update(id[i], tmpAns);
            }
//	    cout << endl;
                 
        }
        printf("%d\n", ans);
        
    }

    return 0;
}
