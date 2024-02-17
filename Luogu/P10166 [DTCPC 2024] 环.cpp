#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
ll a[MAX],mn[MAX];
vector<int> topsort(int n,vector<int> mp[],int *in)
{
	queue<int> q;
	for(int it=1;it<=n;it++)
	{
		mn[it]=LLINF;
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
			mn[to]=min({mn[to],mn[x],a[x]});
		}
	}
	return toplist;
}
vector<int> mp[MAX];
int in[MAX];
int main()
{
	int n,m,i,x,y;
	ll ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=0;
		scanf("%lld",&a[i]);
	}
	while(m--)
	{
		scanf("%d%d",&x,&y);
		mp[x].push_back(y);
		in[y]++;
	}
	ans=LLINF;
	if(topsort(n,mp,in).size()!=n) ans=0;
	for(i=1;i<=n;i++) ans=min(ans,a[i]+mn[i]);
	sort(a+1,a+1+n);
	ans=min(ans,2*(a[1]+a[2]));
	printf("%lld\n",ans);
	return 0;
}
