#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=1e9+7;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
	int T,n,m,k,i,j,a,b,c,f,cnt,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		map<pair<int,int>,int> mp;
		cnt=0;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[{a,b}]=c;
			for(j=0;j<4;j++)
			{
				x=a+dir[j][0];
				y=b+dir[j][1];
				if(x<1||x>n||y<1||y>m) continue;
				if(mp.count({x,y})) cnt+=(mp[{x,y}]!=c);
			}
		}
		for(auto &it:mp)
		{
			if(it.second==1) continue;
			a=it.first.first;
			b=it.first.second;
			for(j=0;j<4;j++)
			{
				x=a+dir[j][0];
				y=b+dir[j][1];
				if(x<1||x>n||y<1||y>m) continue;
				if(!mp.count({x,y})) cnt++;
			}
		}
		f=0;
		for(i=2;i<=n-1;i++)
		{
			if(!mp.count({i,1}) || !mp.count({i,m}))
			{
				f=1;
				break;
			}
		}
		for(i=2;i<=m-1;i++)
		{
			if(!mp.count({1,i}) || !mp.count({n,i}))
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			if(cnt&1) puts("0");
			else printf("%lld\n",qpow(2,1LL*n*m-k));
		}
		else printf("%lld\n",qpow(2,1LL*n*m-k-1));
	}
	return 0;
}

