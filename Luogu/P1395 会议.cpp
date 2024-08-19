#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e4+10;
struct Tree_Centroid
{
	vector<int> *mp;
	int sz[MAX],mx[MAX],n;
	void dfs(int x,int fa)
	{
		sz[x]=1;
		mx[x]=0;
		for(auto &to:mp[x])
		{
			if(to==fa) continue;
			dfs(to,x);
			sz[x]+=sz[to];
			mx[x]=max(mx[x],sz[to]);
		}
		mx[x]=max(mx[x],n-sz[x]);
	}
	vector<int> get_tree_centroid(int _n,vector<int> *_mp,int root)
	{
		int i,mn;
		n=_n;
		mp=_mp;
		dfs(root,-1);
		vector<int> res;
		mn=n+1;
		for(i=1;i<=n;i++) mn=min(mn,mx[i]);
		for(i=1;i<=n;i++)
		{
			if(mx[i]==mn) res.push_back(i);
		}
		return res;
	}
}trct;
vector<int> mp[MAX];
int dis[MAX];
void dfs(int x,int fa)
{
	dis[x]=dis[fa]+1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int n,i,a,b,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	vector<int> res=trct.get_tree_centroid(n,mp,1);
	sort(res.begin(),res.end());
	dis[0]=-1;
	dfs(res[0],0);
	ans=0;
	for(i=1;i<=n;i++) ans+=dis[i];
	printf("%d %d\n",res[0],ans);
	return 0;
}
