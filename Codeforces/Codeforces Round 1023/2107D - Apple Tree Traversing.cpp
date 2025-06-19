#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int vis[MAX];
struct Tree_Diameter
{
	vector<int> *mp;
	int fa[MAX],rt,mx,node;
	void dfs(int x,int pre,int h)
	{
		fa[x]=pre;
		for(auto &to:mp[x])
		{
			if(to==pre) continue;
			if(vis[to]) continue;
			dfs(to,x,h+1);
		}
		if(h>mx)
		{
			mx=h;
			node=x;
		}
		else if(h==mx) node=max(node,x);
	}
	vector<int> get_tree_diameter(int rt,vector<int> *_mp)
	{
		mp=_mp;
		fa[0]=0;
		mx=node=0;
		dfs(rt,0,0);
		rt=node;
		mx=node=0;
		dfs(rt,0,0);
		rt=node;
		vector<int> res;
		while(rt)
		{
			res.push_back(rt);
			rt=fa[rt];
		}
		return res;
	}
}td;
struct node{int d,a,b;};
vector<node> res;
vector<int> mp[MAX];
void dfs(int x)
{
	vector<int> tmp=td.get_tree_diameter(x,mp);
	if(tmp[0]<tmp.back()) res.push_back({(int)tmp.size(),tmp.back(),tmp[0]});
	else res.push_back({(int)tmp.size(),tmp[0],tmp.back()});
	for(auto &it:tmp) vis[it]=1;
	vector<int> now;
	for(auto &it:tmp)
	{
		for(auto &to:mp[it])
		{
			if(!vis[to]) now.push_back(to);
		}
		mp[it].clear();
	}
	for(auto &it:now) dfs(it);
}
int main()
{
	int T,n,i,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			vis[i]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		res.clear();
		dfs(1);
		sort(res.begin(),res.end(),[](node x,node y){
			if(x.d==y.d) return x.a>y.a;
			return x.d>y.d;
		});
		vector<int> ans;
		for(auto &it:res)
		{
			ans.push_back(it.d);
			ans.push_back(it.a);
			ans.push_back(it.b);
		}
		for(i=0;i<ans.size();i++) printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
	}
	return 0;
}
