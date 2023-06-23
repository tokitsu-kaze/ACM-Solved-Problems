#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Bipartite_Matching
{
	static const int N=1e4+10;
	static const int M=1e6+10;
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
			if(mp[i].size()==0) return res;
			if(dfs(i,i)) res++;
			else return res;
		}
		return res;
	}
}bpm;
/*
O(n*m)
bpm.init(n,m);
bpm.add_edge(a,b); a:left,1-n   b:right,1-m
*/
int main()
{
	int n,m,e,i,a,b;
	scanf("%d",&n);
	bpm.init(10000,n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		bpm.add_edge(a,i);
		bpm.add_edge(b,i);
	}
	printf("%d\n",bpm.max_match());
	return 0;
}
