#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX];
ll pre[MAX],suf[MAX];
int main()
{
	int n,i;
	ll sum,ans;
	scanf("%d",&n);
	for(i=1;i<=3*n;i++) scanf("%d",&a[i]);
	priority_queue<int> q;
	sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
		q.push(-a[i]);
		pre[i]=sum;
	}
	for(i=n+1;i<=2*n;i++)
	{
		sum+=a[i];
		q.push(-a[i]);
		sum-=-q.top();
		q.pop();
		pre[i]=sum;
	}
	while(!q.empty()) q.pop();
	sum=0;
	for(i=3*n;i>=2*n+1;i--)
	{
		sum+=a[i];
		q.push(a[i]);
		suf[i]=sum;
	}
	for(i=2*n;i>=n+1;i--)
	{
		sum+=a[i];
		q.push(a[i]);
		sum-=q.top();
		q.pop();
		suf[i]=sum;
	}
	ans=-1e18;
	for(i=n;i<=2*n;i++) ans=max(ans,pre[i]-suf[i+1]);
	printf("%lld\n",ans);
	return 0;
}
