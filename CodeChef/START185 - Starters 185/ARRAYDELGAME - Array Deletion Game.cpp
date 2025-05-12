#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		priority_queue<int> q;
		ans=0;
		for(i=1;i<=2*n;i++)
		{
			scanf("%d",&x);
			if(i&1)
			{
				q.push(-x);
				ans+=x;
			}
			else
			{
				if(x>-q.top())
				{
					ans-=-q.top();
					q.pop();
					ans+=x;
					q.push(-x);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
