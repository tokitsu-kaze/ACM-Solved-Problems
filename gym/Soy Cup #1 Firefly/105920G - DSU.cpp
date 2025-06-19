#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
int f[MAX];
vector<int> mp[MAX];
int in[MAX];
int main()
{
	int T,n,i,ok,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ok=1;
		dsu.init(n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			f[i]++;
			if(f[i]!=i)
			{
				if(!dsu.merge(i,f[i])) ok=0;
			}
			mp[i].clear();
			in[i]=0;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			if(f[i]==i) continue;
			mp[f[i]].push_back(i);
			in[i]++;
		}
		vector<pair<int,int>> res;
		queue<int> q;
		for(i=1;i<=n;i++)
		{
			if(in[i]) continue;
			while(!q.empty()) q.pop();
			q.push(i);
			while(!q.empty())
			{
				x=q.front();
				q.pop();
				for(auto &to:mp[x])
				{
					res.push_back({to,x});
					q.push(to);
				}
			}
		}
		reverse(res.begin(),res.end());
		printf("%d\n",(int)res.size());
		for(auto &it:res) printf("%d %d\n",it.first-1,it.second-1);
	}
	return 0;
}
