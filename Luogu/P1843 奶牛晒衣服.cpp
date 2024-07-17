#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int n,a,b,w[MAX];
int ck(ll x)
{
	int i;
	ll res=0;
	for(i=1;i<=n;i++)
	{
		res+=max(0LL,(w[i]-a*x+b-1)/b);
		if(res>x) return 0;
	}
	return 1;
}
int main()
{
	int i;
	ll l,r,mid;
	scanf("%d%d%d",&n,&a,&b);
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	l=1;
	r=5e5;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
