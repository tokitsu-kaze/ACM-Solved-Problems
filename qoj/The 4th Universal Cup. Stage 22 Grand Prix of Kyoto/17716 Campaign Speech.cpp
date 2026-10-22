#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
ll sum;
set<pair<int,int>> mpx[MAX],mpy[MAX];
int vis[MAX];
vector<ll> pos;
void work(set<pair<int,int>> &mp,int a,int b)
{
	int l,r,id;
	l=a;
	r=b;
	if(l>r) swap(l,r);
	while(1)
	{
		auto it=mp.lower_bound({l,0});
		if(it==mp.end() || (*it).first>r) break;
		id=(*it).second;
		if(!vis[id])
		{
			pos.push_back(sum+abs((*it).first-a));
			vis[id]=1;
		}
		mp.erase(it);
	}
}
const int delta=1e5;
int x[MAX],y[MAX];
int main()
{
	int n,m,i,a,b;
	ll mx;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		x[i]+=delta;
		y[i]+=delta;
	}
	for(i=0;i<MAX;i++)
	{
		mpx[i].clear();
		mpy[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		a+=delta;
		b+=delta;
		mpx[a].insert({b,i});
		mpy[b].insert({a,i});
		vis[i]=0;
	}
	sum=0;
	pos.clear();
	x[n+1]=x[1];
	y[n+1]=y[1];
	for(i=1;i<=n;i++)
	{
		if(x[i]==x[i+1]) work(mpx[x[i]],y[i],y[i+1]);
		else if(y[i]==y[i+1]) work(mpy[y[i]],x[i],x[i+1]);
		sum+=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
	}
	sort(pos.begin(),pos.end());
	mx=pos[0]+sum-pos.back();
	for(i=0;i+1<pos.size();i++) mx=max(mx,pos[i+1]-pos[i]);
	printf("%lld\n",sum-mx);
	return 0;
}
