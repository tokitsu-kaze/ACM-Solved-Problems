#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
int main()
{
	int n,k,i,ans;
	ll x,now;
	scanf("%d%d%lld",&n,&k,&x);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=0;
	now=0;
	for(i=k;i;i--)
	{
		now+=a[i];
		if(now>=x)
		{
			ans=i-1;
			break;
		}
	}
	if(now<x) puts("-1");
	else printf("%d\n",n-ans);
	return 0;
}
/*
考虑不喝最多的
如果前i个不喝，那么后面最小的k-i+1个是酒 
*/
