#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
int main()
{
	int n,x,i;
	ll ans;
	scanf("%d",&n);
	ans=0;
	priority_queue<int> q;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(!q.empty()&&-q.top()<x)
		{
			ans+=x-(-q.top());
			q.pop();
			q.push(-x);
		}
		q.push(-x);
	}
	printf("%lld\n",ans);
	return 0;
}
