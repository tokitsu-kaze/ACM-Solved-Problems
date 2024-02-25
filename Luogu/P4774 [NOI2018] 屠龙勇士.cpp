#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
ll qmul(ll a,ll b,ll p)
{
	ll res=0;
	while(b>0)
	{
		if(b&1) res=(res+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,tmp;
	g=exgcd(b,a%b,x,y);
	tmp=x;
	x=y;
	y=tmp-a/b*y;
	return g;
}
ll linear_equation(ll a,ll b,ll c,ll &x,ll &y)
{
	
	ll g,dx,dy,t;
	g=exgcd(a,b,x,y);
	if(a==0&&b==0)
	{
		if(c) return -1;
		x=y=0;
		return g;
	}
	if(c%g) return -1; //no solution
	dx=b/g;
	x=qmul(x,c/g,dx);
	if(x<0) x+=dx;
	return g;
}
ll exCRT(int n,ll *a,ll *m,ll now_res)
{
	int i;
	ll prep,p,res,g,x,y;
	for(i=1;i<=n;i++) a[i]=(a[i]%m[i]+m[i])%m[i];
	p=m[1];
	res=a[1];
	for(i=2;i<=n;i++)
	{
		/*
		m[i-1]*x-m[i]*y=a[i]-a[i-1]
		m[i-1]=p, a[i-1]=res
		->  p*x-m[i]*y=a[i]-res
		*/
		g=linear_equation(p,m[i],(a[i]-res)%m[i]+m[i],x,y);
	    if(g==-1) return -1;
	    prep=p;
	    p=p/g*m[i];
	    res=(res+qmul(prep,x,p))%p;
	}
	if(res<now_res) res+=(now_res-res+p-1)/p;
    return res;
}
/*
x = a_i (mod m_i)  a:1..n, m:1..n

exCRT return: x = res + k*p, k is interge
*/
ll a[MAX],b[MAX],p[MAX],atk[MAX];
ll new_a[MAX],new_p[MAX];
ll work(int n,ll mx)
{
	int i;
	ll x,y,g;
	for(i=1;i<=n;i++)
	{
		/*
		bi*x = ai mod pi
		bi*x + pi*y = ai
		*/
		g=linear_equation(b[i],p[i],a[i],x,y);
		if(g==-1) return -1;
		new_a[i]=x;
		new_p[i]=p[i]/g;
	}
	return exCRT(n,new_a,new_p,mx);
}
int main()
{
	int t,n,m,i;
	ll x,mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=1;i<=n;i++) scanf("%lld",&p[i]);
		for(i=1;i<=n;i++) scanf("%lld",&atk[i]);
		multiset<ll> s;
		while(m--)
		{
			scanf("%lld",&x);
			s.insert(x);
		}
		mx=0;
		for(i=1;i<=n;i++)
		{
			auto it=s.upper_bound(a[i]);
			if(it!=s.begin()) --it;
			b[i]=*it;
			s.erase(it);
			s.insert(atk[i]);
			mx=max(mx,(a[i]+b[i]-1)/b[i]);
		}
		printf("%lld\n",work(n,mx));
	}
	return 0;
}
