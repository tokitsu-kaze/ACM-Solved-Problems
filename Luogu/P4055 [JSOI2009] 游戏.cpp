#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+10;
struct Bipartite_Matching
{
	static const int N=MAX;
	static const int M=MAX;
	int n,m;
	vector<int> mp[N];
	int flag[N],s[N],link[M],used[M];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].push_back(b);}
	bool dfs(int x,int timetag)
	{
		int i,to;
		flag[x]=1;
		for(i=0;i<mp[x].size();i++)
		{
			to=mp[x][i];
			if(used[to]==timetag) continue;
			used[to]=timetag;
			if(link[to]==-1||dfs(link[to],timetag))
			{
				link[to]=x;
				s[x]=to;
				return 1;
			}
		}
		return 0;
	}
	int max_match()
	{
		int i,res;
		memset(link,-1,sizeof link);
		memset(s,-1,sizeof s);
		memset(used,0,sizeof used);
		res=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i].size()==0) continue;
			if(dfs(i,i)) res++;
		}
		return res;
	}
}bpm;
/*
O(n*m) : n node,m edge
bpm.init(n,m);
bpm.add_edge(a,b); a:left,1-n   b:right,1-m
*/
int dir[4][2]={0,1,1,0,0,-1,-1,0};
char mp[105][105];
int id[105][105],tot;
pair<int,int> pos[MAX];
int flag[MAX],vis[MAX],ok;
vector<pair<int,int>> res;
void dfs(int x)
{
	if(vis[x]) return;
	vis[x]=1;
	res.push_back(pos[x]);
	for(auto &to:bpm.mp[x])
	{
		if(bpm.link[to]==-1) continue;
		dfs(bpm.link[to]);
	}
}
int main()
{
	int n,m,i,j,k,x,y;
	scanf("%d%d",&n,&m);
	tot=0;
	for(i=0;i<n;i++)
	{
		scanf("%s",mp[i]);
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#') continue;
			id[i][j]=++tot;
			pos[tot]={i+1,j+1};
		}
	}
	bpm.init(tot,tot);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mp[i][j]=='#') continue;
			for(k=0;k<4;k++)
			{
				x=i+dir[k][0];
				y=j+dir[k][1];
				if(x<0||y<0||x>=n||y>=m) continue;
				if(mp[x][y]=='#') continue;
				bpm.add_edge(id[i][j],id[x][y]);
				bpm.add_edge(id[x][y],id[i][j]);
			}
		}
	}
	if(bpm.max_match()==tot)
	{
		puts("LOSE");
		return 0;
	}
	res.clear();
	for(i=1;i<=tot;i++) flag[i]=vis[i]=0;
	for(i=1;i<=tot;i++)
	{
		if(bpm.s[i]!=-1) flag[i]=1;
	}
	for(i=1;i<=tot;i++)
	{
		if(bpm.s[i]!=-1||vis[i]) continue;
		dfs(i);
	}
	sort(res.begin(),res.end());
	puts("WIN");
	for(auto &it:res) printf("%d %d\n",it.first,it.second);
	return 0;
}
