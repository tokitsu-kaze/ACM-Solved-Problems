#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
vector<int> g[MAX];
int n,m;
string mp[MAX];
vector<int> a[MAX];
char s[MAX];
int in[MAX],flag[MAX];
void dfs(int x)
{
	if(flag[x]) return;
	flag[x]=1;
	for(auto &to:g[x]) dfs(to);
}
int get_id(int x,int y)
{
	return x*m+y+1;
}
int main()
{
	int t,i,j,x,y,ok;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			mp[i]=string(s);
		}
		for(i=0;i<n;i++)
		{
			vector<int> tmp(m);
			for(auto &it:tmp) scanf("%d",&it);
			a[i]=tmp;
		}
		for(i=1;i<=n*m;i++)
		{
			flag[i]=in[i]=0;
			g[i].clear();
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='u')
				{
					x=i-a[i][j];
					y=j;
				}
				else if(mp[i][j]=='d')
				{
					x=i+a[i][j];
					y=j;
				}
				else if(mp[i][j]=='l')
				{
					x=i;
					y=j-a[i][j];
				}
				else if(mp[i][j]=='r')
				{
					x=i;
					y=j+a[i][j];
				}
				if(x<0||x>=n||y<0||y>=m) continue;
				g[get_id(i,j)].push_back(get_id(x,y));
				in[get_id(x,y)]++;
			}
		}
		vector<int> res;
		for(i=1;i<=n*m;i++)
		{
			if(!in[i]) res.push_back(i);
		}
		if(res.size()>1)
		{
			puts("No");
			continue;
		}
		if(res.size()==0) x=1;
		else x=res[0];
		dfs(x);
		ok=1;
		for(i=1;i<=n*m;i++) ok&=flag[i];
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
