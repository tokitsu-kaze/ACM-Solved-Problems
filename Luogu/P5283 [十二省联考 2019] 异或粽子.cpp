#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct Persistent_01Trie
{
	#define type ll
	static const int LOG=33;
	static const int K=LOG+2;
	int root[MAX],tot,nex[MAX*K][2],cnt[MAX*K],pos[MAX*K];
	void init()
	{
		root[0]=0;
		nex[0][0]=nex[0][1]=cnt[0]=tot=0;
	}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void update(type x,int &rt,int pre,int p)
	{
		int id,t,i;
		if(!rt) rt=newnode();
		id=rt;
		for(i=LOG;~i;i--)
		{
			cnt[id]=cnt[pre]+1;
			t=(x>>i)&1;
			nex[id][t^1]=nex[pre][t^1];
			nex[id][t]=newnode();
			id=nex[id][t];
			pre=nex[pre][t];
		}
		cnt[id]=cnt[pre]+1;
		pos[id]=p;
	}
	type query_max(type x,int rt,int pre)
	{
		int id,i;
		type res,t;
		id=rt;
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(cnt[nex[id][t^1]]-cnt[nex[pre][t^1]]>0) t^=1;
			res|=(t<<i);
			id=nex[id][t];
			pre=nex[pre][t];
		}
		return res^x;
	}
	int query_pmax(type x,int rt,int pre)
	{
		int id,t,i;
		id=rt;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(cnt[nex[id][t^1]]-cnt[nex[pre][t^1]]>0) t^=1;
			id=nex[id][t];
			pre=nex[pre][t];
		}
		return pos[id];
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void create_ver(int now_ver,int pre_ver,type x,int p)
	{
		root[now_ver]=0;
		update(x,root[now_ver],root[pre_ver],p);
	}
	type ask_max(int pre_ver,int now_ver,type x)
	{
		assert(pre_ver>0);
		return query_max(x,root[now_ver],root[pre_ver-1]);
	}
	int ask_pmax(int pre_ver,int now_ver,type x)
	{
		assert(pre_ver>0);
		return query_pmax(x,root[now_ver],root[pre_ver-1]);
	}
	#undef type
}tr;
/*
tr.init();
tr.create_ver(now_ver,pre_ver,v);
tr.copy_ver(now_ver,pre_ver);
tr.ask_max(l,r,v);
*/
struct node
{
	int r,x,y;
	ll v;
	friend bool operator <(node a,node b)
	{
		return a.v<b.v;
	}
};
ll a[MAX],bit[MAX];
int main()
{
	int n,k,i,x,y,mid;
	ll ans;
	scanf("%d%d",&n,&k);
	n++;
	bit[1]=0;
	tr.init();
	tr.create_ver(1,0,bit[1],1);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		bit[i]=bit[i-1]^a[i];
		tr.create_ver(i,i-1,bit[i],i);
	}
	priority_queue<node> q;
	for(i=2;i<=n;i++)
	{
		x=1;
		y=i-1;
		q.push({i,x,y,tr.ask_max(x,y,bit[i])});
	}
	ans=0;
	while(k--)
	{
		assert(q.size()>0);
		auto t=q.top();
		q.pop();
		ans+=t.v;
		mid=tr.ask_pmax(t.x,t.y,bit[t.r]);
		if(mid-1>=t.x) q.push({t.r,t.x,mid-1,tr.ask_max(t.x,mid-1,bit[t.r])});
		if(mid+1<=t.y) q.push({t.r,mid+1,t.y,tr.ask_max(mid+1,t.y,bit[t.r])});
	}
	printf("%lld\n",ans);
	return 0;
}
