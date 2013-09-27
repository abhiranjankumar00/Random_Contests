#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define mxm 1000
vector<pair<int,int> > a;
pair<int,int> profit[2][mxm];
int main(){
	//freopen("BERRY_5.in","r",stdin);
	//freopen("5.out","w",stdout);
	int c,m,v,i,j,pidx,cidx,mod,be,s,item;
	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&v,&m);
		a.clear();
		for(i=0;i<v;i++){
			scanf("%d",&s);
			a.push_back(make_pair(s % m, s));
		}
		sort(a.begin(),a.end());
		for(i=0;i<mxm;i++)for(j=0;j<2;j++){
			profit[j][i]=make_pair(-1,-1);
		}
		profit[0][0] = make_pair(0,0);
		pidx = 0;
		for(i=0;i<v;i++,pidx^=1){
			cidx=pidx^1;
			for(j=0;j<m;j++){
				profit[cidx][j]=profit[pidx][j];
				mod=a[i].first;
				item=a[i].second;
				pair<int,int> p = make_pair(profit[pidx][(j-mod+m)%m].first+1,\
				                            profit[pidx][(j-mod+m)%m].second+item);
				if(profit[pidx][(j-mod+m)%m].first>=0){
					if (p > profit[cidx][j]){
						profit[cidx][j] = p;
						//printf("Yeee %d : %d %d\n",j,p.first,p.second);
					}
				}
			}
		}
		printf("%d %d\n",profit[pidx][0].first,profit[pidx][0].second/m);
	}
	return 0;
}
