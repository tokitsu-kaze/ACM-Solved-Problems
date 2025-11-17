#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int n,k,a[MAX],pre[MAX],suf[MAX];
int ck(ll x)
{
	int i;
	ll sum;
	priority_queue<int> q;
	sum=0;
	for(i=1;i<=n;i++)
	{
		q.push(a[i]);
		sum+=a[i];
		while(sum>x)
		{
			sum-=q.top();
			q.pop();
		}
		pre[i]=q.size();
	}
	sum=0;
	while(!q.empty()) q.pop();
	for(i=n;i;i--)
	{
		q.push(a[i]);
		sum+=a[i];
		while(sum>x)
		{
			sum-=q.top();
			q.pop();
		}
		suf[i]=q.size();
	}
	pre[0]=suf[n+1]=0;
	for(i=0;i<=n;i++)
	{
		if(pre[i]+suf[i+1]>=k) return 1;
	}
	return 0;
}
int main()
{
	int T,i;
	ll l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=0;
		r=3e14;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
