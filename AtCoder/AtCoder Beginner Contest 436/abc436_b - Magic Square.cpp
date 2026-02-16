#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int mp[110][110];
int main()
{
	int n,x,y,k,i,j;
	scanf("%d",&n);
	x=0;
	y=(n-1)/2;
	memset(mp,0,sizeof mp);
	k=1;
	mp[x][y]=k++;
	for(i=1;i<=n*n-1;i++)
	{
		if(mp[(x-1+n)%n][(y+1)%n]==0)
		{
			x=(x-1+n)%n;
			y=(y+1)%n;
			mp[x][y]=k++;
		}
		else
		{
			x=(x+1)%n;
			mp[x][y]=k++;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d%c",mp[i][j]," \n"[j+1==n]);
		}
	}
	return 0;
}
