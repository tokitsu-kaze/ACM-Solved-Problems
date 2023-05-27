#include <bits/stdc++.h>
using namespace std;
const int MAX=500*500+10;
struct node{int x,y; };
int flag[505][505],dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,q,x[MAX],y[MAX];
char s[505][505],mp[505][505];
int ck(int mid)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			mp[i][j]=s[i][j];
			flag[i][j]=0;
		}
	}
	for(i=1;i<=mid;i++) mp[x[i]][y[i]]='1';
	queue<node> q;
	for(i=0;i<m;i++) q.push({-1,i});
	while(!q.empty())
	{
		node t=q.front();
		q.pop();
		for(i=0;i<4;i++)
		{
			node nex=t;
			nex.x+=dir[i][0];
			nex.y+=dir[i][1];
			if(nex.x==n) return 0;
			if(nex.x<0 || nex.x>=n || nex.y<0 || nex.y>=m) continue;
			if(mp[nex.x][nex.y]=='1') continue;
			if(flag[nex.x][nex.y]) continue;
			flag[nex.x][nex.y]=1;
			q.push(nex);
		}
	}
	return 1;
}
int main()
{
	int t,i,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) scanf("%s",s[i]);
		scanf("%d",&q);
		for(i=1;i<=q;i++) scanf("%d%d",&x[i],&y[i]);
		l=0;
		r=q;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		if(ck(l)) printf("%d\n",l);
		else puts("-1");
	}
	return 0;
}

