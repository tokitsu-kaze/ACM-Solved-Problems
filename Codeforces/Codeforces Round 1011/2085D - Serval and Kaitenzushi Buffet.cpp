#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,k,i,now;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		priority_queue<int> q;
		ans=0;
		now=0;
		for(i=n;i;i--)
		{
			if(now==k)
			{
				q.push(-a[i]);
				ans+=a[i];
				now=0;
			}
			else
			{
				if(!q.empty() && -q.top()<a[i])
				{
					ans-=-q.top();
					q.pop();
					q.push(-a[i]);
					ans+=a[i];
				}
				now++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

