#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll a[MAX],tmp[MAX];
int n;
int ck()
{
	int i;
	ll d;
	for(i=1;i<=n;i++) a[i]=tmp[i];
	for(i=2;i<=n;i++)
	{
		if(a[i]<a[i-1]) return 0;
	}
	d=a[2]-a[1];
	for(i=2;i<=n;i++)
	{
		if(a[i-1]+d!=a[i]) return 0;
	}
	for(i=1;i<=n;i++) a[i]-=d*i;
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1]) return 0;
	}
	if(a[1]<0 || a[1]%(n+1)) return 0;
	
	return 1;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&tmp[i]);
		if(ck()) puts("YES");
		else
		{
			reverse(tmp+1,tmp+1+n);
			if(ck()) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
