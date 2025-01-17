#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dep[MAX],mxdep[MAX],ans[MAX];
set<pair<int,int>> s[MAX];
void dfs0(int x,int pre,int h)
{
	dep[x]=mxdep[x]=h;
	s[x].insert({0,0});
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs0(to,x,h+1);
		mxdep[x]=max(mxdep[x],mxdep[to]);
		s[x].insert({mxdep[to],to});
	}
}
const int LOG=log2(MAX);
int fa[MAX][LOG+1],mx[MAX][LOG+1];
void dfs(int x,int pre)
{
	fa[x][0]=pre;
	s[pre].erase({mxdep[x],x});
	mx[x][0]=(*s[pre].rbegin()).first-dep[fa[x][0]]+1;
	s[pre].insert({mxdep[x],x});
	for(int i=1;i<=LOG;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
		mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]+(1<<(i-1)));
	}
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
}
int jump(int x,int k)
{
	for(int i=LOG;~i;i--)
	{
		if((k>>i)&1) x=fa[x][i];
	}
	return x;
}
int calmx(int x,int k)
{
	int res=-INF;
	int now=0;
	for(int i=LOG;~i;i--)
	{
		if((k>>i)&1)
		{
			res=max(res,mx[x][i]+now);
			x=fa[x][i];
			now+=(1<<i);
		}
	}
	return res;
}
int main()
{
	int T,n,q,i,a,b,x,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)
		{
			mp[i].clear();
			s[i].clear();
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs0(1,0,0);
		s[0].insert({0,0});
		dfs(1,0);
		scanf("%d",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&k);
			k=min(k,dep[x]);
			ans[i]=max(k,mxdep[x]-dep[x]);
			ans[i]=max(ans[i],calmx(x,k));
		}
		for(i=1;i<=q;i++) printf("%d%c",ans[i]," \n"[i==q]);
	}
	return 0;
}
