#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
struct node
{
	ll a,b;
	node(){}
	node(ll l,ll r)
	{
		a=l;
		b=r;
	}
	friend bool operator <(node a,node b)
	{
		return a.a<b.a;
	}
};
map<node,ll> mp;
ll findpos(ll a,ll b)
{
	map<ll,ll> flag;
	flag.clear();
	while(a)
	{
		flag[a]=1;
		a/=2;
	}
	while(b)
	{
		if(flag[b])
		{
			return b;
		}
		b/=2;
	}
}
void color(ll a,ll b,ll v)
{
	ll pos=findpos(a,b);
	node temp;
	while(a>pos)
	{
		temp=node(a,a/2);
		mp[temp]+=v;
		a/=2;
	}
	while(b>pos)
	{
		temp=node(b,b/2);
		mp[temp]+=v;
		b/=2;
	}
}
void query(ll a,ll b)
{
	node temp;
	ll pos=findpos(a,b),ans=0;
	while(a>pos)
	{
		temp=node(a,a/2);
//		cout<<mp[temp]<<endl;
		ans+=mp[temp];
		a/=2;
	}
	while(b>pos)
	{
		temp=node(b,b/2);
//		cout<<mp[temp]<<endl;
		ans+=mp[temp];
		b/=2;
	}
	printf("%lld\n",ans);
}
int main()
{
	ll n,op,a,b,v,ans;
	while(~scanf("%lld",&n))
	{
		mp.clear();
		while(n--)
		{
			scanf("%lld%lld%lld",&op,&a,&b);
			if(op==1)
			{
				scanf("%lld",&v);
				color(a,b,v);
			}
			else if(op==2)
			{
				query(a,b);
			}
		}
	}
	return 0;
}