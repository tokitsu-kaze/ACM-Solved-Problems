#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=998244353;
int p[MAX],q[MAX];
ll pw2[MAX];
int main()
{
	int T,n,i,mxp,posp,mxq,posq;
	ll ans;
	pw2[0]=1;
	for(i=1;i<MAX;i++) pw2[i]=pw2[i-1]*2%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&p[i]);
		for(i=0;i<n;i++) scanf("%d",&q[i]);
		mxp=mxq=-1;
		for(i=0;i<n;i++)
		{
			if(p[i]>mxp)
			{
				mxp=p[i];
				posp=i;
			}
			if(q[i]>mxq)
			{
				mxq=q[i];
				posq=i;
			}
			if(mxp>mxq) ans=pw2[mxp]+pw2[q[i-posp]];
			else if(mxp<mxq) ans=pw2[mxq]+pw2[p[i-posq]];
			else
			{
				if(q[i-posp]>p[i-posq]) ans=pw2[mxp]+pw2[q[i-posp]];
				else ans=pw2[mxq]+pw2[p[i-posq]];
			}
			printf("%lld%c",ans%mod," \n"[i+1==n]);
		}
	}
	return 0;
}
