#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],n;
ll cal()
{
	int i;
	ll res,cnt;
	res=cnt=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]) cnt++;
		else res+=cnt;
	}
	return res;
}
int main()
{
	int t,i,pos;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=cal();
		pos=-1;
		for(i=1;i<=n;i++)
		{
			if(!a[i])
			{
				pos=i;
				break;
			}
		}
		if(pos!=-1)
		{
			a[pos]^=1;
			ans=max(cal(),ans);
			a[pos]^=1;
		}
		pos=-1;
		for(i=n;i;i--)
		{
			if(a[i])
			{
				pos=i;
				break;
			}
		}
		if(pos!=-1)
		{
			a[pos]^=1;
			ans=max(cal(),ans);
			a[pos]^=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
