#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX][12];
int vis[12][33],a[12],b[12];
int main()
{
	int n,m,i,j,ok,len;
	memset(vis,0,sizeof vis);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%s",s[i]+1);
		len=strlen(s[i]+1);
		for(j=1;j<=n;j++)
		{
			if(len==a[j]) vis[j][s[i][b[j]]-'a']=1;
		}
	}
	for(i=1;i<=m;i++)
	{
		len=strlen(s[i]+1);
		if(len!=n)
		{
			puts("No");
			continue;
		}
		ok=1;
		for(j=1;j<=n;j++)
		{
			if(!vis[j][s[i][j]-'a']) ok=0;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
