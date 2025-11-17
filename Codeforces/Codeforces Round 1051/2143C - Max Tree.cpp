#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	queue<int> q;
	for(int it=1;it<=n;it++)
	{
		if(!in[it]) q.push(it);
	}
	vector<int> toplist;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(to);
		}
	}
	return toplist;
}
int a[MAX],b[MAX],x[MAX],y[MAX],p[MAX],in[MAX];
vector<int> mp[MAX];
int main()
{
	int T,n,i,tot;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			in[i]=0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d%d%d",&a[i],&b[i],&x[i],&y[i]);
			if(x[i]<y[i])
			{
				mp[a[i]].push_back(b[i]);
				in[b[i]]++;
			}
			else
			{
				mp[b[i]].push_back(a[i]);
				in[a[i]]++;
			}
		}
		auto res=topsort(n,mp,in);
		tot=0;
		for(auto &it:res) p[it]=++tot;
		ans=0;
		for(i=1;i<n;i++)
		{
			if(p[a[i]]>p[b[i]]) ans+=x[i];
			else ans+=y[i];
		}
//		printf("%lld\n",ans);
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
