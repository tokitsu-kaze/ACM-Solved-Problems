#include<bits/stdc++.h>
using namespace std;
int mp[1010][1010],up[1010][1010],l[1010],r[1010];
int st[1010],top;
int main()
{
	int n,m,i,j,ans;
	char s[3];
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%s",s);
			if(s[0]=='R') mp[i][j]=0;
			else mp[i][j]=1;
		}
	}
	memset(up[0],0,sizeof up[0]);
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(mp[i][j]) up[i][j]=up[i-1][j]+1;
			else up[i][j]=0;
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		top=0;
		up[i][m+1]=-1;
		for(j=1;j<=m+1;j++)
		{
			while(top&&up[i][st[top-1]]>up[i][j])
			{
				r[st[top-1]]=j-1;
				top--;
			}
			st[top++]=j;
		}
		top=0;
		up[i][0]=-1;
		for(j=m;~j;j--)
		{
			while(top&&up[i][st[top-1]]>up[i][j])
			{
				l[st[top-1]]=j+1;
				top--;
			}
			st[top++]=j;
		}
		for(j=1;j<=m;j++) ans=max(ans,up[i][j]*(r[j]-l[j]+1));
	}
	printf("%d\n",ans*3);
}
