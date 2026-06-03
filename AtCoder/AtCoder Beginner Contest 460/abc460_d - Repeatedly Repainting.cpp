#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct node{int x,y;};
int dir[8][2]={0,1,1,0,0,-1,-1,0,-1,-1,-1,1,1,-1,1,1};
string mp[MAX],nmp[MAX];
char s[MAX];
int main()
{
	int n,m,i,j,k,cnt,sz,f,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		mp[i]=string(s);
		nmp[i].resize(m);
	}
	cnt=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#') cnt++;
		}
	}
	if(cnt==n*m || cnt==0)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++) mp[i][j]='.';
			puts(mp[i].c_str());
		}
		return 0;
	}
	for(cnt=0;cnt<2;cnt++)
	{
		for(i=0;i<n;i++) nmp[i]=string(m,'.');
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='.') continue;
				for(k=0;k<8;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(x<0||y<0||x>=n||y>=m) continue;
					if(mp[x][y]=='.') nmp[x][y]='#';
				}
			}
		}
		for(i=0;i<n;i++) mp[i]=nmp[i];
	}
	vector<node> res;
	queue<node> q;
	map<pair<int,int>,int> vis;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#')
			{
				q.push({i,j});
				vis[{i,j}]=1;
			}
		}
	}
	f=0;
	while(!q.empty())
	{
		sz=q.size();
		f++;
		while(sz--)
		{
			node t=q.front();
			q.pop();
			if(f&1) res.push_back(t);
			for(i=0;i<8;i++)
			{
				node nex=t;
				nex.x+=dir[i][0];
				nex.y+=dir[i][1];
				if(nex.x<0 || nex.y<0 || nex.x>=n || nex.y>=m) continue;
				if(vis.count({nex.x,nex.y})) continue;
				vis[{nex.x,nex.y}]=1;
				q.push(nex);
			}
		}
	}
	for(auto &it:res) mp[it.x][it.y]='#';
	for(i=0;i<n;i++) puts(mp[i].c_str());
	return 0;
}
/*
1 3
##.
*/

