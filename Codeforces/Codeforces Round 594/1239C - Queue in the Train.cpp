#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll ans[MAX];
int main()
{
	int n,p,i,x;
	ll now;
	scanf("%d%d",&n,&p);
	priority_queue<pair<ll,ll>> pq;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		pq.push({-x,-i});
	}
	queue<ll> q;
	set<ll> s;
	now=0;
	for(i=1;i<=n;i++)
	{
		if(q.empty() && s.empty()) now=-pq.top().first;
		now+=p;
		while(!pq.empty() && -pq.top().first<=now)
		{
			if(q.empty() || -pq.top().second<q.back())
			{
				q.push(-pq.top().second);
			}
			else s.insert(-pq.top().second);
			pq.pop();
		}
		ans[q.front()]=now;
		q.pop();
		while(q.empty() && !s.empty())
		{
			q.push(*s.begin());
			s.erase(s.begin());
		}
	}
	for(i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}
