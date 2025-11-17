#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mp[22][22];
int main()
{
	int n,m,i,j,k,nx,ny,ok,cnt;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	ok=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='.') continue;
			cnt=0;
			for(k=0;k<4;k++)
			{
				nx=i+dir[k][0];
				ny=j+dir[k][1];
				if(nx<1||nx>n||ny<1||ny>m) continue;
				if(mp[nx][ny]=='#') cnt++;
			}
			if(cnt!=2 && cnt!=4) ok=0;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
