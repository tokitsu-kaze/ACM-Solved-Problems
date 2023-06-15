#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct node{int x,w;};
struct Tree_Diameter
{
	int fa[MAX],rt,mx;
	void dfs(int x,int pre,int h,vector<node> *mp)
	{
		fa[x]=pre;
		for(auto &to:mp[x])
		{
			if(to.x==pre) continue;
			dfs(to.x,x,h+to.w,mp);
		}
		if(h>mx)
		{
			mx=h;
			rt=x;
		}
	}
	vector<int> get_tree_diameter(vector<node> *mp)
	{
		fa[0]=0;
		rt=1;
		mx=0;
		dfs(rt,0,0,mp);
		mx=0;
		dfs(rt,0,0,mp);
		vector<int> res;
		while(rt)
		{
			res.push_back(rt);
			rt=fa[rt];
		}
		return res;
	}
}td;
vector<node> mp[MAX];
int flag[MAX],mxdis[MAX],mx;
void dfs(int x,int fa,int h)
{
	mx=max(mx,h);
	for(auto &to:mp[x])
	{
		if(to.x==fa) continue;
		if(flag[to.x]) continue;
		dfs(to.x,x,h+to.w);
	}
}
int bit[MAX];
map<pair<int,int>,int> e;
int main()
{
	int n,s,i,j,a,b,c,ans,now;
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		flag[i]=0;
	}
	e.clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
		e[{a,b}]=e[{b,a}]=c;
	}
	vector<int> res=td.get_tree_diameter(mp);
	for(auto &it:res) flag[it]=1;
	for(auto &it:res)
	{
		mx=0;
		dfs(it,0,0);
		mxdis[it]=mx;
	}
	bit[0]=0;
	for(i=1;i<res.size();i++) bit[i]=bit[i-1]+e[{res[i-1],res[i]}];
	ans=INF;
	now=0;
	multiset<int> ss;
	for(i=0,j=0;i<res.size();i++)
	{
		while((j-1<i)||(j<res.size()&&bit[j]-bit[i]<=s))
		{
			ss.insert(mxdis[res[j]]);
			j++;
		}
		if(now<=s) ans=min(ans,max({*ss.rbegin(),bit[i],bit[res.size()-1]-bit[j-1]}));
		ss.erase(ss.find(mxdis[res[i]]));
	}
	printf("%d\n",ans);
	return 0;
}
