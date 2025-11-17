#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
ll fac[MAX];
int pos[MAX];
int main()
{
	int T,n,i,l,r,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			pos[x]=i;
		}
		ans=1;
		l=r=pos[0];
		for(i=1;i<n;i++)
		{
			if(pos[i]>=l && pos[i]<=r) ans=ans*((r-l+1)-i)%mod;
			l=min(l,pos[i]);
			r=max(r,pos[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
