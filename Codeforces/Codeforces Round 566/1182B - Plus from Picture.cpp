#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char mp[505][505];
int main()
{
	int n,m,i,j,k,tot,now,ok,f;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	tot=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			tot+=(mp[i][j]=='*');
		}
	}
	ok=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='.') continue;
			now=1;
			f=0;
			for(k=i-1;k;k--)
			{
				if(mp[k][j]=='.') break;
				now++;
				f=1;
			}
			if(!f) continue;
			
			f=0;
			for(k=i+1;k<=n;k++)
			{
				if(mp[k][j]=='.') break;
				now++;
				f=1;
			}
			if(!f) continue;
			
			f=0;
			for(k=j-1;k;k--)
			{
				if(mp[i][k]=='.') break;
				now++;
				f=1;
			}
			if(!f) continue;
			
			f=0;
			for(k=j+1;k<=m;k++)
			{
				if(mp[i][k]=='.') break;
				now++;
				f=1;
			}
			if(!f) continue;
			if(now==tot) ok=1;
		}
	}
	if(ok) puts("YES");
	else puts("NO");
	return 0;
}

