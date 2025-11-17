#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],b[MAX],c[MAX];
ll res[MAX];
int main()
{
	int n,k,i;
	ll now,tm;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	priority_queue<pair<ll,int>> q;
	set<ll> t;
	t.insert(0);
	for(i=1;i<=n;i++) t.insert(a[i]);
	i=1;
	now=0;
	while(i<=n)
	{
		tm=*t.begin();
		t.erase(t.begin());
		while(!q.empty())
		{
			if(-q.top().first<=tm)
			{
				now-=q.top().second;
				q.pop();
			}
			else break;
		}
		while(i<=n)
		{
			if(a[i]>tm) break;
			if(c[i]+now<=k)
			{
				res[i]=tm;
				t.insert(tm+b[i]);
				q.push({-(tm+b[i]),c[i]});
				now+=c[i];
				i++;
			}
			else break;
		}
	}
	for(i=1;i<=n;i++) printf("%lld\n",res[i]);
	return 0;
}
