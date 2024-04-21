#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct node
{
	ll v;
	int id;
	friend bool operator < (node a,node b)
	{
		return a.v<b.v;
	}
};
int a[MAX],vis[MAX],l[MAX],r[MAX];
ll val[MAX];
void del(int x)
{
	l[x]=l[l[x]];
	r[x]=r[r[x]];
	r[l[x]]=l[r[x]]=x;
}
int main()
{
	int n,m,i;
	ll ans;
	scanf("%d%d",&n,&m);
	priority_queue<node> q;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l[i]=i-1;
		r[i]=i+1;
		vis[i]=0;
		q.push({a[i],i});
		val[i]=a[i];
	}
	l[1]=n;
	r[n]=1;
	if(m*2>n)
	{
		puts("Error!");
		return 0;
	}
	ans=0;
	while(m--)
	{
		while(vis[q.top().id]) q.pop();
		node t=q.top();
		q.pop();
		ans+=val[t.id];
		val[t.id]=val[l[t.id]]+val[r[t.id]]-val[t.id];
		vis[l[t.id]]=vis[r[t.id]]=1;
		q.push({val[t.id],t.id});
		del(t.id);
	}
	printf("%lld\n",ans);
	return 0;
}
