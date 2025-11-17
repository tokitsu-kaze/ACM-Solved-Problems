#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX],vis[MAX];
int main()
{
	int T,n,i,cnt,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		for(i=1;i<=n;i++) vis[i]=0;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(p[i]) vis[p[i]]=1;
			else cnt++;
		}
		l=INF;
		r=0;
		for(i=1;i<=n;i++)
		{
			if(!p[i])
			{
				if(cnt==1 && !vis[i]) continue;
			}
			if(!p[i] || i!=p[i])
			{
				l=min(l,i);
				r=max(r,i);
			}
		}
		printf("%d\n",max(0,r-l+1));
	}
	return 0;
}
