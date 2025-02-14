#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct Trie
{
	#define type ll
	static const int LOG=33;
	static const int K=LOG+2;
	int rt,root[MAX],tot,ch[MAX*K][2],cnt[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=cnt[0]=0;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			cnt[id]++;
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		cnt[id]++;
	}
	type count_y(type x,type limt) // count y: x xor y <= limt
	{
		int id,i;
		type res,t;
		if(!root[rt]) return 0;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if((limt>>i)&1)
			{
				res+=cnt[ch[id][t]];
				id=ch[id][t^1];
			}
			else id=ch[id][t];
		}
		res+=cnt[id];
		return res;
	}
	#undef type
}tr;
int a[MAX],n;
ll k;
int ck(ll x)
{
	int i;
	ll res;
	tr.init();
	res=0;
	for(i=1;i<=n;i++)
	{
		res+=tr.count_y(a[i],x);
		tr.insert(a[i]);
	}
	return res>=k;
}
int main()
{
	int i;
	ll l,r,mid;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	l=0;
	r=2e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",l);
	return 0;
}
