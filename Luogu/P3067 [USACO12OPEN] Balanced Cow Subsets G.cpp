#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<20)+10;
int vis[MAX];
map<int,vector<int> > mp;
vector<int> a,b;
void dfs(int p,vector<int> &res,int now,int s,int f)
{
	if(p==res.size())
	{
		if(f)
		{
			if(!mp.count(now)) return;
			for(auto &it:mp[now]) vis[it|(s<<a.size())]=1;
		}
		else mp[now].push_back(s);
		return;
	}
	dfs(p+1,res,now+res[p],s|(1<<p),f);
	dfs(p+1,res,now-res[p],s|(1<<p),f);
	dfs(p+1,res,now,s,f);
}
int main()
{
	int n,i,x,ans;
	scanf("%d",&n);
	a.clear();
	b.clear();
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(i&1) a.push_back(x);
		else b.push_back(x);
	}
	mp.clear();
	memset(vis,0,sizeof vis);
	dfs(0,a,0,0,0);
	dfs(0,b,0,0,1);
	ans=0;
	for(i=1;i<(1<<n);i++) ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}
