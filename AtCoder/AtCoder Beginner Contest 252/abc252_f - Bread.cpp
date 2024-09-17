#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	ll L,ans,a,b,sum;
	scanf("%d%lld",&n,&L);
	priority_queue<ll> q;
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q.push(-x);
		sum+=x;
	}
	if(sum!=L) q.push(-(L-sum));
	ans=0;
	while(q.size()>1)
	{
		a=-q.top();
		q.pop();
		b=-q.top();
		q.pop();
		ans+=a+b;
		q.push(-(a+b));
	}
	printf("%lld\n",ans);
	return 0;
}
