#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int mn[MAX],mx[MAX];
int ask(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}
int main()
{
	int T,n,i,q,l,r,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			mx[i]=-1;
			mn[i]=n+1;
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			mx[l]=max(mx[l],r);
			mn[r]=min(mn[r],l);
		}
		ans=0;
		if(ask(1,n/2))
		{
			for(i=1;i<=n/2;i++)
			{
				if(mx[i]==-1) continue;
				ans=max(ans,ask(i,mx[i]));
			}
		}
		else
		{
			for(i=n/2+1;i<=n;i++)
			{
				if(mn[i]==n+1) continue;
				ans=max(ans,ask(mn[i],i));
			}
		}
		printf("! %d\n",ans);
		fflush(stdout);
	}
	return 0;
}
