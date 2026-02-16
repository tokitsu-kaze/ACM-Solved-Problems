#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{ll s,t,e;}a[MAX];
int main()
{
	int n,i,ans;
	ll now;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].s,&a[i].t);
		a[i].e=a[i].s+a[i].t;
	}
	sort(a+1,a+1+n,[](node x,node y){
		if(x.e==y.e) return x.t<y.t;
		return x.e<y.e;
	});
	priority_queue<ll> q;
	now=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		q.push(a[i].t);
		now+=a[i].t;
		if(now<=a[i].e) ans++;
		else
		{
			now-=q.top();
			q.pop();
		}
	}
	printf("%d\n",ans);
	return 0;
}
