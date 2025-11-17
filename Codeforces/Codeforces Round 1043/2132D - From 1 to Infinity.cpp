#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
const int DIG=20+2;
ll dp[11][DIG][DIG];
ll gao(ll x,int d)
{
	const int base=10;
	int p[DIG],tot=0;
	if(x==-1) return 0;
	while(1)
	{
		p[tot++]=x%base;
		x/=base;
		if(!x) break;
	}
	function<ll(int,int,int,int)> dfs=[&](int pos,int lead,int sta,int limt)->ll
	{
		if(pos==-1) return sta;
		if(!limt&&!lead&&dp[d][pos][sta]!=-1) return dp[d][pos][sta];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			res+=dfs(pos-1,lead&&i==0&&pos,sta+(i==d),limt&&i==p[pos]); 
		}
		if(!limt&&!lead) dp[d][pos][sta]=res;
		return res;
	};
	return dfs(tot-1,1,0,1);
}

int ck(ll x,ll k)
{
	ll sd,now;
	sd=1;
	now=1;
	while(sd<=x)
	{
		k-=(min(sd*10-1,x)-sd+1)*now;
		if(k<0) return 0;
		sd*=10;
		now++;
	}
	return 1;
}
ll cal(ll x)
{
	ll sd,now,res;
	sd=1;
	now=1;
	res=0;
	while(sd<=x)
	{
		res+=(min(sd*10-1,x)-sd+1)*now;
		sd*=10;
		now++;
	}
	return res;
}
int main()
{
	int T,i;
	ll k,l,r,mid,ans;
	memset(dp,-1,sizeof dp);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&k);
		l=1;
		r=1e15;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1,k)) l=mid+1;
			else r=mid;
		}
//		cout<<l<<" "<<cal(l)<<endl;
		k-=cal(l);
		assert(k>=0);
		ans=0;
		for(i=1;i<=9;i++) ans+=i*gao(l,i);
		string tmp=to_string(l+1);
		for(i=0;i<k;i++) ans+=tmp[i]-'0';
		printf("%lld\n",ans);
	}
	return 0;
}

