#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int st[MAX],d[MAX];
ll a[MAX];
int main()
{
	int T,n,m,k,i,top,ans,pre,pos,nex;
	ll now,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=n;i++) scanf("%d%lld",&d[i],&a[i]);
		d[n+1]=INF;
		top=0;
		ans=0;
		for(i=1;i<=n+1;i++)
		{
			pre=d[i-1];
			now=0;
			while(top)
			{
				pos=st[top-1];
				top--;
				/*
				最多喝几天，不超过d[i]，因为d[i]要喝最新的
				*/
				nex=min(d[i],d[pos]+k)-pre;
				now+=a[pos];// 有多少牛奶
				if(nex<=0)
				{
					top=0;
					break;
				}
				mn=min(now/m,1LL*nex);
				pre+=mn;
				ans+=mn;
				now-=mn*m;
				if(pre==d[i])
				{
					st[top++]=pos;
					a[pos]=now;
					break;
				}
			}
			st[top++]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
