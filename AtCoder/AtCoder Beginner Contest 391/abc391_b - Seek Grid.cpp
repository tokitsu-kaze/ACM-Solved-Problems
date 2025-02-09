#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAX=5000+10;
char s[55][55],t[55][55];
int ck(int x,int y,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[x+i-1][y+j-1]!=t[i][j]) return 0;
		}
	}
	return 1;
}
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(i=1;i<=m;i++) scanf("%s",t[i]+1);
	for(i=1;i+m-1<=n;i++)
	{
		for(j=1;j+m-1<=n;j++)
		{
			if(ck(i,j,m))
			{
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	return 0;
}

