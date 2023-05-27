#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,i,x;
	ll ans,now;
	scanf("%d",&n);
	priority_queue<int> q;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q.push(-x);
	}
	ans=0;
	while(q.size()>1)
	{
		now=-q.top();
		q.pop();
		now+=-q.top();
		q.pop();
		ans+=now;
		q.push(-now);
	}
	printf("%lld\n",ans);
	return 0;
}
