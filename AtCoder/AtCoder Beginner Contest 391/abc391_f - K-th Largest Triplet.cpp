#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=2e5+10;
struct node
{
	ll v;
	int i,j,k;
	friend bool operator <(node x,node y)
	{
		return x.v<y.v;
	}
};
ll a[MAX],b[MAX],c[MAX];
int main()
{
	int n,k,i;
	ll ans;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&b[i]);
	for(i=1;i<=n;i++) scanf("%lld",&c[i]);
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	sort(b+1,b+1+n);
	reverse(b+1,b+1+n);
	sort(c+1,c+1+n);
	reverse(c+1,c+1+n);
	priority_queue<node> q;
	q.push({a[1]*b[1]+b[1]*c[1]+c[1]*a[1],1,1,1});
	map<pair<pair<int,int>,int>,int> mp;
	while(k--)
	{
		node t=q.top();
		q.pop();
		ans=t.v;
		if(t.i+1<=n && !mp.count({{t.i+1,t.j},t.k}))
		{
			q.push({a[t.i+1]*b[t.j]+b[t.j]*c[t.k]+c[t.k]*a[t.i+1],
					t.i+1,
					t.j,
					t.k});
			mp[{{t.i+1,t.j},t.k}]=1;
		}
		if(t.j+1<=n && !mp.count({{t.i,t.j+1},t.k}))
		{
			q.push({a[t.i]*b[t.j+1]+b[t.j+1]*c[t.k]+c[t.k]*a[t.i],
					t.i,
					t.j+1,
					t.k});
			mp[{{t.i,t.j+1},t.k}]=1;
		}
		if(t.k+1<=n && !mp.count({{t.i,t.j},t.k+1}))
		{
			q.push({a[t.i]*b[t.j]+b[t.j]*c[t.k+1]+c[t.k+1]*a[t.i],
					t.i,
					t.j,
					t.k+1});
			mp[{{t.i,t.j},t.k+1}]=1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
