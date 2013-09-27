/*
ID: nihcas700
LANG: C++
*/

# include <iostream>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cstdio>
# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <list>
# include <deque>
# include <new>
# include <stack>
# include <queue>
# include <iterator>
# include <functional>
# include <fstream>

 
using namespace std;


# define scd(x) scanf("%d",&x)
# define prd(x) printf("%d",x)
# define scf(x) scanf("%f",&x)
# define prf(x) printf("%f",x)
# define scs(x) scanf("%s",x)
# define prs(x) printf("%s",x)
# define prn() printf("\n")
# define inf 2000000000


int main()
{
	int t,N,L,H,a;
	scd(t);
	
	while(t--)
	{
		vector<int> V;
		vector<pair<int,pair<int,int> > > VV;
		scd(N);scd(L);scd(H);
		
		for(int i=1;i<=N;i++)
		{
			scd(a);
			V.push_back(a);
		}
		
		
		sort(V.begin(),V.end());
		//for(int i=0;i<V.size();i++)cout<<V[i]<<" ";cout<<endl;
		for(int i=0;i<V.size();i++)
		{
			for(int j=i+1;j<V.size();j++)
			{
				VV.push_back(make_pair(V[i]+V[j],make_pair(i,j)));
			}
		}
		
		//for(int i=0;i<VV.size();i++)cout<<VV[i].first<<" ";
		//cout<<endl;
		int cc=0;
		
		for(int i=0;i<VV.size();i++)
		{
			int aa= distance(V.begin(),lower_bound(V.begin(),V.end(),(L-VV[i].first)));
			int bb=distance(V.begin(),upper_bound(V.begin(),V.end(),H-VV[i].first));bb--;
			if(VV[i].second.second>bb)continue;
			else if(VV[i].second.second<aa)
			cc+=(bb-aa+1);
			else
			{
				cc+=(bb-VV[i].second.second);
			}
		}
		
		cout<<cc<<endl;
	}
	
	return 0;
}
