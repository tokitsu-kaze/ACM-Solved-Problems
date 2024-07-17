#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int mp[105][105],a[105];
int main()
{
	int n,m,i,j,k,x,ok;
	scanf("%d%d",&n,&m);
	memset(mp,0,sizeof mp);
	while(m--)
	{
		scanf("%d",&k);
		for(i=1;i<=k;i++) scanf("%d",&a[i]);
		for(i=1;i<=k;i++)
		{
			for(j=i+1;j<=k;j++)
			{
				mp[a[i]][a[j]]=1;
			}
		}
	}
	ok=1;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			ok&=mp[i][j];
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
