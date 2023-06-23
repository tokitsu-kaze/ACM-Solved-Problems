#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Bipartite_Matching
{
	static const int N=200+10;
	static const int M=200+10;
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
O(n*m)
bpm.init(n,m);
bpm.add_edge(a,b); a:left,1-n   b:right,1-m
*/
int a[55],b[55];
int main()
{
	int t,n,i,j,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		bpm.init(n,n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				if(x) bpm.add_edge(i,j);
			}
		}
		if(bpm.max_match()==n) puts("Yes");
		else puts("No");
	}
	return 0;
}
