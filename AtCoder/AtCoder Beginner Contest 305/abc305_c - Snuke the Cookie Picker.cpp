#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
char mp[MAX][MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
	int n,m,i,j,k,cnt,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='#') continue;
			cnt=0;
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(x<1||y<1||x>n||y>m) continue;
				if(mp[x][y]=='#') cnt++;
			}
			if(cnt>=2)
			{
				printf("%d %d\n",i,j);
				goto end;
			}
		}
	}
	end:;
	return 0;
}
