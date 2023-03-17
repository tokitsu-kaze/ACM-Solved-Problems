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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	ll l,r,mid,sum,tag;
	node(){}
	node(ll a,ll b)
	{
		l=a;
		r=b;
		sum=0;
		tag=0;
		mid=(l+r)>>1;
	}
}tree[4*MAX][15];
ll c[MAX][15];
void change(ll id,ll son)
{
	ll i,j,s[12],tag[12];
	mem(s,0);
	for(i=0;i<=9;i++)
	{
		tag[i]=tree[son][i].tag;
		s[i]=tree[son][i].sum;
	}
	for(i=0;i<=9;i++)
	{
		if(tree[id][i].tag!=i)
		{
			for(j=0;j<=9;j++)
			{
				if(tree[son][j].tag==i) tag[j]=tree[id][i].tag;
			}
			s[tree[id][i].tag]+=tree[son][i].sum;
			s[i]-=tree[son][i].sum;
		}
	}
	for(i=0;i<=9;i++)
	{
		tree[son][i].tag=tag[i];
		tree[son][i].sum=s[i];
	}
}
void pushdown(ll id)
{
	ll i;
	change(id,id<<1);
	change(id,id<<1|1);
	for(i=0;i<=9;i++)
	{
		tree[id][i].tag=i;
	}
}
void pushup(ll id)
{
	ll i;
	for(i=0;i<=9;i++)
	{
		tree[id][i].sum=tree[id<<1][i].sum+tree[id<<1|1][i].sum;
	}
}
void build(ll l,ll r,ll id)
{
	ll mid,i;
	for(i=0;i<=9;i++)
	{
		tree[id][i]=node(l,r);
		tree[id][i].tag=i;
		if(l==r) tree[id][i].sum=c[l][i];
	}
	if(l==r) return;
	mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	pushup(id);
}
void update(ll l,ll r,ll id,ll x,ll y)
{
	ll mid,i,s=0;
	if(l<=tree[id][x].l&&r>=tree[id][x].r)
	{
		for(i=0;i<=9;i++)
		{
			if(tree[id][i].tag==x)
			{
				tree[id][i].tag=y;
			}
		}
		tree[id][y].sum+=tree[id][x].sum;
		tree[id][x].sum=0;
		return;
	}
	pushdown(id);
	mid=tree[id][x].mid;
	if(r<=mid) update(l,r,id<<1,x,y);
	else if(l>=mid+1) update(l,r,id<<1|1,x,y);
	else
	{
		update(l,mid,id<<1,x,y);
		update(mid+1,r,id<<1|1,x,y);
	}
	pushup(id);
}
ll query(ll l,ll r,ll id,ll x)
{
	ll mid,s=0,i;
	if(l==tree[id][x].l&&r==tree[id][x].r)
	{
		for(i=0;i<=9;i++)
		{
			s+=tree[id][i].sum*i;
		}
		return s;
	}
	pushdown(id);
	mid=tree[id][x].mid;
	if(r<=mid) return query(l,r,id<<1,x);
	else if(l>=mid+1) return query(l,r,id<<1|1,x);
	else return query(l,mid,id<<1,x)+query(mid+1,r,id<<1|1,x);
	pushup(id);
}
int main()
{
	ll i,n,q,x,op,l,r,a,b,temp;
	while(~scanf("%lld%lld",&n,&q))
	{
		mem(c,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			temp=1;
			while(x)
			{
				ll now=x%10;
				c[i][now]+=temp;
				x/=10;
				temp*=10;
			}
		}
		build(1,n,1);
		while(q--)
		{
			scanf("%lld%lld%lld",&op,&l,&r);
			if(op==1)
			{
				scanf("%lld%lld",&a,&b);
				if(a!=b) update(l,r,1,a,b);
			}
			else
			{
				ll ans=0;
				ans=query(l,r,1,1);
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
/*
3 100
10000 10000 10000
1 1 2 0 2
2 1 3
1 1 3 2 0
2 2 3
2 1 3
*/