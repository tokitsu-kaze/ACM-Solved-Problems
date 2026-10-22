#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
int a[MAX],pmn[MAX];
ll mn[MAX];
int main()
{
	int n,i,j;
	ll ans;
	scanf("%d",&n);
	for(i=0;i<(1<<n);i++)
	{
		scanf("%d",&a[i]);
		pmn[i]=i;
		mn[i]=a[i];
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<(1<<n)-1;i++)
		{
			if((i>>j)&1)
			{
				if(mn[i]>mn[i^(1<<j)])
				{
					mn[i]=mn[i^(1<<j)];
					pmn[i]=pmn[i^(1<<j)];
				}
			}
		}
	}
	ans=0;
	printf("%d\n",(1<<n)-1);
	for(i=0;i<(1<<n)-1;i++)
	{
		if(pmn[i]==i) pmn[i]=(1<<n)-1;
		printf("%d %d\n",i,pmn[i]);
		ans+=mn[i];
	}
	printf("%lld\n",ans);
	return 0;
}
/*
z=x&y，x,y,z 在一个连通块内的最小代价为 2*a[z]，所以可以连 x-z, y-z。
换句话说，x 往 x 的子集中最小的 pmn[x] 连就可以了。于是做个sosdp。
如果 pmn[x]=x，那直接往全集连。顺带发现 a[全集] 是不可能取到的。
*/
