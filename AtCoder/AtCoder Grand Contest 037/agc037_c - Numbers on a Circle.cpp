#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int v,x;
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
};
int a[MAX],b[MAX];
int main()
{
	int n,i,cnt,tmp,x;
	ll ans;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	priority_queue<node> q;
	for(i=0;i<n;i++)
	{
		if(a[i]<b[i]) q.push({b[i],i});
	}
	ans=0;
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		x=t.x;
		tmp=b[(x-1+n)%n]+b[(x+1)%n];
		cnt=(b[x]-a[x])/tmp;
		ans+=cnt;
		b[x]-=tmp*cnt;
		if(b[x]!=a[x] && cnt>0) q.push({b[x],x});
	}
	for(i=0;i<n;i++)
	{
		if(b[i]!=a[i]) ans=-1;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
显然能够从最大的开始减，用堆模拟即可。
*/
