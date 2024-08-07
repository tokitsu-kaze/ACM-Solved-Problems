#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
struct Bipartite_Matching
{
	static const int N=2505;
	static const int M=2505;
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
char mp[55][55];
int idx[55][55],idy[55][55],totx,toty;
int main()
{
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%s",mp[i]+1);
	totx=0;
	for(i=1;i<=n;i++)
	{
		idx[i][0]=0;
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='*')
			{
				if(idx[i][j-1]) idx[i][j]=idx[i][j-1];
				else idx[i][j]=++totx;
			}
		}
	}
	toty=0;
	for(j=1;j<=m;j++)
	{
		idy[0][j]=0;
		for(i=1;i<=n;i++)
		{
			if(mp[i][j]=='*')
			{
				if(idy[i-1][j]) idy[i][j]=idy[i-1][j];
				else idy[i][j]=++toty;
			}
		}
	}
	bpm.init(totx,toty);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(mp[i][j]=='*') bpm.add_edge(idx[i][j],idy[i][j]);
		}
	}
	printf("%d\n",bpm.max_match());
	return 0;
}
