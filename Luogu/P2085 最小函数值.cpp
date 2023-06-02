#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
struct node
{
	int id;
	ll x,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
ll a[MAX],b[MAX],c[MAX];
ll f(int id,ll x){return a[id]*x*x+b[id]*x+c[id];}
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	priority_queue<node> q;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		q.push({i,1,f(i,1)});
	}
	vector<ll> res;
	while(m--)
	{
		node t=q.top();
		q.pop();
		res.push_back(t.v);
		q.push({t.id,t.x+1,f(t.id,t.x+1)});
	}
	for(i=0;i<res.size();i++) printf("%lld%c",res[i]," \n"[i==res.size()-1]);
	return 0;
}
