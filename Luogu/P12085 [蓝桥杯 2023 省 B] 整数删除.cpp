#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct node
{
	ll v;int id;
	friend bool operator <(node a,node b)
	{
		if(a.v==b.v) return a.id>b.id;
		return a.v>b.v;
	}
};
int l[MAX],r[MAX];
ll a[MAX];
void del(int x)
{
	l[r[x]]=l[x];
	r[l[x]]=r[x];
}
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	priority_queue<node> q;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		l[i]=i-1;
		r[i]=i+1;
		q.push({a[i],i});
	}
	l[0]=0;
	r[0]=1;
	l[n+1]=n;
	r[n+1]=n+1;
	for(i=1;i<=k;i++)
	{
		node t=q.top();
		q.pop();
		if(t.v!=a[t.id])
		{
			i--;
			continue;
		}
		if(l[t.id]>=1)
		{
			a[l[t.id]]+=a[t.id];
			q.push({a[l[t.id]],l[t.id]});
		}
		if(r[t.id]<=n)
		{
			a[r[t.id]]+=a[t.id];
			q.push({a[r[t.id]],r[t.id]});
		}
		a[t.id]=-1;
		del(t.id);
	}
	vector<ll> res;
	for(i=1;i<=n;i++)
	{
		if(a[i]==-1) continue;
		res.push_back(a[i]);
	}
	assert(res.size()==n-k);
	for(i=0;i<n-k;i++) printf("%lld%c",res[i]," \n"[i+1==n-k]);
	return 0;
}
