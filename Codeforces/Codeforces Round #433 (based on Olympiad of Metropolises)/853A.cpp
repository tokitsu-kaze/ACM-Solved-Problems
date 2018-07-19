#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
struct node
{
	ll id,v;
	bool operator <(const node& b) const
	{
		return v<b.v;
	}
}a[MAX];
ll pos[MAX];
int main()
{
	ll n,k,i,ans;
	node t;
	while(~scanf("%lld%lld",&n,&k))
	{
		priority_queue<node> q;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&t.v);
			t.id=i;
			a[i]=t;
			if(i<=k+1) q.push(t);
		}
		ans=0;
		for(i=k+1;i<=k+n;i++)
		{
			t=q.top();
			q.pop();
			ans+=(i-t.id)*t.v;
			pos[t.id]=i;
			if(i+1<=n) q.push(a[i+1]);
		}
		printf("%lld\n",ans);
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%lld\n",pos[i]);
			else printf("%lld ",pos[i]);
		}
	}
	return 0;
}