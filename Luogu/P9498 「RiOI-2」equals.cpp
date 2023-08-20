#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
struct node{int id,v;};
vector<int> mp[MAX];
int dep[MAX],ans[MAX];
void dfs(int x,int fa,int h)
{
	dep[x]=h;
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x,h+1);
	}
}
int main()
{
	int n,i,a,b;
	ll sum,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		ans[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	dfs(1,0,1);
	vector<node> res;
	sum=0;
	for(i=1;i<=n;i++)
	{
		res.push_back({i,dep[i]});
		sum+=dep[i];
	}
	if(sum&1)
	{
		puts("-1");
		return 0;
	}
	sort(res.begin(),res.end(),[&](node x,node y){
		return x.v>y.v;
	});
	now=0;
	sum/=2;
	for(auto &it:res)
	{
		if(now+it.v<=sum)
		{
			now+=it.v;
			ans[it.id]=1;
		}
	}
	if(now==sum)
	{
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	else puts("-1");
	return 0;
}
