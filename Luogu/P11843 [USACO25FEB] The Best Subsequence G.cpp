#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
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
struct Discretization
{
	#define type ll
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return upper_bound(all(a),x)-a.begin();}
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
int x[MAX],y[MAX];
int v[MAX],len[MAX],sum1[MAX];
ll ha[MAX];
int cal1(int l,int r)
{
	int pl,pr,res;
	pl=d.get_pos(l);
	pr=d.get_pos(r);
	if(pl==pr) return v[pl]*(r-l+1);
	res=0;
	res+=v[pl]*(d.get_val(pl+1)-l);
	res+=sum1[pr-1]-sum1[pl];
	res+=v[pr]*(r-d.get_val(pr)+1);
	return res;
}
int cal0(int l,int r)
{
	return r-l+1-cal1(l,r);
}
ll calha(int l,int r)
{
	int pl,pr;
	ll res;
	pl=d.get_pos(l);
	pr=d.get_pos(r);
	if(pl==pr) return v[pl]*(qpow(2,r-l+1)-1)%mod;
	res=0;
	res+=calha(l,d.get_val(pl+1)-1)*qpow(2,r-(d.get_val(pl+1)-1))%mod;
	res+=(ha[pr-1]-ha[pl]*qpow(2,d.get_val(pr)-d.get_val(pl+1))%mod+mod)%mod
		*qpow(2,r-(d.get_val(pr)-1))%mod;
	res+=calha(d.get_val(pr),r);
	res%=mod;
	return res;
}
int main()
{
	int n,m,q,i,ql,qr,k,l,r,mid,cnt1,pre,suf;
	scanf("%d%d%d",&n,&m,&q);
	d.init();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		d.add(x[i]);
		d.add(y[i]+1);
	}
	d.add(1);
	d.add(n);
	d.work();
	memset(v,0,sizeof v);
	for(i=1;i<=m;i++)
	{
		v[d.get_pos(x[i])]^=1;
		v[d.get_pos(y[i]+1)]^=1;
	}
	sum1[0]=ha[0]=0;
	for(i=1;i<=d.size();i++)
	{
		v[i]^=v[i-1];
		if(i<d.size()) len[i]=d.get_val(i+1)-d.get_val(i);
		sum1[i]=sum1[i-1];
		ha[i]=(ha[i-1]*qpow(2,len[i]))%mod;
		if(v[i])
		{
			sum1[i]+=len[i];
			ha[i]=(ha[i]+qpow(2,len[i])-1+mod)%mod;
		}
	}
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&ql,&qr,&k);
		cnt1=cal1(ql,qr);
		if(cnt1>=k)
		{
			printf("%lld\n",(qpow(2,k)-1+mod)%mod);
			continue;
		}
		l=ql;
		r=qr;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(cal0(mid+1,qr)>=k-cnt1) l=mid+1;
			else r=mid;
		}
		suf=qr-l+1;
		pre=k-suf;
		printf("%lld\n",((qpow(2,pre)-1+mod)*qpow(2,suf)+calha(l,qr))%mod);
	}
	return 0;
}
