#include <bits/stdc++.h>
using namespace std;
char mp[55][55];
int now[55][55],nex[55][55];
int main()
{
	int n,m,q,i,j,f;
	char op[11];
	scanf("%d%d",&n,&m);
	memset(now,0,sizeof now);
	for(i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='*')
			{
				now[i][j]=1;
				mp[i][j]='.';
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",op);
		memset(nex,0,sizeof nex);
		if(op[0]=='N')
		{
			for(j=0;j<m;j++)
			{
				f=0;
				for(i=n-1;i>=0;i--)
				{
					if(mp[i][j]=='X') f=0;
					nex[i][j]=f;
					if(now[i][j]) f=1;
				}
			}
		}
		else if(op[0]=='S')
		{
			for(j=0;j<m;j++)
			{
				f=0;
				for(i=0;i<n;i++)
				{
					if(mp[i][j]=='X') f=0;
					nex[i][j]=f;
					if(now[i][j]) f=1;
				}
			}
		}
		else if(op[0]=='W')
		{
			for(i=0;i<n;i++)
			{
				f=0;
				for(j=m-1;j>=0;j--)
				{
					if(mp[i][j]=='X') f=0;
					nex[i][j]=f;
					if(now[i][j]) f=1;
				}
			}
		}
		else if(op[0]=='E')
		{
			for(i=0;i<n;i++)
			{
				f=0;
				for(j=0;j<m;j++)
				{
					if(mp[i][j]=='X') f=0;
					nex[i][j]=f;
					if(now[i][j]) f=1;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				now[i][j]=nex[i][j];
				nex[i][j]=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(now[i][j]) mp[i][j]='*';
		}
		mp[i][m]='\0';
		puts(mp[i]);
	}
	return 0;
}
