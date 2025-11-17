#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int pos[MAX],a[MAX];
int main()
{
	int T,n,m,d,i,ans,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			pos[x]=i;
		}
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		ans=INF;
		for(i=1;i<m;i++)
		{
			if(pos[a[i]]>pos[a[i+1]])
			{
				ans=0;
				break;
			}
			if(pos[a[i+1]]>pos[a[i]]+d)
			{
				ans=0;
				break;
			}
			x=pos[a[i+1]]-pos[a[i]];
			ans=min(ans,x);
			if(1+d<n) ans=min(ans,d-x+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
