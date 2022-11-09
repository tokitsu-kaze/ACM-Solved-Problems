#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int v[100010];
int cmp(const void *a,const void *b)
{
	if(*(int *)a<*(int *)b) return 1;
	else if(*(int *)a==*(int *)b) return 0;
	else return -1;
}
int min(int a,int b)
{
	if(a<b) return a;
	return b;
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int i,n,d,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		qsort(v,n,sizeof(v[0]),cmp);
		d=0;
		for(i=1;i<n;i++)
		{
			d=gcd(d,v[i]-v[i-1]);
		}
		ans=0;
		for(i=1;i<n;i++)
		{
			ans+=(v[i]-v[i-1])/d-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}