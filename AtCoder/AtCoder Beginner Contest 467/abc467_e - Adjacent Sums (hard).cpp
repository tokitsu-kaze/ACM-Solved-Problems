#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],c[MAX],d[MAX];
void bf()
{
	int n,m,i;
	ll ans,now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++) scanf("%d",&b[i]);
	c[1]=0;
	for(i=2;i<=n;i++) c[i]=(b[i-1]-c[i-1]+m)%m;
	vector<int> res;
	res.push_back(0);
	for(i=1;i<=n;i++)
	{
		d[i]=(c[i]-a[i]+m)%m;
		if(i&1) res.push_back(m-d[i]);
		else res.push_back(d[i]);
	}
	ans=LLINF;
	for(auto &x:res)
	{
		now=0;
		for(i=1;i<=n;i++)
		{
			if(i&1) now+=(d[i]+x)%m;
			else now+=(d[i]-x+m)%m;
		}
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
}
void solve()
{
	int n,m,i,po,pe,cnto,cnte;
	ll ans,sumd,now;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<n;i++) scanf("%d",&b[i]);
	c[1]=0;
	for(i=2;i<=n;i++) c[i]=(b[i-1]-c[i-1]+m)%m;
	vector<int> res,o,e;
	res.push_back(0);
	cnto=cnte=sumd=0;
	for(i=1;i<=n;i++)
	{
		d[i]=(c[i]-a[i]+m)%m;
		sumd+=d[i];
		if(i&1)
		{
			res.push_back(m-d[i]);
			o.push_back(d[i]);
			cnto++;
		}
		else
		{
			res.push_back(d[i]);
			e.push_back(d[i]);
			cnte++;
		}
	}
	ans=LLINF;
	sort(o.begin(),o.end());
	sort(e.begin(),e.end());
	for(auto &x:res)
	{
		now=sumd;
		po=lower_bound(o.begin(),o.end(),m-x)-o.begin();
		now+=1LL*cnto*x-1LL*(cnto-po)*m;
		pe=lower_bound(e.begin(),e.end(),x)-e.begin()-1;
		now+=-1LL*cnte*x+1LL*(pe+1)*m;
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
}
int main()
{
//	bf();
	solve();
	return 0;
}
/*
a1+a2=b1
a2+a3=b2
确定a1的值后，后面的都是固定的。

移项后：
a1=x
a2=b1-a1=b1-x
a3=b2-b1+x

所以 cost 为
cost1=x-a1
cost2=b1-x-a2
cost3=b2-b1+x-a3

分别计算
x=0
x=a1
x=b1-a2
x=-(b2-b1-a3)
的答案。
*/
