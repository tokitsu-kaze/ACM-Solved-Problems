#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
char mp[MAX][MAX];
int main()
{
	int T,n,m,i,j,ok,f;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
		ok=1;
		for(i=1;i<=n;i++)
		{
			f=0;
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='U')
				{
					if(f) mp[i][j]='B';
					else mp[i][j]='W';
					f^=1;
				}
				else if(mp[i][j]=='D')
				{
					if(mp[i-1][j]=='B') mp[i][j]='W';
					else mp[i][j]='B';
				}
			}
			if(f) ok=0;
		}
		for(j=1;j<=m;j++)
		{
			f=0;
			for(i=1;i<=n;i++)
			{
				if(mp[i][j]=='L')
				{
					if(f) mp[i][j]='B';
					else mp[i][j]='W';
					f^=1;
				}
				else if(mp[i][j]=='R')
				{
					if(mp[i][j-1]=='B') mp[i][j]='W';
					else mp[i][j]='B';
				}
			}
			if(f) ok=0;
		}
		if(!ok) puts("-1");
		else
		{
			for(i=1;i<=n;i++)
			{
				mp[i][m+1]='\0';
				puts(mp[i]+1);
			}
		}
	}
	return 0;
}
/*
发现每行的UD和每列的LR必是成对出现的 
*/
