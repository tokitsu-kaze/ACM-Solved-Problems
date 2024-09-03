#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> mp[MAX];
bool tag[MAX];
int a[MAX],sz[MAX],dep[MAX],mxh;
ll sum[MAX];
void dfs1(int x,int h)
{
	sz[x]=1;
	sum[x]=a[x];
	dep[x]=0;
	mxh=max(mxh,h);
	for(auto &to:mp[x])
	{
		dfs1(to,h+1);
		sz[x]+=sz[to];
		sum[x]+=sum[to];
		dep[x]=max(dep[x],dep[to]+1);
	}
}
void dfs2(int x,int h)
{
	if(h+dep[x]==mxh) tag[x]=1;
	for(auto &to:mp[x]) dfs2(to,h+1);
}
ll f[MAX],g[MAX];
void dfs(int x)
{
	ll t,s,res,pret,sufsum,tmp;
	sort(mp[x].begin(),mp[x].end(),[](int x,int y){
		return 2LL*sz[x]*sum[y]<2LL*sz[y]*sum[x];
	});
	f[x]=res=s=0;
	t=1;
	for(auto &to:mp[x])
	{
		res+=t*sum[to];
		t+=2*sz[to];
		s+=sum[to];
		dfs(to);
		f[x]+=f[to];
	}
	g[x]=LLINF;
	pret=1;
	sufsum=s;
	for(auto &to:mp[x])
	{
		sufsum-=sum[to];
		if(tag[to])
		{
			tmp=res-2LL*sz[to]*sufsum-pret*sum[to];
			g[x]=min(g[x],f[x]-f[to]+tmp+(t-2*sz[to])*sum[to]+g[to]);
		}
		pret+=2*sz[to];
	}
	f[x]+=res;
	if(mp[x].size()==0) g[x]=0;
//	cout<<"debug: x,f,g: "<<x<<" "<<f[x]<<" "<<g[x]<<endl;
}
int main()
{
	int n,t,i,fa;
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=2;i<=n;i++)
	{
		scanf("%d%d",&fa,&a[i]);
		mp[fa].push_back(i);
	}
	a[1]=0;
	mxh=0;
	dfs1(1,0);
	dfs2(1,0);
	dfs(1);
	if(t==0) printf("%d %lld\n",2*(n-1),f[1]);
	else printf("%d %lld\n",2*(n-1)-mxh,g[1]);
	return 0;
}
