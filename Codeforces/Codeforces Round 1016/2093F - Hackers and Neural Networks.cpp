#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
char a[MAX][12],s[MAX];
int vis[MAX];
int main()
{
	int T,n,m,i,j,ans,cnt;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%s",a[i]);
			vis[i]=0;
		}
		ans=INF;
		while(m--)
		{
			cnt=0;
			for(i=1;i<=n;i++)
			{
				scanf("%s",s);
				if(strcmp(a[i],s)==0)
				{
					vis[i]=1;
					cnt++;
				}
			}
			ans=min(ans,n+(n-cnt)*2);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0) ans=-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

