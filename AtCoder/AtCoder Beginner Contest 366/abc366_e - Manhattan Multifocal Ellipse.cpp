#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int x[MAX],y[MAX];
int main()
{
	int n,i,cnt,d;
	ll sum,now,ans,tmp;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	sum=0;
	for(i=1;i<=n;i++) sum+=y[i];
	vector<ll> ry;
	cnt=now=0;
	for(i=-2e6;i<=2e6;i++)
	{
		while(cnt<n && y[cnt+1]<=i)
		{
			cnt++;
			now+=y[cnt];
		}
		tmp=(1LL*i*cnt-now)+(sum-now-1LL*i*(n-cnt));
		ry.push_back(tmp);
	}
	sort(ry.begin(),ry.end());
	sum=0;
	for(i=1;i<=n;i++) sum+=x[i];
	ans=0;
	cnt=now=0;
	for(i=-2e6;i<=2e6;i++)
	{
		while(cnt<n && x[cnt+1]<=i)
		{
			cnt++;
			now+=x[cnt];
		}
		tmp=(1LL*i*cnt-now)+(sum-now-1LL*i*(n-cnt));
		ans+=upper_bound(ry.begin(),ry.end(),d-tmp)-ry.begin();
	}
	printf("%lld\n",ans);
	return 0;
}
/*
sum{|x-xi|}+sum{|y-yi|}<=d
sum{|x-xi|}<=d-sum{|y-yi|}
(x*cnt-sumx)+(tot-sumx-x*(n-cnt+1))
*/
