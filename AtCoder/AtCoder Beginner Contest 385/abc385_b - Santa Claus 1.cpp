#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char mp[105][105],t[MAX];
int main()
{
	int n,m,x,y,i,j,len,dx,dy,nx,ny,ans;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	scanf("%s",t+1);
	len=strlen(t+1);
	ans=0;
	for(i=1;i<=len;i++)
	{
		dx=dy=0;
		if(t[i]=='U') dx=-1;
		else if(t[i]=='D') dx=1;
		else if(t[i]=='L') dy=-1;
		else dy=1;
		nx=x+dx;
		ny=y+dy;
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(mp[nx][ny]=='#') continue;
		if(mp[nx][ny]=='@')
		{
			ans++;
			mp[nx][ny]='.';
		}
		x=nx;
		y=ny;
	}
	printf("%d %d %d\n",x,y,ans);
	return 0;
}
