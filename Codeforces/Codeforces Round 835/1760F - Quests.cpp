#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],n,d;
ll c;
int ck(int x)
{
	int i,j;
	ll res=0;
	j=0;
	while(j<d)
	{
		for(i=1;i<=min(n,x+1);i++)
		{
			res+=a[i];
			j++;
			if(res>=c) return 1;
			if(j==d) break;
		}
		if(n<x+1) j+=x+1-n;
	}
	return res>=c;
}
int main()
{
	int t,i,l,r,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld%d",&n,&c,&d);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		l=0;
		r=d+1;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		if(!ck(l)) puts("Impossible");
		else if(l==d+1) puts("Infinity");
		else printf("%d\n",l);
	}
	return 0;
}
