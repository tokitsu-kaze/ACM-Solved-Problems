#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
char mp[MAX][MAX];
int main()
{
	int T,n,k,i,j,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k+1==n*n)
		{
			puts("NO");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) mp[i][j]='.';
		}
		now=n*n-k;
		for(i=1;i<=n;i++)
		{
			if(now>=2)
			{
				now-=2;
				mp[i][1]='R';
				mp[i][2]='L';
			}
			else if(now==1)
			{
				now-=1;
				mp[i][1]='U';
			}
		}
		puts("YES");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]!='.') continue;
				if(now>0)
				{
					now--;
					mp[i][j]='L';
				}
				else
				{
					mp[i][j]='D';
				}
			}
			mp[i][n+1]='\0';
			puts(mp[i]+1);
		}
	}
	return 0;
}
