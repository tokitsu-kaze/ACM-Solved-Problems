#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node{int x;ll w;};
vector<node> mp[MAX];
int pre[MAX],pre2;
bool flag[MAX],tag[MAX];
ll dp[MAX],w[MAX],w2;
ll dfs(int x)
{
	if(tag[x]) return dp[x];
	tag[x]=1;
	for(auto &to:mp[x])
	{
		dfs(to.x);
		if(flag[to.x])
		{
			dp[x]=min(dp[x],dp[to.x]+to.w-w[x]);
			flag[x]=1;
		}
	}
	return dp[x];
}
int main()
{
	int t,n,m,i,a,b,x,cir;
	ll ans,now,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			w[i]=dp[i]=LLINF;
			//w[i]赋值INF对ans会有影响
			flag[i]=tag[i]=0;
		}
		w2=LLINF;
		cir=1;
		pre2=1;
		while(m--)
		{
			scanf("%d%d%lld",&a,&b,&c);
			if(a>b)
			{
				cir=b;
				pre2=a;
				w2=c;
			}
			if(w[b]>c&&a<b)
			{
				w[b]=c;
				pre[b]=a;
			}
			if(b!=1) mp[b].push_back({a,c});
		}
		ans=0;
		for(i=2;i<=n;i++) ans+=w[i];
		if(cir==1||w2>=w[cir])
		{
			printf("%lld\n",ans);
			continue;
		}
		vector<int> circle;
		x=pre2;
		while(x!=cir)
		{
			circle.push_back(x);
			x=pre[x];
			if(x==1)
			{
				circle.clear();
				break;
			}
		}
		if(circle.size()==0)
		{
			printf("%lld\n",ans-w[cir]+w2);
			continue;
		}
		flag[1]=1;
		dp[1]=0;
		tag[1]=1;
		tag[cir]=1;
		now=ans-w[cir]+w2;
		w[cir]=w2;
		pre[cir]=pre2;
		for(auto &it:circle) ans=min(ans,now+dfs(it));
	//	for(i=1;i<=n;i++) printf("%d %lld\n",i,dp[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4
5 6
1 2 4
1 3 2
2 3 0
3 4 1
4 5 1
5 2 1
4 4
1 2 4
1 3 6
1 4 8
4 2 1000000
3 3
1 2 100
2 1 10
2 3 1000
4 4
4 2 560236399
1 3 882900071
2 4 383676531
1 4 890811941
*/
