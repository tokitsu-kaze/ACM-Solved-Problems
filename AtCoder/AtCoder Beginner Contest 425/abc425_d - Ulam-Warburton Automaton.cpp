#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int x,y;};
char s[MAX];
string mp[MAX];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m;
int ck(node t)
{
	if(mp[t.x][t.y]=='#') return 0;
	int i,cnt;
	cnt=0;
	for(i=0;i<4;i++)
	{
		node nex=t;
		nex.x+=dir[i][0];
		nex.y+=dir[i][1];
		if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
		if(mp[nex.x][nex.y]=='#') cnt++;
	}
	return cnt==1;
}
int main()
{
	int i,j,sz,ans;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		mp[i]=string(s);
	}
	vector<node> now,tmp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#') now.push_back({i,j});
		}
	}
	while(now.size()>0)
	{
		for(auto &it:now) mp[it.x][it.y]='#';
		tmp.clear();
		for(auto &it:now)
		{
			for(i=0;i<4;i++)
			{
				node nex=it;
				nex.x+=dir[i][0];
				nex.y+=dir[i][1];
				if(nex.x<0||nex.x>=n||nex.y<0||nex.y>=m) continue;
				if(ck(nex)) tmp.push_back(nex);
			}
		}
		swap(now,tmp);
	}
	ans=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#') ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
