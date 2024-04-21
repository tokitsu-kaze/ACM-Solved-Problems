#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1005;
char s[MAX];
int mp[MAX][MAX],up[MAX][MAX];
ll now[MAX];
int st[MAX],top;
int main()
{
	int n,m,i,j,l,r;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=m;j++)
		{
			if(s[j]=='.') mp[i][j]=1;
			else mp[i][j]=0;
		}
	}
	memset(up[0],0,sizeof up[0]);
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(i>1&&mp[i][j]==mp[i-1][j]) up[i][j]=up[i-1][j]+1;
			else up[i][j]=1;
			if(mp[i][j]==0) up[i][j]=0;
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		top=0;
		now[0]=0;
		for(j=1;j<=m;j++)
		{
			now[j]=now[j-1];
			while(top&&up[i][st[top-1]]>up[i][j])
			{
				r=st[top-1];
				top--;
				if(top) l=st[top-1];
				else l=0;
				now[j]-=(r-l)*(up[i][r]-up[i][j]);
			}
			st[top++]=j;
			now[j]+=up[i][j];
			ans+=now[j];
		}
	}
	printf("%lld\n",ans);
}

