#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int p[MAX],res[MAX],to[MAX];
char s[MAX];
bool vis[MAX];
int main()
{
	int t,n,i,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			res[i]=vis[i]=0;
		}
		scanf("%s",s+1);
		for(i=1;i<=n;i++)
		{
			x=i;
			while(!vis[x])
			{
				to[x]=i;
				res[i]+=(s[x]-'0')^1;
				vis[x]=1;
				x=p[x];
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",res[to[i]]," \n"[i==n]);
	}
	return 0;
}
