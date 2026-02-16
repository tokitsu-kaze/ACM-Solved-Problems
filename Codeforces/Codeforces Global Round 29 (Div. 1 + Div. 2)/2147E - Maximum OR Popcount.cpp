#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],tmp[MAX];
int main()
{
	int T,n,q,i,j,k,s,x,now,res,ans[33],pos,mn,bs;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s|=a[i];
		}
		for(i=0;i<=32;i++) ans[i]=2e9;
		bs=__builtin_popcount(s);
		for(i=0;i<=bs;i++) ans[i]=0;
		for(j=30;~j;j--)
		{
			for(i=1;i<=n;i++) tmp[i]=a[i];
			res=0;
			for(k=j;~k;k--)
			{
				s=0;
				for(i=1;i<=n;i++) s|=a[i];
				if((s>>k)&1) continue;
				now=(1<<k);
				mn=2e9;
				for(i=1;i<=n;i++)
				{
					if(mn>now-(a[i]&(now-1)))
					{
						mn=now-(a[i]&(now-1));
						pos=i;
					}
				}
				res+=mn;
				a[pos]+=mn;
			}
			s=0;
			for(i=1;i<=n;i++) s|=a[i];
			ans[__builtin_popcount(s)]=res;
			for(i=1;i<=n;i++) a[i]=tmp[i];
		}
		while(q--)
		{
			scanf("%d",&x);
			printf("%d\n",upper_bound(ans,ans+32,x)-ans-1);
		}
	}
	return 0;
}
