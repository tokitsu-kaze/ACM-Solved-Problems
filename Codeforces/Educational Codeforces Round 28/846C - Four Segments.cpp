#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int a[MAX];
ll sum[MAX];
ll get_sum(int l,int r)
{
	return sum[r]-sum[l];
}
int main()
{
	int n,i,j,k,x,y,z,pre,suf;
	ll ans,mx,tmp,now;
	scanf("%d",&n);
	sum[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	ans=0;
	x=y=z=0;
	for(j=0;j<=n;j++)
	{
		mx=-LLINF;
		now=0;
		for(i=j;~i;i--)
		{
			tmp=get_sum(0,i)-get_sum(i,j);
			if(tmp>mx)
			{
				mx=tmp;
				pre=i;
			}
		}
		now+=mx;
		
		mx=-LLINF;
		for(k=j;k<=n;k++)
		{
			tmp=get_sum(j,k)-get_sum(k,n);
			if(tmp>mx)
			{
				mx=tmp;
				suf=k;
			}
		}
		now+=mx;
		if(now>ans)
		{
			ans=now;
			x=pre;
			y=j;
			z=suf;
		}
	}
	printf("%d %d %d\n",x,y,z);
	return 0;
}
