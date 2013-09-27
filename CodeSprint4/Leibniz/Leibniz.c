#include<stdio.h>
double a[(int)1e7]={1};int t,d;main(){while(++t<1e7)a[t]=a[t-1]+(t&1?-1:1)/(2.0*t+1);for(scanf("%d",&t);t--;)scanf("%d",&d),printf("%.15lf\n",a[d-1]);}
