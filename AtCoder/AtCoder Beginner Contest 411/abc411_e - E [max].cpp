#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
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
ll inv(ll x){return qpow(x,mod-2);}
struct node{int v,cnt,id;};
int len[MAX];
int main()
{
	int n,i,j,a[7],cnt;
	ll fz,fm,now;
	scanf("%d",&n);
	vector<node> res;
	for(i=1;i<=n;i++)
	{
		len[i]=6;
		for(j=1;j<=6;j++) scanf("%d",&a[j]);
		sort(a+1,a+1+6);
		cnt=1;
		for(j=2;j<=6;j++)
		{
			if(a[j]==a[j-1]) cnt++;
			else
			{
				res.push_back({a[j-1],cnt,i});
				cnt=1;
			}
		}
		res.push_back({a[6],cnt,i});
	}
	sort(res.begin(),res.end(),[](node x,node y){
		return x.v>y.v;
	});
	fm=qpow(6,n);
	fz=0;
	now=fm;
	for(auto &it:res)
	{
		now=now*inv(len[it.id])%mod;
		fz=(fz+now*it.cnt%mod*it.v)%mod;
		len[it.id]-=it.cnt;
		now=now*len[it.id];
	}
	printf("%lld\n",fz*inv(fm)%mod);
	return 0;
}
