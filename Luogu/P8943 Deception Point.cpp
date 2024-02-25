#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
int dis[MAX];
int flag[MAX],in_cir[MAX];
vector<int> cir;
int st[MAX],top;
void dfs(int x,int fa)
{
	flag[x]=2;
	st[top++]=x;
	for(auto &to:mp[x])
	{
		if(cir.size()) return;
		if(to==fa) continue;
		if(flag[to]==2)
		{
			while(top>0)
			{
				cir.push_back(st[--top]);
				if(cir.back()==to) break;
			}
			return;
		}
		else dfs(to,x);
	}
	top--;
	flag[x]=1;
}
int belong[MAX],dep[MAX];
void dfs2(int x,int fa)
{
	belong[x]=belong[fa];
	dep[x]=dep[fa]+1;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs2(to,x);
	}
}
int main()
{
	int n,q,x,y,i,a,b,ok,tmp,d;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		dis[i]=0x3f;
		flag[i]=in_cir[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	cir.clear();
	top=0;
	dfs(1,0);
	for(auto &it:cir) in_cir[it]=1;
	tmp=0;
	for(auto &it:cir)
	{
		dis[it]=++tmp;
		belong[it]=it;
		dep[it]=0;
		for(auto &to:mp[it])
		{
			if(in_cir[to]) continue;
			dfs2(to,it);
		}
	}
	while(q--)
	{
		scanf("%d%d",&x,&y);
		ok=0;
		if(in_cir[x]) ok=1;
		d=abs(dis[belong[x]]-dis[belong[y]]);
		d=min(d,(int)cir.size()-d);
		if(dep[x]<dep[y]+d) ok=1;
		if(ok) puts("Survive");
		else puts("Deception");
	}
	return 0;
}

