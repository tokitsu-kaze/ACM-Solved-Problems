#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
int ra,rb;
void dfs(int x,int fa)
{
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
	if(mp[x].size()==1)
	{
		ra=mp[x][0];
		rb=x;
	}
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		auto res=trct.get_tree_centroid(n,mp,1);
		if(res.size()==1)
		{
			printf("%d %d\n",a,b);
			printf("%d %d\n",a,b);
			continue;
		}
		dfs(res[0],res[1]);
		printf("%d %d\n",ra,rb);
		printf("%d %d\n",rb,res[1]);
	}
	return 0;
}
