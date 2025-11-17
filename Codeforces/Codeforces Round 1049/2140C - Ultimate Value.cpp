#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n;
ll cal()
{
	int i;
	ll res=0;
	for(i=1;i<=n;i++)
	{
		if(i&1) res+=a[i];
		else res-=a[i];
	}
	return res;
}
int main()
{
	int T,i,j,k;
	ll ans,now,premx,premn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=now=cal();
		premx=-1e18;
		for(i=2;i<=n;i++)
		{
			if(i%2==0) premx=max(premx,2LL*a[i]-i);
			else ans=max(ans,now+premx-(2LL*a[i]-i));
		}
		premn=1e18;
		for(i=1;i<=n;i++)
		{
			if(i%2==0) ans=max(ans,now+(2LL*a[i]+i)-premn);
			else premn=min(premn,2LL*a[i]+i);
		}
		if(n&1)
		{
			swap(a[1],a[n]);
			ans=max(ans,cal()+n-1);
			swap(a[1],a[n]);
		}
		else
		{
			swap(a[1],a[n-1]);
			ans=max(ans,cal()+n-1-1);
			swap(a[1],a[n-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
a1-a2 -> (a2+2)-(a1+1)
(a2+2)-(a1+1)-(a1-a2)
a2-a1+2+1-a1+a2
(2a2+2)-(2a1+1)

a3-a2 -> (a2-2)-(a3-3)
a2-2-a3+3-(a3-a2)
(2a2-2)-(2a3-3)
*/
